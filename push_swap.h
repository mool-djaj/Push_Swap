#ifndef PUSH_SWAP
 #define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

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

void add_stack_to(t_stack **stack, t_stack *new_nodde);
t_stack	*creat_stack(int nbr);
t_stack	*get_stack_last(t_stack *stack);
void free_stack(t_stack **sta);
int	ft_atol(const char *str, long *nptr);
void add_stack_to(t_stack **stack, t_stack *new_nodde);
int dublicate_num(t_stack *a, int nmb);


#endif
