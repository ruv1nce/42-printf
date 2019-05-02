#include "ft_printf.h"

int			elf(char x)
{
	if (x == '#' || x == '0' || x == '-' || x == '+' || x == ' ' || x == '\'')
		return (1);
	else if (x >= '0' && x <= '9')
		return (0);
	else if (x == 'd' || x == 'i' || x == 'u' || x == 'f' || x == 'e' \
			|| x == 'g')
		return (10);
	else if (x == 'c' || x == 's' || x == 'o' || x == 'x' || x == 'X' \
			|| x == 'p' || x == '%' || x == 'b')
		return (11);
	else if (x == 'F' || x == 'E' || x == 'G')
		return (100);
	else if (x == 'h' || x == 'l' || x == 'L')
		return (-1);
	else
		return (-10);
}

uint64_t	ft_pow_pos(int x, int pow)
{
	uint64_t	res;

	if (pow < 0)
		return (0);
	else if (pow == 0)
		res = 1;
	else
	{
		res = 1;
		while (pow--)
			res *= x;
	}
	return (res);
}

uint64_t	rounder(long double *num, long double tmp, int prec)
{
	uint64_t	tail;
	long double	dec;

	tmp -= (uint64_t)tmp;
	dec = ft_pow_pos(10, prec);
	tmp *= dec;
	tmp += 0.5;
	tail = tmp;
	if (tail / dec >= 1)
	{
		tail = 0;
		*num += 1;
	}
	return (tail);
}

int			dotmover(long double num)
{
	int		mov;

	mov = 0;
	if (num < 1 && num)
	{
		while (num < 1)
		{
			num *= 10;
			mov++;
		}
	}
	else if (num >= 1)
	{
		while (num >= 10)
		{
			num /= 10;
			mov--;
		}
	}
	else
		mov = 0;
	return (mov);
}

char		*prune(char *s, t_options *opt)
{
	int		len;
	int		wholeprec;

	if (opt->prun == 1)
	{
		len = ft_strlen(s);
		wholeprec = len - opt->prec - 1;
		while (s[--len] == '0' && len > wholeprec)
		{
			s[len] = '\0';
			opt->prec--;
		}
	}
	return (s);
}
