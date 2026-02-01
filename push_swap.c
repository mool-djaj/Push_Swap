#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		return(0);

	int i;
	t_stack *sta;
	t_stack *new_sta;
	long nmb;

	i = 1;
	sta = NULL;

	while (argv[i])
	{
		if (!ft_atol(argv[i], &nmb) || dublicate_num(sta, (int)nmb))
			return (free_stack(&sta), write(2,"Error\n",6), 1);
		new_sta = creat_stack(nmb);
		if (!new_sta)
			return(free_stack(&new_sta), 1);
		add_stack_to(&sta, new_sta);
		i++;
	}

	free_stack(&sta);
	return (0);
}
