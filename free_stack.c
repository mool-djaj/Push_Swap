/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:22 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 00:25:34 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **sta)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!sta || !*sta)
		return ;
	current = *sta;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*sta = NULL;
}
