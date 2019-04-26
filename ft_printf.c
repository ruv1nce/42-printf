#include "ft_printf.h"

void	print_c(va_list ap, t_options *opt)
{
	char	c;

	opt->spec = '@';
	c = va_arg(ap, int);
	write(1, &c, 1);
}

char	parser(char **format, t_options *opt)
{
	if (**format == 'c')
	{
		opt->spec = 'c';
		return ('c');
	}
	return ('@');
}

int		ft_printf(char *format, ...)
{
	va_list			ap;
	t_options		opt;
	unsigned char	spec;
	const handlers handler[121] = {['c'] = print_c};
	//, ['s'] = print_s, ['d'] = print_i, ['i'] = print_i};

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			spec = parser(&format, &opt);
			handler[spec](ap, &opt);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}
