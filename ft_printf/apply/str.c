#include "../ft_printf.h"

void apply_str(E)
{
	TMPS = ft_strdup((char*)va_arg(ARGS,char*));
	apply_width(e);
	add_str(e,TMPS);
}
