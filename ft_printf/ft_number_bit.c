/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:16:47 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:17:24 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number_bit(unsigned long long number, int base)
{
	int	bit;

	bit = 0;
	while (number || bit == 0)
	{
		bit++;
		number /= base;
	}
	return (bit);
}
