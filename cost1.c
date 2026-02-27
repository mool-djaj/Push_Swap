/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:10 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 23:09:34 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_pos(t_stack *sta)
{
	int	i;

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

int	stack_len(t_stack *sta)
{
	int	i;

	i = 0;
	while (sta)
	{
		sta = sta->next;
		i++;
	}
	return (i);
}

void	big_sort(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3)
		pb(b, a);
	if (stack_len(*a) > 3)
		pb(b, a);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b);
	while (stack_len(*a) > 3)
	{
		set_current_pos(*a);
		set_current_pos(*b);
		set_target_b(*a, *b);
		set_price(*a, *b);
		cheapest(*a);
		move_to_b(a, b);
	}
	sort3(a);
	push_back(a, b);
	final_check(a);
}

t_stack	*get_target_node_a(t_stack *a, t_stack *b_node)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	current_a = a;
	target_node = NULL;
	best_match = LONG_MAX;
	while (current_a)
	{
		if (current_a->value > b_node->value && current_a->value < best_match)
		{
			best_match = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (best_match == LONG_MAX)
		return (find_min(a));
	return (target_node);
}
