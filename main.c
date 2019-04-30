/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfonarev <dfonarev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 02:13:24 by dfonarev          #+#    #+#             */
/*   Updated: 2019/04/29 23:13:02 by dfonarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		i;
	int		prec;
	int		nonprint;
	int		j;
	int		k;
	unsigned int u;
	long	l;
	unsigned long	ul;
	long long ll;
	unsigned long long ull;
	double	d;
	// char	*s = "fucko";
	// char	*ss = NULL;

	i = 75;
	u = 111;
	prec = 5;
	nonprint = 15;
	j = -75;
	k = 500111222;
	i = 75;
	l = -5123123123;
	ul = 5123123123;
	ll = -9223372036854775807;
	ull = 18446744073709551615U;
	d = 15.69;

	/* char, string, % */
	// ft_printf("%s\n", s);
	// ft_printf("%5.4s\n", s);
	// ft_printf("%s\n", ss);
	// ft_printf("%5c\n", i);
	ft_printf("%c\n", 0);
	// ft_printf("%-5%\n");
	// printf("%5.4s\n",s);
	// printf("%s\n", ss);
	// printf("%5c\n", i);
	// printf("%-5%\n");

	/* int lengths */
	// ft_printf("%i%i%li%lli", i, j, l, ll);
	// printf("\n");
	// ft_printf("%u%lu%llu", u, ul, ull);
	// printf("\n");
	// ft_printf("%o%lo%llo", u, ul, ull);
	// printf("\n");
	// ft_printf("%x%lx%llx", u, ul, ull);
	// printf("\n");
	// ft_printf("%X%lX%llX", u, ul, ull);
	// printf("\n");

	/* i/d options */
	// ft_printf("ft %d\n", 5555);
	// ft_printf("ft %9d\n", 5555);
	// ft_printf("ft %09i\n", i);
	// ft_printf("ft %-9i\n", i);
	// ft_printf("ft %-09i\n", i); // 0 is ignored
	// ft_printf("ft %+i\n", i);
	// ft_printf("ft % i\n", i);
	// ft_printf("ft % +i\n", i); // ' ' is ignored
	// ft_printf("ft % 9i\n", i);
	// ft_printf("ft % -9i\n", i);
	// ft_printf("ft % 09i\n", i);
	// ft_printf("ft %.*i\n", prec, i);
	// ft_printf("ft %37.*i\n", prec, i);
	// ft_printf("ft %037.*i\n", prec, i);
	// ft_printf("ft %-39.*i\n", prec, i);
	// ft_printf("ft %-039.*i\n", prec, i); // 0 is ignored
	// ft_printf("ft %+.*i\n", prec, i);
	// ft_printf("ft % .*i\n", prec, i);
	// ft_printf("ft % +.*i\n", prec, i); // ' ' is ignored
	// ft_printf("ft % 39.*i\n", prec, i);
	// ft_printf("ft % -39.*i\n", prec, i);
	// ft_printf("ft % 039.*i\n", prec, i);
	// int r = 0;
	// ft_printf("%2i ft %o\n", ++r, u);
	// ft_printf("%2i ft %#o\n", ++r, u);
	// ft_printf("%2i ft %9o\n", ++r, u);
	// ft_printf("%2i ft %#9o\n", ++r, u);
	// ft_printf("%2i ft %09o\n", ++r, u);
	// ft_printf("%2i ft %#09o\n", ++r, u);
	// ft_printf("%2i ft %-9o\n", ++r, u);
	// ft_printf("%2i ft %#-9o\n", ++r, u);
	// ft_printf("%2i ft %.o\n", ++r, u);
	// ft_printf("%2i ft %#.o\n", ++r, u);
	// ft_printf("%2i ft %.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %9.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#9.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %09.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#09.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %-9.*o\n", ++r, prec, u);
	// ft_printf("%2i ft %#-9.*o\n", ++r, prec, u);
	// ft_printf("\n");
	// r = 0;
	// printf("%2i lc %o\n", ++r, u);
	// printf("%2i lc %#o\n", ++r, u);
	// printf("%2i lc %9o\n", ++r, u);
	// printf("%2i lc %#9o\n", ++r, u);
	// printf("%2i lc %09o\n", ++r, u);
	// printf("%2i lc %#09o\n", ++r, u);
	// printf("%2i lc %-9o\n", ++r, u);
	// printf("%2i lc %#-9o\n", ++r, u);
	// printf("%2i lc %.o\n", ++r, u);
	// printf("%2i lc %#.o\n", ++r, u);
	// printf("%2i lc %.*o\n", ++r, prec, u);
	// printf("%2i lc %#.*o\n", ++r, prec, u);
	// printf("%2i lc %9.*o\n", ++r, prec, u);
	// printf("%2i lc %#9.*o\n", ++r, prec, u);
	// printf("%2i lc %09.*o\n", ++r, prec, u);
	// printf("%2i lc %#09.*o\n", ++r, prec, u);
	// printf("%2i lc %-9.*o\n", ++r, prec, u);
	// printf("%2i lc %#-9.*o\n", ++r, prec, u);




	// printf("\n");
	// ft_printf("ft %i\n", j);
	// ft_printf("ft %0i\n", j);
	// ft_printf("ft %9i\n", j);
	// ft_printf("ft %09i\n", j);
	// ft_printf("ft %-9i\n", j);
	// ft_printf("\n");
		// ft_printf("%+i\n", j);
		// ft_printf("% i\n", j);
		// ft_printf("%.8i\n", j);
		// ft_printf("%7.8i\n", j);
	// printf("lc %i\n", j);
	// printf("lc %0i\n", j);
	// printf("lc %9i\n", j);
	// printf("lc %09i\n", j);
	// printf("lc %-9i\n", j);
		// printf("%+i\n", j);
		// printf("% i\n", j);
		// printf("%.8i\n", j);
		// printf("%7.8i\n", j);

	// printf("%lu\n", 125L);

	/* string options */
	// ft_printf("%s\n", s);
	// ft_printf("%10s\n", s);
	// ft_printf("%-10s\n", s);
	// ft_printf("%.2s\n", s);
	// ft_printf("%10.2s\n", s);
	// ft_printf("%-10.2s\n", s);
	// ft_printf("\n");
	// printf("%s\n", s);
	// printf("%10s\n", s);
	// printf("%-10s\n", s);
	// printf("%.2s\n", s);
	// printf("%10.2s\n", s);
	// printf("%-10.2s\n", s);

	/* char options */
	// ft_printf("%c\n", i);
	// ft_printf("%10c\n", nonprint);
	// ft_printf("%10c\n", i);
	// ft_printf("%-9c\n", i);
	// ft_printf("%lc\n", i);
	// ft_printf("\n");
	// printf("%c\n", i);
	// printf("%10c\n", nonprint);
	// printf("%10c\n", i);
	// printf("%-9c\n", i);
	// printf("%lc\n", i);

	/* float options */
	// printf("%f\n", d);
	// printf("%#f\n", d);
	// printf("%0f\n", d);
	// printf("%15f\n", d);
	// printf("%015f\n", d);
	// printf("%-15f\n", d);
	// printf("%+f\n", d);
	// printf("% f\n", d);
	// printf("%.12f\n", d);
	// printf("%30.12f\n", d);
	// printf("%030.12f\n", d);
	// printf("%-30.12f\n", d);

	/* exp options */
	// printf("%e\n", d);
	// printf("%.10e\n", d);


	// ft_printf("%*.*c\n", 33, 44, i);
	// printf("%*.*i\n", 10, 5, i);
	// printf("%1$*3$.*1$i, %2$*1$i, %3$*2$i\n", 10, 5, i);
	// ft_printf("%*.*i\n", 10, 5, i);

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
