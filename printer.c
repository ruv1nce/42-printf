#include "ft_printf.h"

void	print_c(va_list ap, t_options *opt)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	len = 1;
	/* no '-' flag */
	while (opt->pad != 2 && --opt->width >= len)
		write(1, " ", 1);
	write(1, &c, 1);
	while (opt->pad == 2 && --opt->width >= len)
		write(1, " ", 1);
}

void	print_s(va_list ap, t_options *opt)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (opt->prec >= 0 && opt->prec < len)
		len = opt->prec;
	/* no '-' flag */
	while (opt->pad != 2 && --opt->width >= len)
		write(1, " ", 1);
	write(1, s, len);
	while (opt->pad == 2 && --opt->width >= len)
		write(1, " ", 1);
}
