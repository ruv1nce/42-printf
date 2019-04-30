#include "ft_printf.h"

static void	erase_opt(t_options *opt)
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

void		pointer_opt(t_options *opt)
{
	opt->prec = -1;
	opt->pad = ' ';
	opt->hash = 1;
	opt->len = 3;
	opt->apo = 0;
	opt->spec = 'x';
	opt->base = 16;
	opt->sign = 0;
}

void		writer(char *s, int i, t_options *opt)
{
	opt->cnt += i;
	write(1, s, i);
}

void		print_opt(t_options *opt)
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

int			ft_printf(char *format, ...)
{
	va_list			ap;
	t_options		opt;
	char			*str;
	const makers	maker[121] = {['i'] = make_i, ['d'] = make_i, ['u'] = make_u, ['o'] = make_u, ['x'] = make_u, ['X'] = make_u, ['p'] = make_u, ['c'] = make_s, ['s'] = make_s, ['%'] = make_s};
	const printers	printer[121] = {['c'] = print_s, ['s'] = print_s, ['%'] = print_s, ['i'] = print_i, ['d'] = print_i, ['u'] = print_i, ['o'] = print_i, ['x'] = print_i, ['X'] = print_i, ['p'] = print_i};

	opt.cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			erase_opt(&opt);
			parser(&format, &opt, ap);
			// print_opt(&opt);
			if ((str = maker[opt.spec](ap, &opt)))
			{
			// printf("string: %s\n", str);
				printer[opt.spec](str, &opt);
				free(str);
			}
		}
		else
			writer(format, 1, &opt);
		format++;
	}
	va_end(ap);
	return (opt.cnt);
}
