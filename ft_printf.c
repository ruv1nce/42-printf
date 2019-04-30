#include "ft_printf.h"

void	erase_opt(t_options *opt)
{
	opt->width = 0;
	opt->prec = -1;
	opt->pad = ' ';
	opt->right = 0;
	opt->hash = 0;
	opt->len = 0;
	opt->apo = 0;
	opt->spec = 0;
	opt->base = 0;
	opt->sign = 0;
}

void	print_opt(t_options *opt)
{
	printf("width %i\n", opt->width);
	printf("prec %i\n", opt->prec);
	printf("pad  %c\n", opt->pad);
	printf("right %i\n", opt->right);
	printf("hash %i\n", opt->hash);
	printf("len  %i\n", opt->len);
	printf("apo  %i\n", opt->apo);
	printf("spec %c\n", opt->spec);
	printf("base %i\n", opt->base);
	printf("sign %c\n", opt->sign);
	printf("\n");
}

int		ft_printf(char *format, ...)
{
	va_list			ap;
	t_options		opt;
	const makers	maker[121] = {['i'] = make_i, ['d'] = make_i, ['u'] = make_u, ['o'] = make_u, ['x'] = make_u, ['X'] = make_u, ['c'] = make_s, ['s'] = make_s, ['%'] = make_s};
	char			*str;
	const printers	printer[121] = {['c'] = print_s, ['s'] = print_s, ['%'] = print_s, ['i'] = print_i, ['d'] = print_i, ['u'] = print_i, ['o'] = print_i};
	// ['o'] = print_o,  ['x'] = print_x, ['X'] = print_x, ['f'] = print_f, ['e'] = print_f, ['g'] = print_f

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			erase_opt(&opt);
			parser(&format, &opt, ap);
			// print_opt(&opt);
			if (!(str = maker[opt.spec](ap, &opt)))
				return (0);
			// printf("string: %s\n", str);
			printer[opt.spec](str, &opt);
			free(str);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}
