/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:06 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 00:21:27 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_stack*a, t_stack *b)
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
			a->val_b = (size_b - a->target_pos) * (-1);
		a = a->next ;
	}
}

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

void	cheapest(t_stack *a)
{
	t_stack	*best_node;
	long	best_val;
	long	cost;
	t_stack	*tmp;

	if (!a)
		return ;
	best_val = LONG_MAX;
	tmp = a;
	while (tmp)
	{
		tmp->cheap = 0;
		cost = get_cost(tmp->val_a, tmp->val_b);
		if (cost < best_val)
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
	int	min_pos;
	int	size;

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
