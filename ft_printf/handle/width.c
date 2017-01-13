#include "../ft_printf.h"

void handle_width(E)
{
	int i;

	i = 0;
	if (CHAR == '*')
	{
		e->width = va_arg(ARGS, int);
		NBRC++;
		return ;
	}

	while (ft_isdigit(CHAR))
	{
		e->u_width[i] = CHAR;
		NBRC++;
		i++;
		e->u_width[i] = '\0';
	}
	e->width = ft_atoi(e->u_width);
}
