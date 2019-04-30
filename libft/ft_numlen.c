/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfonarev <dfonarev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 01:00:56 by dfonarev          #+#    #+#             */
/*   Updated: 2019/04/27 01:00:56 by dfonarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(unsigned long long num, int base)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}
