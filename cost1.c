#include "push_swap.h"

void set_current_pos(t_stack *sta)
{
	int i;

	i = 0;
	while (sta)
	{
		sta->pos = i;
		sta = sta->next;
		i++;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int stack_len(t_stack *sta)
{
	int i;

	i = 0;
	while (sta)
	{
		sta = sta->next;
		i++;
	}
	return (i);
}

void big_sort(t_stack **a, t_stack **b)
{
    // 1. Move everything to B until only 3 are left in A
    if (stack_len(*a) > 3)
        pb(b, a);
    if (stack_len(*a) > 3)
        pb(b, a);
    while (stack_len(*a) > 3)
    {
        set_current_pos(*a);
        set_current_pos(*b);
        set_target_b(*a, *b);
        set_price(*a, *b);
        cheapest(*a);
        move_to_b(a, b);
    }

    // 2. Sort the final 3 numbers
    sort3(a);

    // 3. Push everything back from B to A in order
    push_back(a, b);

    // 4. Final alignment: Smallest number to the top
    final_check(a);
}

