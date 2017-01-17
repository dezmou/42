#include "../ft_printf.h"

void apply_percent(E)
{
	TMPS = ft_strdup("%");
	apply_width(e);
	add_str(e,TMPS);
}
