#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define FLAG(x) x == '#' || x == '0' || x == '-' || x == '+' || x == ' ' || x == '\''
# define NUM(x) x >= '0' && x <= '9'
# define LEN(x) x == 'h' || x == 'l' || x == 'L'
# define SPEC(x) x == 'c' || x =='s' || x == 'd' || x == 'i' || x == 'o' || x == 'u' || x == 'x' || x == 'X' || x == 'f' || x == 'p'

/*
** VALID OPTIONS VALUES:
** width: > 0;
** pad: 1 - zero padding, 2 - right padding;
** prec: 0 <> n;
** pos: 1 - '+', 2 - <space>;
** hash: 1 - true;
** length: 1 - hh, 2 - h, 3 - l, 4 - ll, 5 - L;
** apo: 1 - true;
** spec: csiouxXfp;
*/

typedef struct s_options
{
	int				width;
	int				pad;
	int				prec;
	int				pos;
	int				hash;
	int				len;
	unsigned char	apo;
	unsigned char	spec;
}					t_options;

typedef void (*handlers)(va_list, t_options *);

int		ft_printf(char *format, ...);
void	parser(char **format, t_options *opt, va_list ap);
void	print_c(va_list ap, t_options *opt);
void	print_s(va_list ap, t_options *opt);
void	print_i(va_list ap, t_options *opt);
void	print_o(va_list ap, t_options *opt);
void	print_u(va_list ap, t_options *opt);
void	print_x(va_list ap, t_options *opt);

#endif
