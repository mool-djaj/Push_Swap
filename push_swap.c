#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *sta;
    int     i;
	int j = 0;

    if (argc < 2)
        return (0);

    sta = NULL;
    i = 1;
    while (argv[i])
    {
            if (!fill_stack(&sta, argv[i]))
				return (free_stack(&sta) ,write(2, "Error\n", 6) ,1);
			else
			{
				while (j++ < 10)
				{
					printf("%d\n",sta->value);
					sta = sta->next;
				}
			}
			
        i++;
    }
    return (0);
}
