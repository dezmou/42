#include "../ft_printf.h"

void apply_int(E)
{
	char *str;
	int value;

	value = va_arg(ARGS, int);
	str = ft_itoa(value);
	add_str(e,str);
	free(str);
}
