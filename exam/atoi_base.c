#include <stdio.h>
#include <stdlib.h>
/*
int len(char *str)
{
	int i = -1;
	while (str[++i]);
	return i;
}

int atoi_base(char *in, int base)
{
	int final = 0;
	int nbr;
	int inc = 1;
	for (int i = len(in)-1; i >= 0; i--){
		if (in[i] <= 'Z' && in[i] >= 'A')
			nbr = in[i] - 'A' + 10;
		else
			nbr = in[i] - '0';
		final += nbr * inc;
		inc *= base;
	}
	return final;
}
*/

void    print_memory(const void *addr, size_t size)
{

}
int main(void)
{
    int tab[10] = {0, 23, 150, 154354,
                  12, 16,  21, 42};
	char tmp[100];

	for (int i = 0; i < sizeof(tab)/4; i++){
		sprintf(tmp, "%x", tab[i]);
		printf("%s\n", tmp);
	}
	return (0);
}

/*
23 = 17 00 00 00
	 23


	 0000 0000 1700 0000 9600 0000 ff00 0000 ................$
	 0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
	 0000 0000 0000 0000                     ........$

*/
