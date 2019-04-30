#include "ft_printf.h"

/*
** for 's' spec we duplicate string so we can free it later
** like any other string created here
*/

char	*make_s(va_list ap, t_options *opt)
{
	char	*s;

	if (opt->spec == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
		{
			writer("(null)", 6, opt);
			return (NULL);
		}
		else
			return (ft_strdup(s));
	}
	else
	{
		if (!(s = ft_strnew(1)))
			return (NULL);
		if (opt->spec == '%')
			s[0] = '%';
		else
			s[0] = va_arg(ap, int);
	}
	return (s);
}

char	*make_u(va_list ap, t_options *opt)
{
	unsigned long long	num;

	if (opt->len == 3)
		num = va_arg(ap, unsigned long);
	else if (opt->len == 4)
		num = va_arg(ap, unsigned long long);
	else
		num = va_arg(ap, unsigned int);
	if (opt->spec == 'o' && num == 0)
		opt->hash = 0;
	if (opt->spec == 'X')
		return (ft_itoa_base_u(num, opt->base, 1));
	else
		return (ft_itoa_base_u(num, opt->base, 0));
}

char	*make_i(va_list ap, t_options *opt)
{
	long long	num;

	if (opt->len == 3)
		num = va_arg(ap, long);
	else if (opt->len == 4)
		num = va_arg(ap, long long);
	else
		num = va_arg(ap, int);
	if (num < 0)
	{
		opt->sign = '-';
		num *= -1;
	}
	return (ft_itoa_base_u(num, 10, 0));
}
