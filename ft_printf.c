/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:09:35 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/17 22:15:44 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	description(va_list ap, const char desc)
{
	size_t	count_ret;

	count_ret = 0;
	if (desc == 'c')
		count_ret = print_char(ap);
	else if (desc == 's')
		count_ret = print_str(ap);
	else if (desc == 'p')
	{
		ft_putstr_fd("0x", 1);
		count_ret = print_uint(va_arg(ap, unsigned int), "0123456789abcdef");
	}
	else if (desc == 'd' || desc == 'i')
		count_ret = print_int(ap);
	else if (desc == 'u')
		count_ret = print_uint(va_arg(ap, unsigned int), "0123456789");
	else if (desc == 'x' || desc == 'X')
		count_ret = print_uint(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (desc == '%')
	{
		ft_putchar_fd('%', 1);
		count_ret = 1;
	}
	else
		count_ret = 0;
	return (count_ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	count_ret;
	size_t	idx;

	idx = 0;
	count_ret = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			count_ret += description(ap, str[++idx]);
		else
		{
			ft_putchar_fd(str[idx], 1);
			count_ret++;
		}
		idx++;
	}
	va_end(ap);
	return (count_ret);
}
