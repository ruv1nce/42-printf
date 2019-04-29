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
	if (NUM(**format))
	{
		opt->width = ft_atoi(*format);
		while (NUM(**format))
			(*format)++;
		(*format)--;
	}
	else if (**format == '*')
		opt->width = va_arg(ap, int);
	if (**format == '.')
	{
		opt->prec = 0;
		if (NUM(*(*format) + 1))
		{
			(*format)++;
			opt->prec = ft_atoi(*format);
			while (NUM(**format))
				(*format)++;
			(*format)--;
		}
		else if (*(++(*format)) == '*')
			opt->prec = va_arg(ap, int);
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
	if (DECIMAL(spec))
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
	while (**format)
	{
		(*format)++;
		if (FLAG(**format))
			save_flag(format, opt);
		else if ((NUM(**format)) || **format == '.' || **format == '*')
			save_widthprec(format, opt, ap);
		else if (LEN(**format))
			save_len(format, opt);
		else if (SPEC(**format))
		{
			opt->spec = **format;
			save_base(opt->spec, opt);
			break ;
		}
	}
}
