#include "ft_printf.h"

void		writer(char *s, int i, t_options *opt)
{
	opt->cnt += i;
	write(1, s, i);
}

static void	init_func_ptrs(makers *maker, printers *printer)
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
}

void		iterator(char *format, t_options *opt, va_list ap)
{
	makers		maker[121];
	printers	printer[121];
	char		*str;

	init_func_ptrs(maker, printer);
	while (*format)
	{
		if (*format == '%')
		{
			erase_opt(opt);
			parser(&format, opt, ap);
			// print_opt(&opt);
			if ((str = maker[opt->spec](ap, opt)))
			{
			// printf("string: %s\n", str);
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
	iterator(format, &opt, ap);
	va_end(ap);
	return (opt.cnt);
}
