#include "libft.h"

int 		ft_atoi(const char *str)
{
	int final;
	int i;
	int neg;

	i = 0;
	final = 0;
	neg = 1;
	while ( (str[i] <= 13) && (str[i] >= 9) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		final = (final*10) + (str[i] - '0');
		i++;
	}
	return (final*neg);
}