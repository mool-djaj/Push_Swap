#include "push_swap.h"

int duplicate_num(t_stack *a, int nmb)
{
    if (!a)
		return (0);
	while (a)
	{
		if (a->value == nmb)
			return (1);
		a = a->next;
	}
	return (0);
}