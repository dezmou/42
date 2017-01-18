#include "../ft_printf.h"

void apply_octal(E)
{
	long value;

	value = (long)va_arg(ARGS,unsigned long);
	if (value == 0 && e->precision != 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base(value,8);
	apply_hex_final(e);
}
