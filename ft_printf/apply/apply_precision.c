#include "../ft_printf.h"

static void apply_prec_final(E)
{
	char *strmore;

	if (e->final_prec > 0)
	{
		strmore = ft_strnew(e->final_prec);
		strmore = ft_memset(strmore,'0',e->final_prec);
		TMPS = ft_str_join_free(strmore,TMPS,2);
		free(strmore);
	}
	if (e->precision > 0)
		e->fl_zero = ' ';
}

void apply_precision(E)
{
	if (e->precision == 0)
		if (TMPS[0] == '0')
			TMPS[0] = 0;
	get_more_prec(e);
	if (TMPS[0] == '-')
	{
		e->final_prec++;
		apply_prec_final(e);
		TMPS[e->final_prec] = '0';
		TMPS[0] = '-';
		e->final_prec--;
	}
	else
		apply_prec_final(e);
}

void apply_precision_str(E)
{
	if (ft_strlen(TMPS) > e->precision)
	{
		TMPS[e->precision] = 0;
	}
}
