#include "libft.h"

int 	ft_isdigit(int nbr)
{
	if ((nbr <= '9') && (nbr >= '0'))
		return (1);
	return (0);
}