#include "../ft_printf.h"

static char  *get_prefix(E)
{
	char *final;

	if (e->specifier == 'o' || e->specifier == 'O')
		return (ft_strdup("0"));
	else
	{
		final = ft_strdup("0x");
		final[1] = e->bigx;
	}
	return (final);
}

static void apply_hex_zero_octal(E,char *prefix)
{
	if (e->finalwidth >= 1)
		TMPS[0] = prefix[0];
	else
		TMPS = ft_str_join_free("0", TMPS, 2);
}

static void apply_hex_zero(E,char *prefix)
{
	if (e->specifier == 'o' || e->specifier == 'O')
	{
		apply_hex_zero_octal(e, prefix);
		return ;
	}
	if (e->finalwidth >= 2)
	{
		TMPS[0] = prefix[0];
		TMPS[1] = prefix[1];
	}
	else if (e->finalwidth >= 1)
	{
		TMPS[0] = prefix[1];
		if (e->specifier == 'x')
			TMPS = ft_str_join_free("x", TMPS, 2);
		else
			TMPS = ft_str_join_free("X", TMPS, 2);
	}
	else
	{
		if (e->specifier == 'x')
			TMPS = ft_str_join_free("0x", TMPS, 2);
		else
			TMPS = ft_str_join_free("0X", TMPS, 2);
	}
}






void apply_hex_final(E)
{
	char *tmp;

	apply_precision(e);
	tmp = get_prefix(e);
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	if (e->fl_hash != 0)
	{
		if (e->fl_zero == ' ')
		{
			TMPS = ft_str_join_free(tmp,TMPS,2);
			apply_width(e);
		}
		else
		{
			get_more_width(e);
			apply_width(e);
			apply_hex_zero(e,tmp);
		}
	}
	else
		apply_width(e);
	add_str(e,TMPS);
	free(tmp);
}

void apply_hex_big(E)
{
	unsigned int value;

	value = va_arg(ARGS,unsigned int);
	if (value == 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base(value,16);
	e->bigx = 'X';
	apply_hex_final(e);
}

void apply_hex_short(E)
{
	unsigned int value;

	value = va_arg(ARGS,unsigned int);
	if (value == 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base(value,16);
	ft_strtolower(TMPS);
	e->bigx = 'x';
	apply_hex_final(e);
}
