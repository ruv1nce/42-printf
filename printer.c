#include "ft_printf.h"

void		print_s(char *s, t_options *opt)
{
	int		len;

	len = (opt->spec == 's') ? ft_strlen(s) : 1;
	if (opt->spec == 's' && opt->prec >= 0 && opt->prec < len)
		len = opt->prec;
	while (!opt->right && --opt->width >= len)
	{
		if (opt->spec == '%')
			writer(&opt->pad, 1, opt);
		else
			writer(" ", 1, opt);
	}
	if (opt->spec == 'c' || opt->spec == '%')
		writer(&s[0], 1, opt);
	else
		writer(s, len, opt);
	while (opt->right && --opt->width >= len)
		writer(" ", 1, opt);
}

static void	process_i_options(t_options *opt, int *len, int *prelen)
{
	if (opt->hash && (opt->spec == 'o'))
	{
		opt->width--;
		if (opt->prec > 0)
			opt->prec--;
	}
	else if (opt->hash && (opt->spec == 'x' || opt->spec == 'X'
				|| opt->spec == 'p'))
		opt->width -= 2;
	if (opt->sign && (opt->spec == 'i' || opt->spec == 'd'))
		opt->width--;
	if (opt->prec > *len)
		*prelen += opt->prec - *len;
	else if (opt->prec < 0 && !opt->right && opt->pad == '0'
			&& opt->width > *len + *prelen)
		*prelen += opt->width - *len;
	opt->width -= *prelen;
}

void		print_i(char *s, t_options *opt)
{
	int	len;
	int	prelen;

	len = ft_strlen(s);
	prelen = 0;
	process_i_options(opt, &len, &prelen);
	while (!opt->right && --opt->width >= len)
		writer(" ", 1, opt);
	if (opt->sign && (opt->spec == 'i' || opt->spec == 'd'))
		writer(&opt->sign, 1, opt);
	if (opt->hash && (opt->spec == 'o'))
		writer("0", 1, opt);
	if (opt->hash && (opt->spec == 'x' || opt->spec == 'p'))
		writer("0x", 2, opt);
	if (opt->hash && (opt->spec == 'X'))
		writer("0X", 2, opt);
	while (--prelen >= 0)
		writer("0", 1, opt);
	writer(s, len, opt);
	while (opt->right && --opt->width >= len)
		writer(" ", 1, opt);
}

void		print_feg(char *s, t_options *opt)
{
	int	len;

	len = ft_strlen(s);
	opt->width = (opt->hash || opt->prec) ? opt->width - 1 : opt->width;
	opt->width = (opt->sign) ? opt->width - 1 : opt->width;
	while (!opt->right && opt->pad == ' ' && --opt->width >= len)
		writer(" ", 1, opt);
	if (opt->sign)
		writer(&opt->sign, 1, opt);
	while (!opt->right && opt->pad == '0' && --opt->width >= len)
		writer("0", 1, opt);
	if (opt->spec == 'f')
		writer(s, len - opt->prec, opt);
	else
		writer(s, 1, opt);
	if (opt->hash || opt->prec)
		writer(".", 1, opt);
	if (opt->spec == 'f')
		writer(s + len - opt->prec, opt->prec, opt);
	else
		writer(s + 1, 4 + opt->prec, opt);
	while (opt->right && --opt->width >= len)
		writer(" ", 1, opt);
}
