/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:49:04 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 21:49:07 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int		left;
	int		width;
	int		accuracy;
	int		alt;
	char	space;
	char	sign;
	char	type;
}				t_flags;

int		ft_printf(const char *str, ...);
void	ft_print_percent(t_flags *flags, int *count);
void	ft_print_numeral(unsigned long long quo, int *count,
			unsigned long long base, char digit);
void	ft_print_space(int length, int *count, char c);
void	ft_print_decimal(long long decimal, t_flags *flags, int *count);
void	ft_print_unsigned(unsigned long long u, t_flags *flags, int *count);
void	ft_print_hex(unsigned int hex, t_flags *flags, int *count);
void	ft_print_char(char c, t_flags *flags, int *count);
void	ft_print_str(char *s, t_flags *flags, int *count);
void	ft_print_pointer(void *p, t_flags *flags, int *count);
int		ft_number_bit(unsigned long long number, int base);
#endif
