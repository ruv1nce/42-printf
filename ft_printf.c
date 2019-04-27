#include "ft_printf.h"

void	erase_opt(t_options *opt)
{
	opt->width = 0;
	opt->pad = 0;
	opt->prec = -1;
	opt->pos = 0;
	opt->hash = 0;
	opt->len = 0;
	opt->apo = 0;
	opt->spec = 0;
}

void	print_opt(t_options *opt)
{
	printf("width %i\n", opt->width);
	printf("pad  %i\n", opt->pad);
	printf("prec %i\n", opt->prec);
	printf("pos  %i\n", opt->pos);
	printf("hash %i\n", opt->hash);
	printf("len  %i\n", opt->len);
	printf("apo  %i\n", opt->apo);
	printf("spec %i\n", opt->spec);
	printf("\n");
}

int		ft_printf(char *format, ...)
{
	va_list			ap;
	t_options		opt;
	const handlers handler[121] = {['c'] = print_c, ['s'] = print_s};
	// ['i'] = print_i, ['o'] = print_o, ['u'] = print_u, ['x'] = print_x, ['X'] = print_x, ['f'] = print_f, ['e'] = print_f, ['g'] = print_f

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			erase_opt(&opt);
			if (*(format + 1) == '%')
			{
				write(1, "%", 1);
				format++;
			}
			else
			{
				parser(&format, &opt, ap);
				// print_opt(&opt);
				handler[opt.spec](ap, &opt);
			}
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}
