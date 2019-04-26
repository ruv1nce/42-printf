#include "ft_printf.h"

int	main(void)
{
	int		i;
	int		j;
	long long l;
	unsigned long long ul;
	double	d;
	// char	*s = "fuckfuck";

	i = 75;
	j = -75;
	l = 9223372036854775807;
	ul = 18446744073709551615ULL;
	d = 15.69;
	// printf("--simple stuff--\n");
	// printf("text\n");
	// printf("%c\n", 'Z');
	// printf("%c\n", i);

	// ft_printf("dude %% %c dude %c\n", '$', i);
	ft_printf("%#0+5.5hhc\n", i);
	ft_printf("%- 8.7hc\n", i);
	ft_printf("%0.llc\n", i);
	ft_printf("%lc\n", i);
	ft_printf("%Lc\n", i);


	// printf("%p\n", &i);
	// printf("\n");
	// printf("%s\n", s);
	// printf("%i\n", i);
	// printf("%o\n", i);
	// printf("%u\n", i);
	// printf("%x\n", i);
 	// printf("%#x\n", i);
 	// printf("%##x\n", i);
	// printf("%X\n", i);
	// printf("%f\n", d);
	// printf("\n");

	// printf("--specified precision--\n");
	// printf("%.4s\n", s);
	// printf("%.4i\n", i);
	// printf("%.4o\n", i);
	// printf("%.4u\n", i);
	// printf("%.4x\n", i);
	// printf("%.4X\n", i);
	// printf("%.4f\n", d);
	// printf("\n");

	// printf("--unspecified precision--\n");
	// printf("%.s\n", s);
	// printf("%.i\n", i);
	// printf("%.o\n", i);
	// printf("%.u\n", i);
	// printf("%.x\n", i);
	// printf("%.X\n", i);
	// printf("%.f\n", d);
	// printf("%.0f\n", d);

	// printf("--positive padding--\n");
	// printf("%14s\n", s);
	// printf("%14i\n", i);
	// printf("%0i\n", i);
	// printf("%i\n", i);
	// printf("%14o\n", i);
	// printf("%14u\n", i);
	// printf("%14x\n", i);
	// printf("%14X\n", i);
	// printf("%14f\n", d);
	// printf("\n");

	// printf("--negative padding--\n");
	// printf("%-14s\n", s);
	// printf("%-14i\n", i);
	// printf("%-14o\n", i);
	// printf("%-14u\n", i);
	// printf("%-14x\n", i);
	// printf("%-14X\n", i);
	// printf("%-14f\n", d);
	// printf("\n");

	// printf("--positive padding with 0--\n");
	// printf("%014i\n", i);
	// printf("%014o\n", i);
	// printf("%014u\n", i);
	// printf("%014x\n", i);
	// printf("%014X\n", i);
	// printf("%014f\n", d);
	// printf("\n");

	// printf("-- space and + --\n");
	// printf("%i\n", i);
	// printf("%i\n", j);
	// printf("% i\n", i);
	// printf("% i\n", j);
	// printf("%+i\n", i);
	// printf("%+i\n", j);
	// printf("\n");

	// printf("-- # --\n");
	// printf("%o\n", i);
	// printf("%#o\n", i);
	// printf("%o\n", j);
	// printf("%#o\n", j);
	// printf("%x\n", i);
	// printf("%#x\n", i);
	// printf("%x\n", j);
	// printf("%#x\n", j);
	// printf("%.f\n", d);
	// printf("%#.f\n", d);
	// printf("\n");

	// printf("-- lengths: hh & h --\n");
	// printf("%hhi\n", (char)255);
	// printf("%hhu\n", (unsigned char)255);
	// printf("%hi\n", (short)255);
	// printf("-- lengths: ll --\n");
	// printf("%lli\n", l);
	// printf("-- lengths: ull --\n");
	// printf("%llu\n", ul);
	// printf("\n");
}
