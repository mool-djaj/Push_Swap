#include "push_swap.h"

// 1. The clean string matcher
int is_move(char *line, char *move)
{
    int i = 0;

    if (!line || !move)
        return (0);
    
    while (move[i] && line[i] && move[i] == line[i])
        i++;
    
    if (move[i] == '\0' && (line[i] == '\n' || line[i] == '\0'))
        return (1);
    
    return (0);
}

// 2. The Updated Executor
int execute_move(char *line, t_stack **a, t_stack **b)
{
    // --- THE FIX: Ignore empty lines or GNL EOF bugs! ---
    if (line[0] == '\n' || line[0] == '\0')
        return (1); 
    // ----------------------------------------------------

    if (is_move(line, "sa"))
        swap(a);
    else if (is_move(line, "sb"))
        swap(b);
    else if (is_move(line, "ss"))
    { swap(a); swap(b); }
    else if (is_move(line, "pa"))
        push(a, b);
    else if (is_move(line, "pb"))
        push(b, a);
    else if (is_move(line, "ra"))
        rotate(a);
    else if (is_move(line, "rb"))
        rotate(b);
    else if (is_move(line, "rr"))
    { rotate(a); rotate(b); }
    else if (is_move(line, "rra"))
        reverse_rotate(a);
    else if (is_move(line, "rrb"))
        reverse_rotate(b);
    else if (is_move(line, "rrr"))
    { reverse_rotate(a); reverse_rotate(b); }
    else
        return (0); // Not a valid move!
    return (1);
}

// 2. The Main Program
int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    char    *line;
	int 	i;

	i = 1;
    if (argc < 2)
        return (0);// Parse identical to push_swap
    while (argv[i])
    {
        if (!fill_stack(&a, argv[i]))
            return (free_stack(&a), write(2, "Error\n", 6), 1);
        i++;
    }// Read moves and execute them silently
    line = get_next_line(0);
    while (line)
    {
        if (!execute_move(line, &a, &b))
		{
            write(2, "Error\n", 6);
            free(line);
            free_stack(&a);
            free_stack(&b);
            return (1);
		}
        free(line);
        line = get_next_line(0);
    }// Final Check: Is it sorted and is B empty?
    if (is_sorted(a) && b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
