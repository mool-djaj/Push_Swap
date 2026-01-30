#include "push_swap.h"

void add_stack_to(t_stack **stack, t_stack *new_nodde)
{
	t_stack *last;
	if (!new_nodde)
		return ;
	if (!*stack)
	{
		*stack == new_nodde;
		return ;
	}
	last = get_stack_last(*stack);
	last->next = new_nodde;
	new_nodde->prev = last;
}

t_stack	*get_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}