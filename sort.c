#include "push_swap.h"
void det_index(t_stack *stack)
{
	t_stack *current;
	t_stack *compare;
	int		index;

	current = stack;

	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next ;

		}
		current->index = index;
		current = current->next;

	}

}