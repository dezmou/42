#include "libft.h"

void				ft_strtolower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}
