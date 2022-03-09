/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:09:35 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/09 17:35:31 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	description(va_list ap, const char desc)
{
	size_t	count_ret;

	count_ret = 0;
	printf("desc = %p\n", ap);
	if (desc == 'c')
		count_ret = print_char(va_arg(ap, int));
	else if (desc == 's')
		count_ret = print_str(ap);
	else if (desc == 'p')
		count_ret = print_pointer(ap);
	else if (desc == 'd' || desc == 'i')
		count_ret = print_int(ap);
	else if (desc == 'u')
		count_ret = print_uint(ap);
	else if (desc == 'x' || desc == 'X')
		count_ret = print_hex(ap);
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
			description(ap, str[++idx]);
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
