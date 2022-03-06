/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:19:49 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 15:19:57 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space(int length, int *count, char c)
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*count) += write(1, &c, 1);
		i++;
	}
}
