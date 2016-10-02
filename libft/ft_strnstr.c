#include "libft.h"

char 	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	int i;
	int itest;

	i = 0;
	while (dest[i] && n)
	{
		if (dest[i] == src[0])
		{
			itest = 0;
			while (1)
			{
				if (src[itest] == '\0')
					return (char *)(&(dest[i]));
				if (dest[i + itest] != src[itest])
					break;
				itest++;
			}	
		}
		n--;
		i++;
	}
	return (NULL);
}