#include "ft_printf.h"

long double	ft_pow_pos_dbl(int x, int pow)
{
	long double	res;

	if (pow < 0)
		return (0);
	else if (pow == 0)
		res = 1;
	else
	{
		res = 1;
		while (pow--)
			res *= x;
	}
	return (res);
}

uint64_t	ft_pow_pos(int x, int pow)
{
	uint64_t	res;

	if (pow < 0)
		return (0);
	else if (pow == 0)
		res = 1;
	else
	{
		res = 1;
		while (pow--)
			res *= x;
	}
	return (res);
}

uint64_t	rounder(long double *num, long double tmp, int prec)
{
	uint64_t	tail;
	long double	dec;

	tmp -= (uint64_t)tmp;
	dec = ft_pow_pos(10, prec);
	tmp *= dec;
	tmp += 0.5;
	tail = tmp;
	if (tail / dec >= 1)
	{
		tail = 0;
		*num += 1;
	}
	return (tail);
}

static int					dotmover(long double num)
{
	int		mov;

	mov = 0;
	if (num < 1)
	{
		while (num < 1)
		{
			num *= 10;
			mov++;
		}
	}
	else if (num >= 1)
	{
		while (num >= 10)
		{
			num /= 10;
			mov--;
		}
	}
	else
		mov = 0;
	return (mov);
}

static char	*prune(char *s, t_options *opt)
{
	int		len;
	int		wholeprec;

	if (opt->prun == 1)
	{
		len = ft_strlen(s);
		wholeprec = len - opt->prec - 1;
		while (s[--len] == '0' && len > wholeprec)
		{
			s[len] = '\0';
			opt->prec--;
		}
	}
	return (s);
}


static char					*make_f(long double num, t_options *opt)
{
	uint64_t	tail;
	int			tmp;
	char		*s;
	char		*t1;
	char		*t2;

	tail = rounder(&num, num, opt->prec);
	t1 = ft_itoa_base_u((uint64_t)num, 10, 0);
	t2 = ft_strnew(opt->prec);
	tmp = opt->prec;
	while (--tmp >= 0)
	{
		t2[tmp] = tail % 10 + '0';
		tail /= 10;
	}
	t2 = prune(t2, opt);
	s = ft_strjoin(t1, t2);
	free (t1);
	free (t2);
	return (s);
}

static char					*make_e(long double num, t_options *opt)
{
	char	*s;
	char	*t1;
	char	t2[5];
	int		mov;

	mov = dotmover(num);
	num = (mov >= 0) ? num * ft_pow_pos(10, mov) : num / ft_pow_pos(10, -mov);
	t1 = make_f(num, opt);
	t1[opt->prec + 1] = '\0';
	t2[0] = 'e';
	t2[1] = (mov > 0) ? '-' : '+';
	mov = mov < 0 ? -mov : mov;
	t2[2] = mov / 10 + '0';
	t2[3] = mov % 10 + '0';
	t2[4] = '\0';
	s = ft_strjoin(t1, t2);
	free(t1);
	return (s);
}

static char					*make_g(long double num, t_options *opt)
{
	int		mov;
	char	*s;

	mov = dotmover(num);
	// opt->prec = (opt->prec == 0) ? 0 : 6;
	if (-mov < opt->prec && -mov >= -4)
	{
		opt->prec = (opt->prec == 0) ? 0 : opt->prec + mov - 1;
		opt->spec = 'f';
		s = make_f(num, opt);
	}
	else
	{
		opt->prec = (opt->prec == 0) ? 0 : opt->prec - 1;
		opt->spec = 'e';
		s = make_e(num, opt);
	}
	return (s);
}

char						*make_feg(va_list ap, t_options *opt)
{
	long double	num;
	char		*s;

	num = (opt->len == 5) ? va_arg(ap, long double) : va_arg(ap, double);
	if (num < 0 || num == DBL_NZERO)
	{
		opt->sign = '-';
		num *= -1;
	}
	// if (DBL_SPECIAL(num))
	opt->prec = (opt->prec == -1) ? 6 : opt->prec;
	if (opt->spec == 'f')
		s = make_f(num, opt);
	else if (opt->spec == 'e')
		s = make_e(num, opt);
	else
		s = make_g(num, opt);
	return (s);
}
