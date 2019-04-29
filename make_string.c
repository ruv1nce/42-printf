#include "ft_printf.h"

/*
** for 's' spec we duplicate string so we can free it later
** like any other string created here
*/

char	*make_s(va_list ap, t_options *opt)
{
	char	*s;

	if (opt->spec == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else
	{
		if (!(s = ft_strnew(1)))
			return (NULL);
		if (opt->spec == '%')
			s[0] = '%';
		else
			s[0] = (char)va_arg(ap, int);
	}
	return (s);
}

char	*make_u(va_list ap, t_options *opt)
{
	if (opt->len == 3)
	{
		if (opt->spec == 'X')
			return (ft_itoa_base_u(va_arg(ap, unsigned long), opt->base, 1));
		else
			return (ft_itoa_base_u(va_arg(ap, unsigned long), opt->base, 0));
	}
	else if (opt->len == 4)
		if (opt->spec == 'X')
			return (ft_itoa_base_u(va_arg(ap, unsigned long long), opt->base, 1));
		else
			return (ft_itoa_base_u(va_arg(ap, unsigned long long), opt->base, 0));
	else
		if (opt->spec == 'X')
			return (ft_itoa_base_u(va_arg(ap, unsigned int), opt->base, 1));
		else
			return (ft_itoa_base_u(va_arg(ap, unsigned int), opt->base, 0));
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
