#include "../ft_printf.h"



void apply_int(E)
{
	int value;

	value = va_arg(ARGS, int);
	if (e->fl_pos != 0)
		e->fl_space = 0;
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	if (value < 0)
		e->dec_is_neg = 1;
	TMPS = ft_itoa(value);
	apply_width_dec(e);
	
	add_str(e,TMPS);
}
