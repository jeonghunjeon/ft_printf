/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:15:24 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/09 17:12:43 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int		idx;
	char	*cpy;

	cpy = (char *)s;
	idx = 0;
	while (cpy[idx])
		idx++;
	return (idx);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	idx;

	idx = 0;
	if (fd < 0)
		return ;
	while (s[idx])
	{
		write(fd, &s[idx], 1);
		idx++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	a;
	int	b;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	a = n / 10;
	b = n % 10;
	if (a > 9)
		ft_putnbr_fd(a, fd);
	else if (a == 0)
		;
	else
		ft_putchar_fd((a + 48), fd);
	ft_putchar_fd((b + 48), fd);
}

int print_char(char ch)
{
	ft_putchar_fd(ch, 1);
	return (1);
}

int print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_fd("(NULL)", 1);
		return (6);
	}
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int print_pointer(va_list ap)
{
	return (0);
}

int print_int(va_list ap)
{
	int	num;
	int	count;

	num = va_arg(ap, int);
	count = 0;
	ft_putnbr_fd(num, 1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int print_uint(va_list ap)
{
	return (0);
}

int print_hex(va_list ap)
{
	return (0);
}
