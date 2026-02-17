#include "push_swap.h"

static void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;

	i = 0;
	while (args[i])
	{
		free(args[i]); 
		i++;
	}
	free(args);
}

int main(int argc, char **argv)
{
    t_stack *sta;
    char    **tmp_args;
    int     i;
    int     j;
    long    nmb;

    if (argc < 2)
        return (0);
    sta = NULL;
    i = 1;
    while (argv[i])
    {
		tmp_args = ft_split(argv[i], ' ');
        j = 0;
        while (tmp_args[j])
        {
            if (!ft_atol(tmp_args[j], &nmb) || dublicate_num(sta, (int)nmb))
                return (free_split(tmp_args) ,free_stack(&sta) , write(2, "Error\n", 6), 1);
            // 3. Put them in the node
            add_stack_to(&sta, creat_stack((int)nmb));
            free(tmp_args[j]); // Free the string once it's in the stack
            j++;
        }
        free(tmp_args); // Free the array of pointers
        i++;
    }
    // ... logic for is_sorted and algorithm ...
    return (0);
}
