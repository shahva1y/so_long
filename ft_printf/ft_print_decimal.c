/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:18:20 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:18:25 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_decimal(long long decimal, t_flags *flags, int *count)
{
	int	bit;

	if (decimal < 0)
	{
		flags->sign = '-';
		decimal *= (-1);
	}
	bit = ft_number_bit(decimal, 10);
	if ((decimal != 0 && bit > flags->accuracy) || flags->accuracy == -1)
		flags->accuracy = bit;
	if (flags->sign != '\0')
		(flags->width)--;
	if (flags->sign != '\0' && flags->space == '0')
		(*count) += write(1, &(flags->sign), 1);
	if (flags->left == 0)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
	if (flags->sign != '\0' && flags->space == ' ')
		(*count) += write(1, &(flags->sign), 1);
	while (flags->accuracy - bit > 0 && bit++)
		(*count) += write(1, "0", 1);
	if (flags->accuracy)
		ft_print_numeral((unsigned long long)decimal, count, 10, 'a');
	if (flags->left)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
}
