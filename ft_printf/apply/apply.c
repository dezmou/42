#include "../ft_printf.h"

static void assign(E, void (*func)(t_env*))
{
	func(e);
}

void apply(E)
{
	assign(e,e->tab_spec[e->specifier]);
}
