import subprocess
import random
import multiprocessing as mp
from multiprocessing import Pool
import time
import os

# ===== CONFIG =====
SIZE = 500
TESTS = 10000
LIMIT = 5500
TIMEOUT = 5
WORKERS = mp.cpu_count()

# ===== INPUT GENERATION STRATEGIES =====
def generate_random(size):
    return random.sample(range(1, size + 1), size)

def generate_reverse(size):
    return list(range(size, 0, -1))

def generate_almost_sorted(size):
    nums = list(range(1, size + 1))
    for _ in range(size // 10):
        i, j = random.sample(range(size), 2)
        nums[i], nums[j] = nums[j], nums[i]
    return nums

def generate_median_at_end(size):
    nums = list(range(1, size + 1))
    mid = size // 2
    nums[0], nums[mid] = nums[mid], nums[0]
    return nums

def generate_rotated(size):
    nums = list(range(1, size + 1))
    rotation = random.randint(1, size - 1)
    return nums[rotation:] + nums[:rotation]

def generate_sawtooth(size):
    nums = []
    chunk_size = size // 10
    for i in range(10):
        chunk = list(range(i * chunk_size + 1, (i + 1) * chunk_size + 1))
        if i % 2:
            chunk.reverse()
        nums.extend(chunk)
    nums.extend(range(len(nums) + 1, size + 1))
    return nums

def generate_interleaved(size):
    first = list(range(1, size // 2 + 1))
    second = list(range(size // 2 + 1, size + 1))
    nums = []
    for i in range(len(first)):
        nums.append(first[i])
        if i < len(second):
            nums.append(second[i])
    return nums

def generate_v_shape(size):
    mid = size // 2
    nums = list(range(size, mid, -1)) + list(range(1, mid + 1))
    return nums

GENERATORS = [
    (generate_random, 0.40),
    (generate_reverse, 0.15),
    (generate_almost_sorted, 0.10),
    (generate_median_at_end, 0.10),
    (generate_rotated, 0.10),
    (generate_sawtooth, 0.05),
    (generate_interleaved, 0.05),
    (generate_v_shape, 0.05),
]

def get_random_generator():
    r = random.random()
    cumulative = 0
    for gen, prob in GENERATORS:
        cumulative += prob
        if r < cumulative:
            return gen
    return GENERATORS[0][0]

# ===== TEST WORKER =====
def test_single_case(args):
    test_id, nums, size = args
    args_list = list(map(str, nums))
    
    try:
        # Run push_swap
        result = subprocess.run(
            ["./push_swap"] + args_list,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=TIMEOUT
        )
        
        instructions = result.stdout.strip()
        ops = len(instructions.splitlines()) if instructions else 0
        
        # Check if sorted correctly
        is_sorted = True  # Default to true
        
        if os.path.exists("./checker_Mac"):
            try:
                # The key fix: ensure newline at end if instructions exist
                checker_input = instructions + "\n" if instructions else ""
                
                checker = subprocess.run(
                    ["./checker_Mac"] + args_list,
                    input=checker_input,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    timeout=TIMEOUT
                )
                
                output = checker.stdout.strip()
                is_sorted = (output == "OK")
                
                # Debug: uncomment to see what checker returns
                # if output != "OK":
                #     print(f"\nChecker output: '{output}' for test {test_id}")
                
            except Exception as e:
                # If checker fails, assume not sorted
                is_sorted = False
        
        return {
            'test_id': test_id,
            'ops': ops,
            'nums': nums,
            'sorted': is_sorted,
            'timeout': False
        }
        
    except subprocess.TimeoutExpired:
        return {
            'test_id': test_id,
            'ops': 0,
            'nums': nums,
            'sorted': False,
            'timeout': True
        }

# ===== MAIN =====
def main():
    # Check if executables exist
    if not os.path.exists("./push_swap"):
        print("❌ Error: ./push_swap not found")
        return
    
    if not os.path.exists("./checker_Mac"):
        print("⚠️  Warning: ./checker_Mac not found - skipping verification\n")
    
    # Stats
    worst_ops = 0
    worst_input = []
    completed = 0
    timeouts = 0
    incorrect = 0
    
    # Generate test cases
    test_cases = []
    for i in range(TESTS):
        generator = get_random_generator()
        nums = generator(SIZE)
        test_cases.append((i, nums, SIZE))
    
    # Run tests in parallel
    with Pool(processes=WORKERS) as pool:
        for result in pool.imap_unordered(test_single_case, test_cases):
            completed += 1
            
            if result['timeout']:
                print(f"\n⏱ Timeout on try {result['test_id'] + 1}")
                timeouts += 1
                continue
            
            if not result['sorted']:
                incorrect += 1
                print(f"\n❌ Incorrect sort on try {result['test_id'] + 1} ({result['ops']} ops)")
                # Save the bad case for debugging
                with open("bad_case.txt", 'w') as f:
                    f.write(" ".join(map(str, result['nums'])))
                continue
            
            ops = result['ops']
            
            # Check for new worst
            if ops > worst_ops:
                worst_ops = ops
                worst_input = result['nums']
                print(f"🔥 New worst: {worst_ops} ops (try {result['test_id'] + 1})")
            
            # Check limit
            if ops > LIMIT:
                print("\n❌ LIMIT BROKEN!")
                print("Operations:", ops)
                print("Input:")
                print(" ".join(map(str, result['nums'])))
                break
            
            # Progress
            print(f"Try {completed}/{TESTS}", end="\r")
    
    # Final results
    print("\n\n✅ Testing finished")
    if incorrect > 0:
        print(f"⚠️  Incorrect sorts: {incorrect}")
    print("Worst ops found:", worst_ops)
    print("Worst input:")
    print(" ".join(map(str, worst_input)))
    
    # Save for easy testing
    with open("worst_input.txt", 'w') as f:
        f.write(" ".join(map(str, worst_input)))

if __name__ == "__main__":
    main()