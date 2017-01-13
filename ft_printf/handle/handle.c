#include "../ft_printf.h"

void reset_spec(E)
{
	e->is_flagged = 0;
	e->fl_neg = 0;
	e->fl_pos = 0;
	e->fl_space = 0;
	e->fl_hash = 0;
	e->fl_zero = 0;
	e->width = 0;
	e->precision = -1;
	e->length = 0;
	e->specifier = 0;
}

void handle_percent(E)
{
	if (STR[NBRC+1] == '%')
	{
		add_char(e,'%');
		return ;
	}
	reset_spec(e);
	NBRC += 1;
	handle(e);
}
void show_params(E)
{
	printf("##############\nis flagged: %d\n\n", e->is_flagged);
	printf("fl_neg    : %d\n", e->fl_neg);
	printf("fl_pos    : %d\n", e->fl_pos);
	printf("fl_space  : %d\n", e->fl_space);
	printf("fl_hash   : %d\n", e->fl_hash);
	printf("fl_zero   : %d\n\n", e->fl_zero);
	printf("width     : %d\n", e->width);
	printf("precision : %d\n", e->precision);
	printf("length    : %d\n", e->length);
	printf("specifier : %c\n\n\n", e->specifier);
}

void 	handle(E)
{
	handle_flags(e);
	handle_width(e);
	handle_precision(e);
	handle_length(e);
	handle_specifier(e);
	apply(e);

}
