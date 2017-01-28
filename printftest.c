#include "ft_printf/ft_printf.h"
#include <stdio.h>

# define TEST "%015ls", L"fuck you all"

int main(void)
{
	int rl;
	int ft;

	ft_printf("ft_printf   -->");
	ft = ft_printf(TEST);
	ft_printf("<--\n");
	printf("printf      -->");
	rl = printf(TEST);
	printf("<--\n\n");
	printf("ft : %d\nrl : %d\n", ft, rl);
	return (0);
}
