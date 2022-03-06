/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:26:25 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 18:26:30 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, t_flags *flags, int *count)
{
	if (s == NULL)
		s = "(null)";
	if ((int)ft_strlen(s) < flags->accuracy
		|| flags->accuracy == -1)
		flags->accuracy = (int)ft_strlen(s);
	if (flags->left != 0)
		*count += write(1, s, flags->accuracy);
	ft_print_space((flags->width - flags->accuracy), count, ' ');
	if (flags->left == 0)
		*count += write(1, s, flags->accuracy);
}
