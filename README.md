*This project has been created as part of the 42 curriculum by akaarich.*

# Push_Swap

## Description
**Push_Swap** is a highly algorithmic project from the 42 curriculum. The primary goal is to sort data on a stack, with a limited set of instructions, using the absolute lowest possible number of actions. 

We start with two stacks: 
* **Stack A**: Contains a random list of un-duplicated integers (positive and/or negative) provided as arguments.
* **Stack B**: Starts empty.

The objective is to sort the numbers in Stack A in ascending order using only the following specific operations:
* **Swap:** `sa`, `sb`, `ss` (swap the first two elements of a stack)
* **Push:** `pa`, `pb` (push the top element of one stack to the other)
* **Rotate:** `ra`, `rb`, `rr` (shift all elements up by one; the top element becomes the last)
* **Reverse Rotate:** `rra`, `rrb`, `rrr` (shift all elements down by one; the last element becomes the top)

---

## Features
* **Mandatory Part:** A highly optimized sorting algorithm (`push_swap`) that computes the most efficient sequence of moves to sort any given stack of integers.
* **Bonus Part:** A custom `checker` program that takes a list of integers, reads instructions from standard input (or a pipe), executes them, and verifies if the resulting stack is actually sorted.
* **Robust Error Handling:** Detects duplicate inputs, non-numeric characters, integer overflows/underflows, and invalid instructions.

---

## Libft Usage
This project relies heavily on **Libft**, a custom C library created earlier in the 42 curriculum. Because standard C library functions (like `printf` or `atoi`) are forbidden, Libft is used here to handle:
* **String parsing:** `ft_split` to handle numbers passed as a single string.
* **Conversions:** Custom `ft_atol` to safely convert strings to long integers and check for `INT_MAX`/`INT_MIN` overflows.
* **Memory Management:** Safe freeing of strings and linked list nodes.

---

## Technical Choices & Algorithm Description
To achieve the lowest possible number of operations and secure a maximum score, this project implements a highly optimized **Cost-Calculation Algorithm** (often referred to as the "Mechanical Turk").

Instead of sorting blindly or chunking numbers into arbitrary groups, the algorithm calculates the exact cost of moving every single node to its correct sorted position before making a move.

**The Step-by-Step Process:**
1. **Push to B:** The algorithm continuously pushes elements from Stack A to Stack B until only 3 elements remain in Stack A. 
2. **Sort 3:** It sorts the remaining 3 elements in Stack A using a hardcoded, hyper-efficient method (maximum of 2 moves).
3. **Calculate Costs:** For every single node currently in Stack B, the algorithm calculates:
   * How many rotations (`rb`/`rrb`) are needed to bring it to the top of B.
   * How many rotations (`ra`/`rra`) are needed to rotate Stack A so that the node is placed in its exact sorted position.
4. **Combo Optimization:** It checks if the rotation directions for A and B match. If they do, it heavily utilizes the simultaneous operations `rr` and `rrr` to spin both stacks at once, saving valuable moves.
5. **Execute the Cheapest Node:** It scans the calculated costs, finds the node with the absolute lowest combined cost, executes the necessary rotations, and pushes (`pa`) the node to A.
6. **Final Alignment:** It repeats this process until Stack B is empty. Finally, it finds the smallest number in Stack A and rotates the stack until that number is at the top.

---

## Instructions

### Compilation
The project includes a comprehensive `Makefile` to compile the executables using standard 42 flags (`-Wall -Wextra -Werror`) and link the `libft` library.

* `make`: Compiles the `libft` library and the main `push_swap` program.
* `make bonus`: Compiles the custom `checker` program used to verify if instructions actually sort the stack.
* `make clean`: Removes all compiled `.o` object files (including inside the `libft` directory).
* `make fclean`: Runs `clean` and also removes the final executables (`push_swap`, `checker`) and the `libft.a` archive.
* `make re`: Runs `fclean` followed by `make`, completely recompiling the project from scratch.

### Execution & Usage

**1. Running Push_Swap:**
Run the program by providing a list of integers as arguments. It will output the exact sequence of instructions required to sort the stack.
```bash
./push_swap 4 67 3 87 23
