#include "push_swap.h"

static int is_sorted(t_stack *sta)
{
	if (!sta)
		return (1);

	while (sta->next)
	{
		if (sta->value > sta->next->value)
			return (0);
		sta = sta->next;
	}
	return (1);
}

static t_stack *find_max(t_stack *sta)
{
	t_stack *max_node;
	int		max;

	if (!sta)
		return (NULL);
	
	max = INT_MIN;

	while (sta)
	{
		if (sta->value > max)
		{
			max = sta->value;
			max_node = sta;
		}
		sta = sta->next;
	}
	return (max_node);
}

void sort3(t_stack **a)
{
	t_stack *max_node;

	max_node = find_max(*a);

	if (*a == max_node)
		ra(a);

	else if ((*a)->next == max_node)
		rra(a);

	if ((*a)->value > (*a)->next->value)
		sa(a);
}