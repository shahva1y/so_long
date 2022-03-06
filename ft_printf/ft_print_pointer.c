/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:25:08 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:25:13 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(void *p, t_flags *flags, int *count)
{
	int	bit;

	bit = ft_number_bit((unsigned long long)p, 16);
	if ((p != NULL && bit > flags->accuracy) || flags->accuracy == -1)
		flags->accuracy = bit;
	flags->width -= 2;
	if (flags->left == 0)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
	while (flags->accuracy - bit > 0 && bit++)
		(*count) += write(1, "0", 1);
	*count += write(1, "0x", 2);
	if (flags->accuracy)
		ft_print_numeral((unsigned long long)p, count, 16, 'a');
	if (flags->left)
		ft_print_space((flags->width - flags->accuracy), count, flags->space);
}
