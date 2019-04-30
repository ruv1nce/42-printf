/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfonarev <dfonarev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 01:45:04 by dfonarev          #+#    #+#             */
/*   Updated: 2019/04/27 01:45:04 by dfonarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	//killme
#include "libft.h"

static char	*zero_string(void)
{
	char	*str;

	if (!(str = malloc(2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

/*
** mode = 0: lowercase letters;
** mode = 1: uppercase letters
**
** check for negative numbers and base != 10 ???
*/

char		*ft_itoa_base_u(unsigned long long value, int base, int mode)
{
	int					len;
	const char			sym[] = "0123456789abcdef";
	char				*str;

	if (!value)
		return (zero_string());
	len = ft_numlen(value, base);
	str = ft_strnew(len);
	while (--len >= 0)
	{
		if (sym[value % base] >= '0' && sym[value % base] <= '9')
			str[len] = sym[value % base];
		else
			str[len] = sym[value % base] - (mode * 32);
		value /= base;
	}
	return (str);
}
