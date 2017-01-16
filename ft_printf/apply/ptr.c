#include "../ft_printf.h"

void apply_ptr(E)
{
	long value ;
	char *str;
	char *final;

	value = (long)va_arg(ARGS, void*);
	if (value == 0)
	{
		add_str(e,"0x0");
		return ;
	}
	str = ft_itoa_base(value,16);
	ft_strtolower(str);
	final = ft_strjoin("0x", str);
	add_str(e,final);
	free(str);
	free(final);

}
