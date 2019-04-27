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

// void	print_num(va_list ap, t_options *opt)
// {
// 	long long			i;
// 	unsigned long long	u;
// 	char				*s;
// 	int					len;

// 	if (opt->spec == 'i' || opt->spec == 'd')
// 	{
// 		i = va_arg(ap, long long);
// 		s = ft_itoa_base(i, 10, 0);
// 	}
// 	else
// 	{
// 		u = va_arg(ap, unsigned long long);
// 		s = ft_itoa_base_u(u, opt->base, 0);
// 	}
// 	len = ft_strlen(s);
// }

void	print_i(va_list ap, t_options *opt)
{
	long long	i;
	char		*s;
	int			len;
	char		pad;

	if (opt->len == 3)
		i = va_arg(ap, long);
	else if (opt->len == 4)
		i = va_arg(ap, long long);
	else
		i = va_arg(ap, int);
	s = ft_itoa_base(i, 10, 0);
	len = ft_strlen(s);
	/* for '-' flag or no '0' flag: pad = ' ' */
	pad = (opt->pad == 2 || !opt->pad) ? ' ' : '0';
	/* no '-' flag */
	if (opt->pad == 1 && i < 0)
	{
		write(1, "-", 1);
		s++;
		len--;
		opt->width--;
	}
	while (opt->pad != 2 && --opt->width >= len)
	{
		write(1, &pad, 1);
	}
	write(1, s, len);
	while (opt->pad == 2 && --opt->width >= len)
		write(1, &pad, 1);

}
