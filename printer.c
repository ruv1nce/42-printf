#include "ft_printf.h"

// void	print_c(char *s, t_options *opt)
// {
// 	int		len;

// 	len = 1;
// 	/* no '-' flag */
// 	while (opt->pad != 2 && --opt->width >= len)
// 		write(1, " ", 1);
// 	write(1, s, 1);
// 	while (opt->pad == 2 && --opt->width >= len)
// 		write(1, " ", 1);
// }

void	print_s(char *s, t_options *opt)
{
	int		len;

	len = ft_strlen(s);
	// if (!len)
	// 	return ;
	if (opt->spec == 's' && opt->prec >= 0 && opt->prec < len)
		len = opt->prec;
	/* no '-' flag */
	while (opt->pad != 2 && --opt->width >= len)
		writer(" ", 1, opt);
	if (opt->spec == 'c')
		writer(&s[0], 1, opt);
	else
		writer(s, len, opt);
	while (opt->pad == 2 && --opt->width >= len)
		writer(" ", 1, opt);
}

void	print_i(char *s, t_options *opt)
{
	int	len;
	int	prelen;

	len = ft_strlen(s);
	prelen = 0;
	if (opt->hash && (opt->spec == 'o'))
	{
		opt->width--;
		if (opt->prec > 0)
			opt->prec--;
	}
	if (opt->sign && (opt->spec == 'i' || opt->spec == 'd'))
		opt->width--;
	if (opt->prec > len)
		prelen += opt->prec - len;
	else if (opt->prec == -1 && !opt->right && opt->pad == '0' && opt->width > len + prelen)
		prelen += opt->width - len;
	opt->width -= prelen;
	/* print */
	while (!opt->right && --opt->width >= len)
		writer(" ", 1, opt);
	if (opt->sign && (opt->spec == 'i' || opt->spec == 'd'))
		writer(&opt->sign, 1, opt);
	if (opt->hash && (opt->spec == 'o'))
		writer("0", 1, opt);
	while (--prelen >= 0)
		writer("0", 1, opt);
	writer(s, len, opt);
	while (opt->right && --opt->width >= len)
		writer(" ", 1, opt);
}
