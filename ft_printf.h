#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define FLAG(x) x == '#' || x == '0' || x == '-' || x == '+' || x == ' ' || x == '\''
# define NUM(x) x >= '0' && x <= '9'
# define LEN(x) x == 'h' || x == 'l' || x == 'L'
# define SPEC(x) x == 'c' || x =='s' || x == 'd' || x == 'i' || x == 'o' || x == 'u' || x == 'x' || x == 'X' || x == 'f' || x == 'p' || x == '%'
# define DECIMAL(x) x == 'd' || x == 'i' || x == 'u' || x == 'f' || x == 'e' || x == 'g'

/*
** VALID OPTIONS VALUES:
** width: > 0;
** prec: 0 <> n;
** pad: '0', ' ';
** right: 1 - true;
** hash: 1 - true;
** len: 1 - hh, 2 - h, 3 - l, 4 - ll, 5 - L;
** apo: 1 - true;
** spec: csiouxXfp%;
** base: 10, 8, 16, 2;
** sign: '+', '-';
** cnt: symbols printed (0 <> n);
*/

typedef struct s_options
{
	int				width;
	int				prec;
	char	pad;
	unsigned char	right;
	unsigned char	hash;
	unsigned char	len;
	unsigned char	apo;
	unsigned char	spec;
	unsigned char	base;
	char			sign;
	unsigned int	cnt;
}					t_options;

typedef char	*(*makers)(va_list, t_options *);
typedef void	(*printers)(char *, t_options *);

int		ft_printf(char *format, ...);
void	writer(char *s, int i, t_options *opt);
int		validator(char *format);
void	parser(char **format, t_options *opt, va_list ap);
char	*make_i(va_list ap, t_options *opt);
char	*make_u(va_list ap, t_options *opt);
char	*make_s(va_list ap, t_options *opt);
void	print_s(char *s, t_options *opt);
void	print_i(char *s, t_options *opt);
void	erase_opt(t_options *opt);
void	pointer_opt(t_options *opt);
void	print_opt(t_options *opt); //KILLME

#endif
