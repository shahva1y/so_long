/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:35:28 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 13:37:27 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int a)
{
	if (('a' <= a && a <= 'z')
		|| ('A' <= a && a <= 'Z'))
		return (1);
	return (0);
}
