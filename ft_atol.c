#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atol(const char *str, long *nptr)
{
	long long	nb;
	int			sign;
	int			found_digit;

	nb = 0;
	sign = 1;
	found_digit = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		found_digit = 1;
		nb = nb * 10 + (*str++ - '0');
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (0);
	}
	if (!found_digit || *str != '\0')
		return (0);
	*nptr = nb * sign;
	return (1);
}
