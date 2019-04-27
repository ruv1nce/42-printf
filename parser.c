#include "ft_printf.h"

static void	save_flag(char **format, t_options *opt)
{
	if (**format == '#')
		opt->hash = 1;
	else if (**format == '0' && !opt->pad)
		opt->pad = 1;
	else if (**format == '-')
		opt->pad = 2;
	else if (**format == '+')
		opt->pos = 1;
	else if (**format == ' ' && !opt->pos)
		opt->pos = 2;
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
		(*format)++;
		if (NUM(**format))
		{
			opt->prec = ft_atoi(*format);
			while (NUM(**format))
				(*format)++;
			(*format)--;
		}
		else if (**format == '*')
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
			break ;
		}
	}
}
