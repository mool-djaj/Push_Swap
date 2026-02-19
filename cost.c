#include "push_swap.h"

void set_price(t_stack*a, t_stack *b)
{
	int size_a;
	int size_b;

	size_a = stack_len(a);
	size_b = stack_len(b);
	while (a)
	{
		if (a->pos <= size_a / 2)
			a->val_a = a->pos;
		else
			a->val_a = (size_a - a->pos) * (-1) ;
		
		if (a->target_pos <= size_b / 2)
			a->val_b = a->target_pos;
		else
			a->val_b = (size_b - a->target_pos) * (-1) ;
		a = a->next;
	}
}

// In cost.c
void cheapest(t_stack *a)
{
    long    best_val;
    t_stack *best_node;
    long    current_cost;

    if (!a)
        return ;
    best_val = LONG_MAX;
    best_node = NULL;
    while (a)
    {
        // 1. Both positive (rr optimization: cost is the HIGHEST of the two)
        if (a->val_a > 0 && a->val_b > 0)
            current_cost = (a->val_a > a->val_b) ? a->val_a : a->val_b;
            
        // 2. Both negative (rrr optimization: cost is the HIGHEST absolute value)
        else if (a->val_a < 0 && a->val_b < 0)
            current_cost = (ft_abs(a->val_a) > ft_abs(a->val_b)) ? ft_abs(a->val_a) : ft_abs(a->val_b);
            
        // 3. Different directions (No optimization: cost is the sum)
        else
            current_cost = ft_abs(a->val_a) + ft_abs(a->val_b);

        // Compare the real current_cost to best_val
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
