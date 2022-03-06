/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:23:12 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:23:16 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned long long u, t_flags *flags, int *count)
{
	int	bit;

	bit = ft_number_bit(u, 10);
	if ((u != 0 && bit > flags->accuracy) || flags->accuracy == -1)
		flags->accuracy = bit;
	if (flags->left == 0)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
	while (flags->accuracy - bit > 0 && bit++)
		(*count) += write(1, "0", 1);
	if (flags->accuracy)
		ft_print_numeral((unsigned long long)u, count, 10, 'a');
	if (flags->left)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
}
