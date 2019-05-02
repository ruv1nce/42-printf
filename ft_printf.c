#include "ft_printf.h"

void		writer(char *s, int i, t_options *opt)
{
	opt->cnt += i;
	write(1, s, i);
}

static void	init_makers(makers *maker)
{
	maker['i'] = make_i;
	maker['d'] = make_i;
	maker['u'] = make_u;
	maker['o'] = make_u;
	maker['x'] = make_u;
	maker['X'] = make_u;
	maker['p'] = make_u;
	maker['c'] = make_s;
	maker['s'] = make_s;
	maker['%'] = make_s;
	maker['b'] = make_u;
	maker['f'] = make_feg;
	maker['e'] = make_feg;
	maker['g'] = make_feg;
}

static void	init_printers(printers *printer)
{
	printer['c'] = print_s;
	printer['s'] = print_s;
	printer['%'] = print_s;
	printer['i'] = print_i;
	printer['d'] = print_i;
	printer['u'] = print_i;
	printer['o'] = print_i;
	printer['x'] = print_i;
	printer['X'] = print_i;
	printer['p'] = print_i;
	printer['b'] = print_i;
	printer['f'] = print_feg;
	printer['e'] = print_feg;
	printer['g'] = print_feg;
}

void		iterator(char *format, t_options *opt, va_list ap)
{
	makers		maker[121];
	printers	printer[121];
	char		*str;

	init_makers(maker);
	init_printers(printer);
	while (*format)
	{
		if (*format == '%')
		{
			erase_opt(opt);
			parser(&format, opt, ap);
			if ((str = maker[opt->spec](ap, opt)))
			{
				printer[opt->spec](str, opt);
				free(str);
			}
		}
		else
			writer(format, 1, opt);
		format++;
	}
}

int			ft_printf(char *format, ...)
{
	va_list		ap;
	t_options	opt;

	opt.cnt = 0;
	va_start(ap, format);
	if (!(validator(format)))
		return (0);
	iterator(format, &opt, ap);
	va_end(ap);
	return (opt.cnt);
}
