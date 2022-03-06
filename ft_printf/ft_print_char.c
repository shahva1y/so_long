/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:27:50 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:27:55 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, t_flags *flags, int *count)
{
	if (flags->left != 0)
		*count += write(1, &c, 1);
	ft_print_space(flags->width - 1, count, ' ');
	if (flags->left == 0)
		*count += write(1, &c, 1);
}
