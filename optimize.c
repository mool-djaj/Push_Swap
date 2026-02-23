#include "push_swap.h"

void align_b(t_stack **b)
{
	t_stack	*max_b;
	int		size_b;

	if (!*b)
		return ;

	set_current_pos(*b);
	max_b = find_max(*b);
	size_b = stack_len(*b);
	/*If the biggest number is in the top half, spin UP*/
	if (max_b->pos <= size_b / 2)
	{
		while (*b != max_b)
		rb(b);
    }
	/*If it's in the bottom half, spin DOWN*/
	else
	{
		while (*b != max_b)
			rrb(b);
	}
}

int	calculate_true_cost(t_stack *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_abs(node->val_a);
	cost_b = ft_abs(node->val_b);
	/*If BOTH are positive (ra and rb) OR BOTH are negative (rra and rrb)
	They get the combo discount! Return the MAXIMUM of the two.*/
	if ((node->val_a >= 0 && node->val_b >= 0) 
		|| (node->val_a < 0 && node->val_b < 0))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	/*If they are going opposite directions (one is +, one is -)
	No discount. You must add them together.*/
	return (cost_a + cost_b);
}
