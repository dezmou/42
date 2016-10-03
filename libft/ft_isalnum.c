#include "libft.h"

int 	ft_isalnum(int nbr)
{
	if (((nbr <= '9') && (nbr >= '0')) ||
		((nbr >= 'a')  && (nbr <= 'z')) ||
		((nbr >= 'A') && (nbr <= 'Z')))
		return (1);
	return (0);
}