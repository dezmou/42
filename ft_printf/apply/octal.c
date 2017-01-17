#include "../ft_printf.h"

void apply_octal(E)
{
	unsigned int value;

	value = va_arg(ARGS,unsigned int);
	if (value == 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base(value,8);
	apply_hex_final(e);
}
