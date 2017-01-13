#include "../ft_printf.h"

void handle_precision(E)
{
	int i;

	i = 0;
	if (CHAR == '.')
	{
		NBRC++;
		if (CHAR == '*')
			e->precision = va_arg(ARGS, int);
		else
			while(ft_isdigit(CHAR))
			{
				e->u_width[i] = CHAR;
				NBRC++;
				i++;
				e->u_width[i] = '\0';
			}
		if (i)
			e->precision = ft_atoi(e->u_width);
	}
}
