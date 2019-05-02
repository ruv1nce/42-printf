#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

# define FLAG(x) x == '#' || x == '0' || x == '-' || x == '+' || x == ' ' || x == '\''
# define NUM(x) x >= '0' && x <= '9'
# define LEN(x) x == 'h' || x == 'l' || x == 'L'
# define SPEC(x) x == 'c' || x =='s' || x == 'd' || x == 'i' || x == 'o' || x == 'u' || x == 'x' || x == 'X' || x == 'f' || x == 'p' || x == '%' || x =='b' || x == 'e' || x == 'g'
# define DECIMAL(x) x == 'd' || x == 'i' || x == 'u' || x == 'f' || x == 'e' || x == 'g'

# define DBL_INF	0x7FF0000000000000
# define DBL_NINF	0xFFF0000000000000
# define DBL_NAN	0x7FF0000000100000
# define DBL_PZERO	0x0000000000000000
# define DBL_NZERO	0x8000000000000000
# define LDBL_INF	0x7FFF0000000000000000L
# define LDBL_NINF	0xFFFF0000000000000000L
# define LDBL_NAN	0x7FFF0000000001000000L
# define LDBL_PZERO	0x00000000000000000000L
# define LDBL_NZERO	0x80000000000000000000L
# define DBL_SPECIAL(x) x == DBL_INF || x == DBL_NINF || x == DBL_NAN || x == DBL_PZERO || x == DBL_NZERO || x == LDBL_INF || x == LDBL_NINF || x == LDBL_NAN || x == LDBL_PZERO || x == LDBL_NZERO

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
** prun: 1 - true;
** base: 10, 8, 16, 2;
** sign: '+', '-';
** cnt: symbols printed (0 <> n);
*/

typedef struct s_options
{
	int				width;
	int				prec;
	char			pad;
	unsigned char	right;
	unsigned char	hash;
	unsigned char	len;
	char			apo;
	unsigned char	spec;
	unsigned char	prun;
	unsigned char	base;
	char			sign;
	unsigned int	cnt;
}					t_options;

typedef char	*(*makers)(va_list, t_options *);
typedef void	(*printers)(char *, t_options *);

int			ft_printf(char *format, ...);
void		writer(char *s, int i, t_options *opt);
int			validator(char *format);
void		parser(char **format, t_options *opt, va_list ap);
char		*make_i(va_list ap, t_options *opt);
char		*make_u(va_list ap, t_options *opt);
char		*make_s(va_list ap, t_options *opt);
char		*make_feg(va_list ap, t_options *opt);
void		print_s(char *s, t_options *opt);
void		print_i(char *s, t_options *opt);
void		print_feg(char *s, t_options *opt);
void		erase_opt(t_options *opt);
void		pointer_opt(t_options *opt);
char		*add_apo(char *s, t_options *opt);
uint64_t	ft_pow_pos(int x, int pow);
void		print_opt(t_options *opt); //KILLME

#endif
