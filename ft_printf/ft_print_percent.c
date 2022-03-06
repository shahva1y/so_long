/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:31:43 by krulindi          #+#    #+#             */
/*   Updated: 2021/11/06 14:32:13 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_flags *flags, int *count)
{
	if (flags->width < 1)
		flags->width = 1;
	if (flags->left == 0)
		ft_print_space((flags->width - 1), count, flags->space);
	(*count) += write(1, "%", 1);
	if (flags->left)
		ft_print_space((flags->width - 1), count, flags->space);
}
