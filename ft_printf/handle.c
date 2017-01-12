#include "ft_printf.h"

void handle_percent(E)
{
	NBRC += 1;
	LRD = 0;
	handle(e);
	//NBRC += 1;
}


void 	handle(E)
{
	if (LDR == 0)
		handle_flags(e);
	/*
	if (LDR == 1)
		handle_width(e);
	if (LDR == 2)
		handle_precision(e);
	if (LDR == 3)
		handle_length(e);
	if (LDR == 4)
		handle_specifier(e);
	*/
}
