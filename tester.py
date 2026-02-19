import subprocess
import random
import itertools
import sys

EXEC = "./push_swap"

# Colors for terminal output
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
BLUE = "\033[94m"
RESET = "\033[0m"

def run_push_swap(args):
    """Runs the push_swap executable and returns the number of moves and any errors."""
    str_args = [str(arg) for arg in args]
    try:
        res = subprocess.run([EXEC] + str_args, capture_output=True, text=True)
        # Count the number of moves (ignoring empty lines)
        out_lines = [line for line in res.stdout.split('\n') if line]
        return len(out_lines), res.stderr.strip()
    except FileNotFoundError:
        print(f"{RED}Error: Executable {EXEC} not found. Did you run 'make'?{RESET}")
        sys.exit(1)

def test_errors():
    print(f"\n{BLUE}=== 1. TESTING ERRORS ==={RESET}")
    tests = [
        (["1", "2", "2", "3"], "Duplicates"),
        (["1", "a", "3"], "Letters/Invalid characters"),
        (["1", "2147483648", "3"], "Greater than INT_MAX"),
        (["1", "-2147483649", "3"], "Less than INT_MIN"),
        ([""], "Empty string")
    ]
    for args, name in tests:
        _, err = run_push_swap(args)
        if err == "Error":
            print(f"{GREEN}[OK]{RESET} {name} (Properly output 'Error')")
        else:
            print(f"{RED}[FAIL]{RESET} {name} - Expected 'Error' on stderr, but got: '{err}'")

def test_already_sorted():
    print(f"\n{BLUE}=== 2. TESTING SORTED LISTS ==={RESET}")
    moves, err = run_push_swap([1, 2, 3, 4, 5])
    if moves == 0 and not err:
        print(f"{GREEN}[OK]{RESET} Sorted list of 5 takes 0 moves")
    else:
        print(f"{RED}[FAIL]{RESET} Sorted list took {moves} moves. Expected: 0")

def test_permutations(size, max_allowed):
    print(f"\n{BLUE}=== 3. ALL COMBINATIONS OF {size} NUMBERS ==={RESET}")
    base = list(range(1, size + 1))
    perms = list(itertools.permutations(base))
    
    max_found = 0
    fails = 0
    
    for p in perms:
        moves, _ = run_push_swap(p)
        max_found = max(max_found, moves)
        if moves > max_allowed:
            fails += 1
            print(f"{RED}[FAIL]{RESET} Sequence {p} took {moves} moves (Max allowed: {max_allowed})")
            
    if fails == 0:
        print(f"{GREEN}[OK]{RESET} All {len(perms)} combinations passed! Max moves used: {max_found}/{max_allowed}")

def test_random(size, iterations, max_allowed):
    print(f"\n{BLUE}=== 4. TESTING RANDOM {size} NUMBERS ({iterations} rounds) ==={RESET}")
    total_moves = 0
    max_found = 0
    fails = 0
    
    for i in range(iterations):
        # Generate random unique numbers
        nums = random.sample(range(-50000, 50000), size)
        moves, _ = run_push_swap(nums)
        
        total_moves += moves
        max_found = max(max_found, moves)
        
        if moves > max_allowed:
             fails += 1
             print(f"{RED}[WARNING]{RESET} Round {i+1} took {moves} moves (Allowed: {max_allowed})")
             
    avg = total_moves // iterations
    print(f"-> Average moves: {YELLOW}{avg}{RESET}")
    print(f"-> Worst case (Max moves): {YELLOW}{max_found}{RESET}")
    
    if fails == 0:
        print(f"{GREEN}[OK]{RESET} Passed all random tests within the limit!")
    else:
         print(f"{RED}[FAIL]{RESET} {fails} rounds exceeded the maximum allowed moves.")

if __name__ == "__main__":
    # 1. Error testing
    test_errors()
    
    # 2. Identity testing
    test_already_sorted()

    # 3. Small combinations
    # Tests all 6 possible ways to mix 3 numbers (Allowed: max 2 moves, though 3 is standard)
    test_permutations(3, 3) 
    
    # Tests all 120 possible ways to mix 5 numbers (Allowed: max 12 moves)
    # Note: If you don't have a dedicated sort5 function yet, this might use big_sort and fail the 12-move limit.
    test_permutations(5, 12)
    
    # 4. Big Random testing
    # Runs 50 tests of 100 numbers (Aiming for less than 700 for full points)
    test_random(100, 50, 700)
    
    # Runs 50 tests of 500 numbers (Aiming for less than 5500 for full points)
    test_random(500, 50, 5500)
    
    print(f"\n{GREEN}=== TEST SUITE COMPLETE ==={RESET}\n")