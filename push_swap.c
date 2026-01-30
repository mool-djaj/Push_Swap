#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		return(0);
	int i;
	long nmb;
	i = 1;

	while (argv[i])
	{
		if (!ft_atol(argv[i], &nmb))
			return (write(2,"Error\n",6), 1);
		
	}
	
	
	
}