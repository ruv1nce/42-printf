#include "ft_printf.h"

void	print_c(va_list ap, t_options *opt)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
}

void	print_s(va_list ap, t_options *opt)
{
	char	*s;

	s = va_arg(ap, char *);
	while (*s)
		write(1, s, 1);
}
