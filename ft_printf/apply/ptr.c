#include "../ft_printf.h"

void apply_ptr(E)
{
	long value ;

	value = (long)va_arg(ARGS, void*);
	if (value == 0 || (void*)value == NULL)
	{
		TMPS = ft_strdup("0x0");
		apply_width(e);
		add_str(e,TMPS);
		return ;
	}
	TMPS = ft_itoa_base(value,16);
	ft_strtolower(TMPS);
	TMPS = ft_str_join_free("0x",TMPS, 2);
	add_str(e,TMPS);
}
