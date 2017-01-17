#include "../ft_printf.h"

void apply_char(E)
{
	char str[2];

	str[0] = (char)va_arg(ARGS, int);
	str[1] = 0;
	TMPS = ft_strdup(str);
	if (str[0] == 0)
	{
		NBRR++;
		e->width--;
	}
	apply_width(e);
	add_str(e,TMPS);
}
