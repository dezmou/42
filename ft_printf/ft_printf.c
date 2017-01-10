#include "ft_printf.h"



int is_handled(E)
{
	int i;

	i = -1;
	while (e->str_handled[++i])
		if (e->str_handled[i] == CHAR)
			return (1);
	return (0);
}

void handle_percent(E)
{
	NBRC += 1;
	if (is_handled(e))
		handle(e);
	NBRC += 1;
}

int parse_str(E)
{
	NBRC += 1;
	if (CHAR == '%')
		handle_percent(e);
	if (STR[NBRC] == 0)
		return(0);
	return (1);
}

int ft_printf(const char *restrict format, ...)
{
	t_env *e;

	e = init_env();
	STR = ft_strdup(format);
	va_start(ARGS, format);
	while (parse_str(e))
	{
		ft_putchar(CHAR);
		e->nbrread++;
	}
	va_end(ARGS);
	destroy_env(e);
	return (e->nbrread);
}
/*
int main(void)
{
	printf("bonjour% d", 500);
	//ft_printf("bonjour  %d", 50);
	return (0);
}
*/
