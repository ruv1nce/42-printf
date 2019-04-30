#include "ft_printf.h"

void	erase_opt(t_options *opt)
{
	opt->width = 0;
	opt->prec = -1;
	opt->pad = ' ';
	opt->right = 0;
	opt->hash = 0;
	opt->len = 0;
	opt->apo = 0;
	opt->spec = 0;
	opt->base = 0;
	opt->sign = 0;
}

void	pointer_opt(t_options *opt)
{
	opt->prec = -1;
	opt->pad = ' ';
	opt->hash = 1;
	opt->len = 3;
	opt->apo = 0;
	opt->spec = 'x';
	opt->base = 16;
	opt->sign = 0;
}

void	print_opt(t_options *opt)//
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
