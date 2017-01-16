#include "../ft_printf.h"

void apply_unsigned(E)
{
	char *str;
	unsigned int value;

	value = va_arg(ARGS,unsigned int);
	str = ft_itoa(value);
	add_str(e,str);
	free(str);
}
