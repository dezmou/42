#include "../ft_printf.h"


void apply_int(E)
{

}

static void assign(E, void (*func)(t_env*))
{
	func(e);
}

void apply(E)
{
	assign(e,e->tab_spec[e->specifier]);

}
