/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:01 by akaarich          #+#    #+#             */
/*   Updated: 2026/02/26 02:39:00 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_move(char *line, char *move)
{
	int	i;

	i = 0;
	if (!line || !move)
		return (0); 
	while (move[i] && line[i] && move[i] == line[i])
		i++;
	if (move[i] == '\0' && (line[i] == '\n' || line[i] == '\0'))
		return (1);
	return (0);
}

static int	exec_rotate(char *line, t_stack **a, t_stack **b)
{
	if (is_move(line, "ra"))
		rotate(a);
	else if (is_move(line, "rb"))
		rotate(b);
	else if (is_move(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (is_move(line, "rra"))
		reverse_rotate(a);
	else if (is_move(line, "rrb"))
		reverse_rotate(b);
	else if (is_move(line, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	execute_move(char *line, t_stack **a, t_stack **b)
{
	if (is_move(line, "sa"))
		swap(a);
	else if (is_move(line, "sb"))
		swap(b);
	else if (is_move(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (is_move(line, "pa"))
		push(a, b);
	else if (is_move(line, "pb"))
		push(b, a);
	else if (exec_rotate(line, a, b))
		return (1);
	else
		return (0);
	return (1);
}

static void	print_res(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	while (argv[++i])
		if (!fill_stack(&a, argv[i]))
			return (free_stack(&a), write(2, "Error\n", 6), 1);
	line = get_next_line(0);
	while (line)
	{
		if (!execute_move(line, &a, &b))
			return (write(2, "Error\n", 6), free(line)
				, free_stack(&a), free_stack(&b), 1);
		free(line);
		line = get_next_line(0);
	}
	print_res(a, b);
	return (free_stack(&a), free_stack(&b), 0);
}
