#include "../ft_printf.h"

void apply_str(E)
{
	char *str;

	str = (char*)va_arg(ARGS,char*);
	if (str == NULL)
	{
		TMPS = ft_strdup("(null)");
	}
	else
		TMPS = ft_strdup(str);
	apply_precision_str(e);
	apply_width(e);
	add_str(e,TMPS);
}
