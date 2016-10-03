#include "libft.h"

int 	ft_isprint(int nbr)
{
	if ((nbr <= 126) && (nbr > 31))
		return (1);
	return (0);
}