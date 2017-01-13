#include "ft_printf.h"

t_env init_env(void)
{
	t_env e;

	e.nbrread = 0;
	e.char_rendu = -1;
	return (e);
}

void destroy_env(E)
{
	free(STR);
}
