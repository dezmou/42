#include "../ft_printf.h"

static void assign(E, void (*func)(t_env*))
{
	func(e);
}
static int is_valid_spec(E)
{
	char *valid;
	int i;

	if (e->specifier <= 0)//useless ?
		return (0);
	i = -1;
	valid = ft_strdup(VALID);
	while (valid[++i])
	{
		if (valid[i] == e->specifier)
		{
			free(valid);
			return(1);
		}
	}
	free(valid);
	return (0);
}

void apply(E)
{
	if (is_valid_spec(e))
		assign(e,e->tab_spec[e->specifier]);
	else
		assign(e,e->tab_spec['R']);
}
