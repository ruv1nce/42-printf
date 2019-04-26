#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_options
{
	int		padding;
	int		width;
	int		zero_pad;
	int		precision;
	int		positive;
	int		hash;
	int		length;
	char	spec;
}			t_options;

typedef void (*handlers)(va_list, t_options *);

int	ft_printf(char *format, ...);

#endif
