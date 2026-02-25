#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*to_move;

	if (!src || !*src)
		return ;

	to_move = *src;
	*src = to_move->next;

	if (*src)
		(*src)->prev = NULL;

	to_move->prev = NULL;

	if (!*dest)
	{
		to_move->next = NULL;
	}
	else
	{
		to_move->next = *dest;
		(*dest)->prev = to_move;
	}

	*dest = to_move;
}
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
