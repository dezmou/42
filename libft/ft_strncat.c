#include "libft.h"

char 	 *ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t i_src;

	i = 0;
	i_src = 0;
	while (dest[i])
		i++;
	while (i_src < n)
	{
		dest[i] = src[i_src];
		i++;
		i_src++;
	}
	dest[i] = '\0';
	return (dest);
}