#include "../ft_printf.h"

void apply_invalid(E)
{
	TMPS = ft_strdup("");
	TMPS[0] = e->specifier;
	apply_width(e);
	add_str(e,TMPS);
}
