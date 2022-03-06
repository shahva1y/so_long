/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numeral.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:05:39 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 15:05:55 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_numeral(unsigned long long quo, int *count,
						unsigned long long base, char digit)
{
	unsigned long long	rem;
	char				c;

	rem = quo % base;
	quo = quo / base;
	if (quo != 0)
		ft_print_numeral(quo, count, base, digit);
	if (rem < 10)
		c = '0' + rem;
	else
		c = digit + (rem - 10);
	(*count) += write(1, &c, 1);
}
