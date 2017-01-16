#include "../ft_printf.h"

void apply_octal(E)
{
	unsigned int value;
	char *str;

	value = va_arg(ARGS,unsigned int);
	str = ft_itoa_base(value,8);
	add_str(e,str);
	free(str);
}
