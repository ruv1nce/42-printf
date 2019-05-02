#include "ft_printf.h"

static void	save_flag(char **format, t_options *opt)
{
	if (**format == '#')
		opt->hash = 1;
	else if (**format == '0' && !opt->right)
		opt->pad = '0';
	else if (**format == '-')
	{
		opt->right = 1;
		opt->pad = ' ';
	}
	else if (**format == '+')
		opt->sign = '+';
	else if (**format == ' ' && !opt->sign)
		opt->sign = ' ';
	else if (**format == '\'')
		opt->apo = 1;
}

static void	save_widthprec(char **format, t_options *opt, va_list ap)
{
	if (!(elf(**format)))
	{
		opt->width = ft_atoi(*format);
		while (!(elf(**format)) && !(elf(*(*format + 1))))
			(*format)++;
	}
	else if (**format == '*')
		opt->width = va_arg(ap, int);
	if (**format == '.')
	{
		opt->prec = 0;
		if (!(elf(*(*format + 1))))
		{
			(*format)++;
			opt->prec = ft_atoi(*format);
			while (!(elf(**format)) && !(elf(*(*format + 1))))
				(*format)++;
		}
		else if (*(*format + 1) == '*')
		{
			(*format)++;
			opt->prec = va_arg(ap, int);
		}
	}
}

static void	save_len(char **format, t_options *opt)
{
	if (**format == 'h')
	{
		if (*(*format + 1) == 'h')
		{
			opt->len = 1;
			(*format)++;
		}
		else
			opt->len = 2;
	}
	else if (**format == 'l')
	{
		if (*(*format + 1) == 'l')
		{
			opt->len = 4;
			(*format)++;
		}
		else
			opt->len = 3;
	}
	else if (**format == 'L')
		opt->len = 5;
}

static void	save_base(unsigned char spec, t_options *opt)
{
	if (elf(spec) == 10)
		opt->base = 10;
	else if (spec == 'o')
		opt->base = 8;
	else if (spec == 'x' || spec == 'X' || spec == 'p')
		opt->base = 16;
	else if (spec == 'b')
		opt->base = 2;
}

void		parser(char **format, t_options *opt, va_list ap)
{
	while (*(++*format))
	{
		if (elf(**format) == 1)
			save_flag(format, opt);
		else if (!(elf(**format)) || **format == '.' || **format == '*')
			save_widthprec(format, opt, ap);
		else if (elf(**format) == -1)
			save_len(format, opt);
		else if (elf(**format) >= 10)
		{
			opt->spec = **format;
			if (elf(opt->spec) == 100)
				opt->spec += 32;
			if (opt->spec == 'p')
				pointer_opt(opt);
			if (opt->spec == 'g')
				opt->prun = 1;
			save_base(opt->spec, opt);
			break ;
		}
	}
}
