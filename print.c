/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:15:24 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/21 18:50:02 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	return (1);
}

int	print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	print_int(va_list ap)
{
	int	num;
	int	count;

	num = va_arg(ap, int);
	count = 0;
	ft_putnbr_fd(num, 1);
	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (11);
	if (num < 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_num(unsigned int nb, char *base)
{
	int				char_count;
	unsigned int	base_num;

	char_count = 0;
	base_num = (unsigned int)ft_strlen(base);
	if (nb > base_num - 1)
		char_count += print_num(nb / base_num, base);
	ft_putchar_fd(base[nb % base_num], 1);
	char_count++;
	return (char_count);
}

int	print_pointer(size_t nb, char *base)
{
	int	char_count;

	char_count = 0;
	if (nb > ft_strlen(base) - 1)
		char_count += print_pointer(nb / ft_strlen(base), base);
	if (nb <= ft_strlen(base) - 1)
	{
		ft_putstr_fd("0x", 1);
		char_count += 2;
	}
	ft_putchar_fd(base[nb % ft_strlen(base)], 1);
	char_count++;
	return (char_count);
}
