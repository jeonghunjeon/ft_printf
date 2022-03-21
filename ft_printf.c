/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:09:35 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/19 00:06:23 by jeonjeon         ###   ########.fr       */
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
		count_ret += 2;
		count_ret += print_uint(va_arg(ap, unsigned int), "0123456789abcdef");
	}
	else if (desc == 'd' || desc == 'i')
		count_ret = print_int(ap);
	else if (desc == 'u')
		count_ret = print_unint(ap);
	else if (desc == 'x' || desc == 'X')
		count_ret = print_uint(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (desc == '%')
		count_ret = ft_putchar_fd('%', 1);
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
