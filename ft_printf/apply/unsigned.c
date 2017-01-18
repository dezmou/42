#include "../ft_printf.h"

void apply_unsigned(E)
{
	unsigned int value;

	value = va_arg(ARGS,unsigned int);
	if (e->fl_pos != 0)
		e->fl_pos = 0;
	if (e->fl_pos != 0 || e->fl_space != 0)
		e->fl_space = 0;
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	TMPS = ft_itoa_u(value);
	apply_precision(e);
	apply_width_dec(e);
	add_str(e,TMPS);
}
