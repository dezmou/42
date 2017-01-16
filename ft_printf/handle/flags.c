#include "../ft_printf.h"

void apply_hash(E)
{
	if (e->fl_hash == 1)
	{

	}
}

void apply_flags(E)
{

}

static void handle_flag(E,char c)
{
	e->is_flagged = 1;
	if (c == '-')
		e->fl_neg = 1;
	if (c == '+')
		e->fl_pos = 1;
	if (c == ' ')
		e->fl_space = 1;
	if (c == '#')
		e->fl_hash = 1;
	if (c == '0')
		e->fl_zero = 1;
	NBRC++;
	handle_flags(e);
}

void handle_flags(E)
{
	if (CHAR == '-')
		handle_flag(e,'-');
	if (CHAR == '+')
		handle_flag(e,'+');
	if (CHAR == ' ')
		handle_flag(e,' ');
	if (CHAR == '#')
		handle_flag(e,'#');
	if (CHAR == '0')
		handle_flag(e,'0');
}
