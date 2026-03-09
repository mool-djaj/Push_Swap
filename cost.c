/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:06 by akaarich          #+#    #+#             */
/*   Updated: 2026/03/09 22:43:42 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_cost(long val_a, long val_b)
{
	long	abs_a;
	long	abs_b;

	abs_a = ft_abs(val_a);
	abs_b = ft_abs(val_b);
	if ((val_a > 0 && val_b > 0) || (val_a < 0 && val_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

void	set_price(t_stack *a, t_stack *b)
{
	int		s_a;
	int		s_b;
	long	c[4];

	s_a = stack_len(a);
	s_b = stack_len(b);
	while (a)
	{
		c[0] = get_cost(a->pos, a->target_pos);
		c[1] = get_cost(a->pos, a->target_pos - s_b);
		c[2] = get_cost(a->pos - s_a, a->target_pos);
		c[3] = get_cost(a->pos - s_a, a->target_pos - s_b);
		a->val_a = a->pos;
		a->val_b = a->target_pos;
		if (c[1] < c[0] && c[1] <= c[2] && c[1] <= c[3])
			a->val_b = a->target_pos - s_b;
		else if (c[2] < c[0] && c[2] <= c[1] && c[2] <= c[3])
			a->val_a = a->pos - s_a;
		else if (c[3] < c[0] && c[3] <= c[1] && c[3] <= c[2])
		{
			a->val_a = a->pos - s_a;
			a->val_b = a->target_pos - s_b;
		}
		a = a->next;
	}
}

void	cheapest(t_stack *a)
{
	t_stack	*best_node;
	long	best_val;
	long	cost;
	t_stack	*tmp;

	if (!a)
		return ;
	best_val = LONG_MAX;
	best_node = NULL;
	tmp = a;
	while (tmp)
	{
		tmp->cheap = 0;
		cost = get_cost(tmp->val_a, tmp->val_b);
		if (cost < best_val || (cost == best_val
				&& best_node && tmp->value > best_node->value))
		{
			best_val = cost;
			best_node = tmp;
		}
		tmp = tmp->next;
	}
	if (best_node)
		best_node->cheap = 1;
}

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheap == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	final_check(t_stack **a)
{
	t_stack	*min_node;
	int		min_pos;
	int		min_value;
	int		size;

	set_current_pos(*a);
	min_node = find_min(*a);
	min_pos = min_node->pos;
	min_value = min_node->value;
	size = stack_len(*a);
	if (min_pos <= size / 2)
		while ((*a)->value != min_value)
			ra(a);
	else
		while ((*a)->value != min_value)
			rra(a);
}
