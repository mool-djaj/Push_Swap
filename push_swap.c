#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *sta;
	t_stack *stb;
    int     i;

    if (argc < 2)
        return (0);
    sta = NULL;
	stb = NULL;
    i = 1;
    while (argv[i])
    {
            if (!fill_stack(&sta, argv[i]))
				return (free_stack(&sta) ,write(2, "Error\n", 6) ,1);
        	i++;
    }
			if (!is_sorted(sta))
		{
			if(stack_len(sta) == 2)
				sa(&sta);
			else if (stack_len(sta) == 3)
				sort3(&sta);
			else
				big_sort(&sta,&stb);
		}
	return (free_stack(&stb), free_stack(&sta), 0);
}
