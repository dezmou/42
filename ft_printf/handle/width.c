#include "../ft_printf.h"


void get_more_prec(E)
{
	int more;

	more = e->precision - ft_strlen(TMPS);
	e->final_prec = more;
}

void get_more_width(E)
{
	int more;

	more = e->width - ft_strlen(TMPS);
	e->finalwidth = more;
}

void handle_width(E)
{
	int i;
	char u_width[64];

	i = 0;
	if (CHAR == '*')
	{
		e->width = va_arg(ARGS, int);
		NBRC++;
		return ;
	}
	while (ft_isdigit(CHAR))
	{
		u_width[i] = CHAR;
		NBRC++;
		i++;
		u_width[i] = '\0';
	}
	e->width = ft_atoi(u_width);
}
