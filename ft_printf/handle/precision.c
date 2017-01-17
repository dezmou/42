#include "../ft_printf.h"

void handle_precision(E)
{
	int i;
	char u_width[64];

	i = 0;
	if (CHAR == '.')
	{
		NBRC++;
		if (CHAR == '*')
			e->precision = va_arg(ARGS, int);
		else
			while(ft_isdigit(CHAR))
			{
				u_width[i] = CHAR;
				NBRC++;
				i++;
				u_width[i] = '\0';
			}
		if (i)
			e->precision = ft_atoi(u_width);
	}
}
