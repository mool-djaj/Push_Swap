#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

int	ft_atol(const char *str, long *nptr);
t_stack	*stack_new(int nbr);
void add_stack_to(t_stack **stack, t_stack *new_nodde);


typedef struct stack
{
	int value;
	int index;
	int pos;
	int target_pos;
	int val_a;
	int val_b;
	struct stack *next;
	struct stack *prev;
} t_stack;

#endif
