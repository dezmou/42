#include "func.h"

void 	tests(char *text)
{
	printf("%s\n",text);
}

void 	testint(int text)
{
	printf("%d\n",text);
}

void 	wstr(char *str)
{
	write(3,str,ft_strlen(str));
}
void 		wchar(char c)
{
	write(3,&c,1);
}

void		w_putnbr(int nb)
{
	if (nb < 0)
	{
		wchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		w_putnbr(nb / 10);
		w_putnbr(nb % 10);
	}
	else
	{
		wchar(nb + '0');
	}
}