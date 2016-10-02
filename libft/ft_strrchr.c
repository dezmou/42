#include "libft.h"

char 	*ft_strrchr(const char *s, int c)
{
	int i;
	char *adr;
	adr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == ((char)c))
			adr = (char *)(&(s[i]));
		i++;
	}
	if (s[i] == ((char)c))
		adr = (char *)(&(s[i]));
	return (adr);
}