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
	t_env e;

	init_env(&e);
	e.str = ft_strdup(format);
	va_start(e.args, format);
	while (parse_str(&e));
	va_end(e.args);
	destroy_env(&e);
	return (e.nbrread);
}

void testit()
{
	int reel ;
	int ft ;

	ft_putstr("\n\n########################\n\n");
	ft_putstr("ft_printf  :-->");
	ft = ft_printf(TEST);
	ft_putstr("<--");
	printf("\n");
	printf("Reel printf:-->");
	reel = printf(TEST);
	printf("<--");
	printf("\n\n reel : %d \n ft   : %d\n\n", reel, ft);
}

int main(void)
{

	testit();
	//ft_printf(TEST);
	//printf("%s", (wchar_t*)("bonjour"));
	return (0);
}
