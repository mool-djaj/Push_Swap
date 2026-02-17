      //parsing
//join join all arguments in single sting
//split all arguments
//atol read numbers
// put them in the node
// duplication / is sorted 
// stuck created 
#include "push_swap.h"

void	free_split(char **args)
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

int	fill_stack(t_stack **sta, char *arg)
{
	char	**tmp_args;
	long	nmb;
	int		j;

	tmp_args = ft_split(arg, ' ');
	if (!tmp_args)
		return (0);
	j = 0;
	while (tmp_args[j])
	{
		if (!ft_atol(tmp_args[j], &nmb) || dublicate_num(*sta, (int)nmb))
		{
			free_split(tmp_args);
			return (0);
		}
		add_stack_to(sta, creat_stack((int)nmb)); //
		j++;
	}
	free(tmp_args);
	return (1);
}
