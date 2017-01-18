#include "../ft_printf.h"

void apply_long(E)
{
	long value;

	value = (long)va_arg(ARGS, long);
	TMPS = ft_itoa(value);
	if (e->fl_pos != 0)
		e->fl_space = 0;
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	if (value < 0)
		e->dec_is_neg = 1;
	apply_precision(e);
	apply_width_dec(e);
	add_str(e,TMPS);
}
