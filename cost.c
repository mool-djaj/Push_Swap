#include "push_swap.h"

void set_price(t_stack*a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_len(a);
	size_b = stack_len(b);
	while (a)
	{
		if (a->pos <= size_a / 2)
			a->val_a = a->pos;
		else
			a->val_a = (size_a - a->pos) * (-1);
		
		if (a->target_pos <= size_b / 2)
			a->val_b = a->target_pos;
		else
			a->val_b = (size_b - a->target_pos) * (-1) ;
		a = a->next;
	}
}

void cheapest(t_stack *a)
{
	t_stack	*best_node;
    long	best_val;
    long	current_cost;

    if (!a)
        return ;
    best_val = LONG_MAX;
    best_node = NULL;
    while (a)
    {
        if (a->val_a > 0 && a->val_b > 0)
        {
            if (a->val_a > a->val_b)
                current_cost = a->val_a;
            else
                current_cost = a->val_b;
        }
        else if (a->val_a < 0 && a->val_b < 0)
        {
            if (ft_abs(a->val_a) > ft_abs(a->val_b))
                current_cost = ft_abs(a->val_a);
            else
                current_cost = ft_abs(a->val_b);
        }
        else
            current_cost = ft_abs(a->val_a) + ft_abs(a->val_b);
        if (current_cost < best_val)
        {
            best_val = current_cost;
            best_node = a;
        }
        a->cheap = 0;
        a = a->next;
    }
    if (best_node)
        best_node->cheap = 1;
}


t_stack *get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheap == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void final_check(t_stack **a)
{
	int	min_pos;
	int size;

	set_current_pos(*a);
	min_pos = find_min(*a)->pos;
	size = stack_len(*a);

	if (min_pos <= size / 2)
		while ((*a)->value != find_min(*a)->value)
			ra(a);
	else
		while ((*a)->value != find_min(*a)->value)
 			rra(a);
}
