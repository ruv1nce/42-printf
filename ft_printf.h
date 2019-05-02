#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

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

typedef struct		s_options
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

typedef char		*(*t_makers)(va_list ap, t_options*);
typedef void		(*t_printers)(char*, t_options*);

int					ft_printf(char *format, ...);
void				writer(char *s, int i, t_options *opt);
int					validator(char *format);
void				parser(char **format, t_options *opt, va_list ap);
int					elf(char x);
char				*make_i(va_list ap, t_options *opt);
char				*make_u(va_list ap, t_options *opt);
char				*make_s(va_list ap, t_options *opt);
char				*make_feg(va_list ap, t_options *opt);
void				print_s(char *s, t_options *opt);
void				print_i(char *s, t_options *opt);
void				print_feg(char *s, t_options *opt);
void				erase_opt(t_options *opt);
void				pointer_opt(t_options *opt);
char				*add_apo(char *s, t_options *opt);
uint64_t			ft_pow_pos(int x, int pow);
uint64_t			rounder(long double *num, long double tmp, int prec);
int					dotmover(long double num);
char				*prune(char *s, t_options *opt);

#endif
