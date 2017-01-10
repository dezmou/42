#include "ft_printf.h"

t_env *init_env(void)
{
	t_env *e;
	e = (t_env*)malloc(sizeof(t_env));
	e->str_handled = ft_strdup(CHARS_HANDLED);
	e->nbrread = 0;
	NBRC = -1;
	LRD = 0;
	return (e);
}

void destroy_env(E)
{
	free(e->str_handled);
	free(STR);
	free(e);
}
