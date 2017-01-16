#include "../ft_printf.h"

void apply_long(E)
{
	long value;
	char *str;

	value = (long)va_arg(ARGS, long);
	str = ft_itoa(value);
	add_str(e,str);
	free(str);
}
