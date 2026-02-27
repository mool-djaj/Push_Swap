/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:44 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/27 01:06:27 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match)
			{
				best_match = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_pos = find_max(b)->pos;
		else
			a->target_pos = target_node->pos;
		a = a->next;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < best_match)
			{
				best_match = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_pos = find_min(a)->pos;
		else
			b->target_pos = target_node->pos;
		b = b->next;
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (cheap->val_a > 0 && cheap->val_b > 0)
	{
		rr(a, b);
		cheap->val_a--;
		cheap->val_b--;
	}
	while (cheap->val_a < 0 && cheap->val_b < 0)
	{
		rrr(a, b);
		cheap->val_a++;
		cheap->val_b++;
	}
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*a);
	rotate_both(a, b, cheap);
	while (cheap->val_a > 0)
	{
		ra(a);
		cheap->val_a--;
	}
	while (cheap->val_a < 0)
	{
		rra(a);
		cheap->val_a++;
	}
	while (cheap->val_b > 0)
	{
		rb(b);
		cheap->val_b--;
	}
	while (cheap->val_b < 0)
	{
		rrb(b);
		cheap->val_b++;
	}
	pb(b, a);
}

void	push_back(t_stack **a, t_stack **b)
{
	t_stack	*trg;

	if (!*b)
		return ;
	set_current_pos(*b);
	trg = find_max(*b);
	if (trg->pos <= stack_len(*b) / 2)
		while (*b != trg)
			rb(b);
	else
		while (*b != trg)
			rrb(b);
	while (*b)
	{
		trg = get_target_node_a(*a, *b);
		set_current_pos(*a);
		if (trg->pos <= stack_len(*a) / 2)
			while (*a != trg)
				ra(a);
		else
			while (*a != trg)
				rra(a);
		pa(a, b);
	}
}
