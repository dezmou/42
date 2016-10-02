#include "libft.h"

char 	*ft_strdup(const char *s)
{
	int i;
	char *final;

	i = 0;
	if (!(final = (char *)malloc(sizeof(char)*(ft_strlen(s) + 1))))
		return NULL;
	while (s[i])
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return final;
}