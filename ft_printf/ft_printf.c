#include "ft_printf.h"

int parse_str(E)
{
	NBRC += 1;
	if (CHAR == '%')
	{
		handle_percent(e);
		return (1);
	}
	if (STR[NBRC] == 0)
		return(0);
	add_char(e, CHAR);
	return (1);
}

int ft_printf(const char *restrict format, ...)
{
	t_env *e;

	e = init_env();
	STR = ft_strdup(format);
	va_start(ARGS, format);
	while (parse_str(e));
	va_end(ARGS);
	destroy_env(e);
	return (NBRR);
}

void testit(E)
{
	int reel;
	int ft;

	ft_putstr("\n\n########################\n\n");
	ft_putstr("ft_printf  : ");
	ft = ft_printf(TEST);
	ft_putstr("<--");
	printf("\n");
	printf("Reel printf: ");
	reel = printf(TEST);
	printf("<--");
	printf("\n\n reel : %d \n ft   : %d\n\n", reel, ft);

}

int main(void)
{
	t_env *e;

	e = init_env();
	testit(e);

	return (0);
}
