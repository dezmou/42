#include "libft.h"

char 	*ft_strstr(const char *dest, const char *src)
{
	int i;
	int itest;

	i = 0;
	while (dest[i])
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
		i++;
	}
	return (NULL);
}