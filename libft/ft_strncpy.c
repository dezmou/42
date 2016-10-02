#include "libft.h"

char 	*ft_strncpy(char *dest, const char *src,size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (!src[i])
			break ; 
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}