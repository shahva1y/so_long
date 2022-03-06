/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:21:13 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:21:17 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int hex, t_flags *flags, int *count)
{
	int	bit;

	bit = ft_number_bit((unsigned long long)hex, 16);
	if ((hex != 0 && bit > flags->accuracy) || flags->accuracy == -1)
		flags->accuracy = bit;
	if (flags->alt == 1)
		flags->width -= 2;
	if (flags->left == 0)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
	while (flags->accuracy - bit > 0 && bit++)
		(*count) += write(1, "0", 1);
	if (flags->alt == 1 && hex != 0 && flags->type == 'x')
		(*count) += write(1, "0x", 2);
	if (flags->alt == 1 && hex != 0 && flags->type == 'X')
		(*count) += write(1, "0X", 2);
	if (flags->type == 'x' && flags->accuracy)
		ft_print_numeral((unsigned long long)hex, count, 16, 'a');
	if (flags->type == 'X' && flags->accuracy)
		ft_print_numeral((unsigned long long)hex, count, 16, 'A');
	if (flags->left)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
}
