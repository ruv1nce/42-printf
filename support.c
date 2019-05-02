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
	if (opt->apo && (opt->spec == 'i' || opt->spec == 'd' || opt->spec == 'u'))
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
	opt->prec = -1;
	opt->pad = ' ';
	opt->hash = 1;
	opt->len = 3;
	opt->apo = 0;
	opt->base = 16;
	opt->sign = 0;
}

void		print_opt(t_options *opt)//
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

int			validator(char *format)
{
	char	*tmp;
	int		spec_found;

	while (*format)
	{
		if (*format == '%')
		{
			tmp = ++format;
			spec_found = 0;
			while (*tmp)
			{
				if (SPEC(*tmp))
				{
					spec_found = 1;
					format = tmp;
					break ;
				}
				tmp++;
			}
			if (!spec_found)
				return (0);
		}
		format++;
	}
	return (1);
}
