#include "libft.h"

int 	ft_isalpha(int nbr)
{
	if (((nbr >= 'a')  && (nbr <= 'z')) ||
		((nbr >= 'A') && (nbr <= 'Z')))
		return (1);
	return (0);
}
