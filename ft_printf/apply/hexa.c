#include "../ft_printf.h"

void apply_hex_big(E)
{
	unsigned int value;
	char *str;

	value = va_arg(ARGS,unsigned int);
	str = ft_itoa_base(value,16);
	add_str(e,str);
	free(str);
	e->bigx = 1;
}

void apply_hex_short(E)
{
	unsigned int value;
	char *str;

	value = va_arg(ARGS,unsigned int);
	str = ft_itoa_base(value,16);
	add_str(e,str);
	free(str);
}
