#include "push_swap.h"

t_stack	*get_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void add_stack_to(t_stack **stack, t_stack *new_sta)
{
	t_stack *last;
	if (!new_sta)
		return ;
	if (!*stack)
	{
		*stack = new_sta;
		return ;
	}

	last = get_stack_last(*stack);
	last->next = new_sta;
	new_sta->prev = last;
}
