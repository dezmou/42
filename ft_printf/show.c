#include "ft_printf.h"

void add_char(E,char c)
{
	ft_putchar(c);
	NBRR++;
}

void add_str(E,char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		add_char(e,str[i]);
}
