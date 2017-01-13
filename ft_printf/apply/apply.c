#include "../ft_printf.h"

void apply_flag_space(E)
{
	if (e->fl_space)
		add_char(e,' ');
}


void apply(E)
{
	if (e->specifier == 's')
		e->finalstr = va_arg(ARGS, char*);
	apply_flag_space(e);
	add_str(e, e->finalstr);

}
