import subprocess
import random
import itertools
import sys
import os

# --- CONFIGURATION ---
PUSH_SWAP = "./push_swap"
CHECKER = "./checker_linux"  
USE_VALGRIND = False          # <-- TURNED OFF TO FIX YOUR UBUNTU CRASH

# --- COLORS ---
GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
CYAN = "\033[1;36m"
RESET = "\033[0m"

def check_files():
    if not os.path.isfile(PUSH_SWAP):
        print(f"{RED}Error: {PUSH_SWAP} not found! Run 'make' first.{RESET}")
        sys.exit(1)
    if not os.path.isfile(CHECKER):
        print(f"{YELLOW}Warning: {CHECKER} not found! Verification will be skipped.{RESET}")
        return False
    return True

def run_test(args):
    """Runs push_swap and passes output to checker."""
    str_args = [str(arg) for arg in args]
    
    # 1. Run Push_Swap
    try:
        ps_process = subprocess.run([PUSH_SWAP] + str_args, capture_output=True, text=True)
        ps_out = ps_process.stdout
        ps_err = ps_process.stderr.strip()
        moves = len([line for line in ps_out.split('\n') if line])
    except Exception as e:
        return -1, str(e), "CRASH"

    # 2. Run Checker (if output isn't an error)
    checker_res = "N/A"
    if ps_err != "Error" and os.path.isfile(CHECKER):
        chk_process = subprocess.run([CHECKER] + str_args, input=ps_out, capture_output=True, text=True)
        checker_res = chk_process.stdout.strip()
        if not checker_res and chk_process.stderr.strip() == "Error":
            checker_res = "Error"

    return moves, ps_err, checker_res

def print_result(name, condition, extra_info=""):
    if condition:
        print(f"  {GREEN}[OK]{RESET} {name} {extra_info}")
    else:
        print(f"  {RED}[KO]{RESET} {name} {extra_info}")
        
def test_errors():
    print(f"\n{BLUE}=== 1. ERROR MANAGEMENT ==={RESET}")
    tests = [
        (["1", "2", "2", "3"], "Duplicates"),
        (["1", "a", "3"], "Letters"),
        (["1", "2147483648", "3"], "INT_MAX Overflow"),
        (["1", "-2147483649", "3"], "INT_MIN Underflow"),
        ([""], "Empty String"),
        (["    "], "Only Spaces"),
        (["1", "", "2"], "Empty String in middle"),
        (["1 2 3", "4 a 5"], "Invalid string inside quotes")
    ]
    for args, name in tests:
        _, err, _ = run_test(args)
        print_result(name, err == "Error")

def test_sorted():
    print(f"\n{BLUE}=== 2. ALREADY SORTED ALGORITHMS ==={RESET}")
    moves, err, chk = run_test(["1", "2", "3", "4", "5"])
    print_result("Sorted 5 elements", moves == 0 and chk != "KO", f"({moves} moves)")

def test_permutations(size, max_moves):
    print(f"\n{BLUE}=== 3. ALL PERMUTATIONS (Size {size}) ==={RESET}")
    perms = list(itertools.permutations(range(1, size + 1)))
    fails, chk_fails, max_found = 0, 0, 0
    
    for p in perms:
        moves, _, chk = run_test(p)
        max_found = max(max_found, moves)
        if moves > max_moves: fails += 1
        if chk == "KO": chk_fails += 1

    print(f"  Total Permutations Tested: {len(perms)}")
    print(f"  Maximum Moves Used: {CYAN}{max_found} / {max_moves}{RESET}")
    print_result("Moves Limit", fails == 0, f"({fails} failed)")
    print_result("Checker OK", chk_fails == 0, f"({chk_fails} KO'd)")

def test_stress(size, iterations, target_5_points):
    print(f"\n{BLUE}=== 4. STRESS TEST (Size {size} | {iterations} Rounds) ==={RESET}")
    total_moves, max_found, fails, chk_fails = 0, 0, 0, 0
    
    for i in range(iterations):
        nums = random.sample(range(-50000, 50000), size)
        moves, _, chk = run_test(nums)
        
        total_moves += moves
        max_found = max(max_found, moves)
        if moves > target_5_points: fails += 1
        if chk == "KO": chk_fails += 1
        
        # Simple progress bar
        sys.stdout.write(f"\r  Progress: [{i+1}/{iterations}] ")
        sys.stdout.flush()

    avg = total_moves // iterations
    print(f"\n  Average Moves: {CYAN}{avg}{RESET}")
    print(f"  Worst Case:    {YELLOW}{max_found}{RESET} (Max for 5/5: {target_5_points})")
    print_result("Grading Limit", fails == 0, f"({fails} rounds exceeded limit)")
    print_result("Checker OK", chk_fails == 0, f"({chk_fails} KO'd)")

if __name__ == "__main__":
    has_checker = check_files()
    
    print(f"{YELLOW}--- INITIATING ULTIMATE PUSH_SWAP TESTER ---{RESET}")
    
    test_errors()
    test_sorted()
    
    # All combos of 3 (Max allowed moves: 3, optimized: 2)
    test_permutations(3, 3)
    
    # All combos of 5 (Max allowed moves: 12)
    test_permutations(5, 12)
    
    # Random 100 (Score 5/5 if under 700 moves)
    test_stress(100, 100, 700)
    
    # Random 500 (Score 5/5 if under 5500 moves)
    test_stress(500, 50, 5500)
    
    print(f"\n{GREEN}=== ALL TESTING COMPLETE ==={RESET}\n")