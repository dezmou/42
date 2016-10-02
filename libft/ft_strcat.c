#include "libft.h"

char 	 *ft_strcat(char *dest, const char *src)
{
	int i;
	int i_src;

	i = 0;
	i_src = 0;
	while (dest[i])
		i++;
	while (src[i_src])
	{
		dest[i] = src[i_src];
		i++;
		i_src++;
	}
	dest[i] = '\0';
	return (dest);
}