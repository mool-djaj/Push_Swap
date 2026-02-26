/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:18 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 00:25:05 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_num(t_stack *a, int nmb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nmb)
			return (1);
		a = a->next;
	}
	return (0);
}
