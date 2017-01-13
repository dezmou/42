#include "ft_printf.h"

static void	init_tab(E)
{
	e->tab_spec['d'] = &apply_int;
	/*
	e->tab_spec['s'] = &apply_str;
	e->tab_spec['S'] = &apply_wstr;
	e->tab_spec['p'] = &apply_ptr;
	e->tab_spec['D'] = &apply_long;
	e->tab_spec['i'] = &apply_int;
	e->tab_spec['o'] = &apply_octal;
	e->tab_spec['O'] = &apply_long;
	e->tab_spec['u'] = &apply_unsigned;
	e->tab_spec['U'] = &apply_long;
	e->tab_spec['x'] = &apply_hex;
	e->tab_spec['X'] = &apply_hex;
	e->tab_spec['c'] = &apply_char;
	e->tab_spec['C'] = &apply_wchar;
	e->tab_spec['b'] = &apply_binary;
	e->tab_spec['f'] = &apply_float;
	e->tab_spec['n'] = &apply_charswritten;
	*/
}


void init_env(E)
{
	e->nbrread = 0;
	e->char_rendu = -1;
	init_tab(e);
}

void destroy_env(E)
{
	free(STR);
}
