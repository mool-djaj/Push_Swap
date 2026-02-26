#!/bin/bash

GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
RESET="\033[0m"

echo -e "${YELLOW}=== PUSH_SWAP CHECKER TESTER ===${RESET}\n"

# 1. Test already sorted input (should output OK with no moves)
echo -n "Test 1 (Already Sorted): "
ARG="1 2 3 4 5"
RES=$(echo -n "" | ./checker $ARG)
if [ "$RES" == "OK" ]; then echo -e "${GREEN}[PASS] OK${RESET}"; else echo -e "${RED}[FAIL] Expected OK, got: $RES${RESET}"; fi

# 2. Test unsorted input with no moves (should output KO)
echo -n "Test 2 (Unsorted, No Moves): "
ARG="5 4 3 2 1"
RES=$(echo -n "" | ./checker $ARG)
if [ "$RES" == "KO" ]; then echo -e "${GREEN}[PASS] KO${RESET}"; else echo -e "${RED}[FAIL] Expected KO, got: $RES${RESET}"; fi

# 3. Test duplicate arguments (should print Error to stderr)
echo -n "Test 3 (Duplicates): "
ARG="1 2 3 3 5"
RES=$(echo -n "" | ./checker $ARG 2>&1)
if [[ "$RES" == *"Error"* ]]; then echo -e "${GREEN}[PASS] Error${RESET}"; else echo -e "${RED}[FAIL] Expected Error, got: $RES${RESET}"; fi

# 4. Test non-integer arguments (should print Error to stderr)
echo -n "Test 4 (Non-Numeric): "
ARG="1 2 a 4 5"
RES=$(echo -n "" | ./checker $ARG 2>&1)
if [[ "$RES" == *"Error"* ]]; then echo -e "${GREEN}[PASS] Error${RESET}"; else echo -e "${RED}[FAIL] Expected Error, got: $RES${RESET}"; fi

# 5. Test invalid instructions (should print Error to stderr)
echo -n "Test 5 (Invalid Move): "
ARG="1 2 3"
RES=$(echo -e "sa\ninvalid_move\n" | ./checker $ARG 2>&1)
if [[ "$RES" == *"Error"* ]]; then echo -e "${GREEN}[PASS] Error${RESET}"; else echo -e "${RED}[FAIL] Expected Error, got: $RES${RESET}"; fi

# 6. Test with your actual push_swap (The Ultimate Pipeline Test)
if [ -f "./push_swap" ]; then
    echo -n "Test 6 (Pipeline push_swap | checker): "
    # Generates 10 random numbers
    ARG=$(jot -r 10 -100 100 | tr '\n' ' ')
    RES=$(./push_swap $ARG | ./checker $ARG)
    if [ "$RES" == "OK" ]; then echo -e "${GREEN}[PASS] Pipeline OK${RESET}"; else echo -e "${RED}[FAIL] Expected OK, got: $RES${RESET}"; fi
else
    echo -e "${YELLOW}Test 6 Skipped: ./push_swap executable not found in this directory.${RESET}"
fi

echo -e "\n${YELLOW}=== DONE ===${RESET}"