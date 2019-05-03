#include "ft_printf.h"

static char	*apo_string(char *s, int len)
{
	int		i;
	char	*s2;
	char	*s2start;

	s += len - 1;
	len += ((len % 3)) ? len / 3 : len / 3 - 1;
	if (!(s2start = ft_strnew(len)))
		return (NULL);
	s2 = s2start + len;
	i = 0;
	while (--s2 >= s2start && ++i)
	{
		if (i == 4)
		{
			*s2 = '\'';
			i = 0;
		}
		else
		{
			*s2 = *s;
			s--;
		}
	}
	free(++s);
	return (++s2);
}

char		*add_apo(char *s, t_options *opt)
{
	if (opt->apo && (elf(opt->spec) == 10))
		s = apo_string(s, ft_strlen(s));
	return (s);
}

void		erase_opt(t_options *opt)
{
	opt->width = 0;
	opt->prec = -1;
	opt->pad = ' ';
	opt->right = 0;
	opt->hash = 0;
	opt->len = 0;
	opt->apo = 0;
	opt->spec = 0;
	opt->prun = 0;
	opt->base = 0;
	opt->sign = 0;
}

void		pointer_opt(t_options *opt)
{
	opt->pad = ' ';
	opt->hash = 1;
	opt->len = 3;
	opt->apo = 0;
	opt->base = 16;
	opt->sign = 0;
}

int			validator(char *format, char *tmp, int spec_found)
{
	format--;
	while (*(++format))
	{
		if (*format == '%')
		{
			tmp = format;
			spec_found = 0;
			while (*(++tmp))
			{
				if (elf(*tmp) >= 10)
				{
					spec_found = 1;
					format = tmp;
					break ;
				}
				else if (elf(*tmp) == -10 && !(NUM(*tmp)) && *tmp != '*'
						&& *tmp != '.')
					return (0);
			}
			if (!spec_found)
				return (0);
		}
	}
	return (1);
}
