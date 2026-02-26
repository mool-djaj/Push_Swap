/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:59 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 00:36:42 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *sta)
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

t_stack	*find_max(t_stack *sta)
{
	t_stack	*max_node;
	int		max;

	if (!sta)
		return (NULL);
	max = sta->value;
	max_node = sta;
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

t_stack	*find_min(t_stack *sta)
{
	t_stack	*min_node;
	int		min;

	if (!sta)
		return (NULL);
	min = sta->value;
	min_node = sta;
	while (sta)
	{
		if (sta->value < min)
		{
			min = sta->value;
			min_node = sta;
		}
		sta = sta->next;
	}
	return (min_node);
}

void	sort3(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max(*a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
