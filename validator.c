// check if format string is valid
// invalid cases:
//		"*5" ".5"

// state = 0 - все разрешено
// e.g. state = 3 - разрешены только length и spec

#include "ft_printf.h"

int		validator(char *format)
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
					format = tmp + 1;
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
