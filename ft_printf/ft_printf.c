/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:27:52 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/24 14:27:59 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_init(t_flags *flags)
{
	flags->left = 0;
	flags->width = -1;
	flags->alt = 0;
	flags->space = ' ';
	flags->sign = '\0';
	flags->accuracy = -1;
	flags->type = '\0';
}

static int	ft_to_int(const char **str)
{
	unsigned long long	num;

	num = 0;
	while (*(*str + 1) >= '0' && *(*str + 1) <= '9')
	{
		num = num * 10 + **str - '0';
		(*str)++;
	}
	if (**str >= '0' && **str <= '9')
		num = num * 10 + **str - '0';
	return (num);
}

static void	ft_parse_flags(const char **str, t_flags *flags)
{
	while (**str != 'c' && **str != 's' && **str != 'p'
		&& **str != 'd' && **str != 'i' && **str != 'u'
		&& **str != 'x' && **str != 'X' && **str != '\0' && (*str)++)
	{
		if (**str == '-')
			flags->left = 1;
		if (**str == '-')
			flags->space = ' ';
		if (**str == '0' && flags->left != 1)
			flags->space = '0';
		if (**str == '#')
			flags->alt = 1;
		if (**str == ' ' && flags->sign == '\0')
			flags->sign = ' ';
		if (**str == '+')
			flags->sign = '+';
		if (**str >= '0' && **str <= '9')
			flags->width = ft_to_int(str);
		if (**str == '.' && (*str)++)
			flags->accuracy = ft_to_int(str);
		if (**str == '%')
			break ;
	}
	if (flags->space == '0' && flags->accuracy != -1 && **str != '%')
		flags->space = ' ';
}

static void	ft_parse_type(const char **str, va_list *ap,
						t_flags *flags, int *count)
{
	flags->type = **str;
	if (**str == '%')
		ft_print_percent(flags, count);
	else if (**str == 'c')
		ft_print_char(va_arg(*ap, int), flags, count);
	else if (**str == 's')
		ft_print_str(va_arg(*ap, char *), flags, count);
	else if (**str == 'p')
		ft_print_pointer(va_arg(*ap, void *), flags, count);
	else if (**str == 'd' || **str == 'i')
		ft_print_decimal(va_arg(*ap, int), flags, count);
	else if (**str == 'u')
		ft_print_unsigned(va_arg(*ap, unsigned int), flags, count);
	else if (**str == 'x' || **str == 'X')
		ft_print_hex(va_arg(*ap, unsigned int), flags, count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	t_flags	flags;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			ft_flags_init(&flags);
			ft_parse_flags(&(str), &flags);
			ft_parse_type(&(str), &ap, &flags, &count);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
