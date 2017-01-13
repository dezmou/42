#include "../ft_printf.h"

void apply(E)
{
	if (e->specifier == 's')
		e->finalstr = va_arg(ARGS, char*);
	add_str(e, e->finalstr);
}
