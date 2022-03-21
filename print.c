/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:15:24 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/19 00:09:00 by jeonjeon         ###   ########.fr       */
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

int		ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write(fd, &c, 1);
	return (1);
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

void	ft_putunbr_fd(unsigned int n, int fd)
{
	int	a;
	int	b;

	if (fd < 0)
		return ;
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

int print_char(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
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

int print_unint(va_list ap)
{
	unsigned int	num;
	unsigned int	count;

	num = va_arg(ap, unsigned int);
	count = 0;
	ft_putunbr_fd(num, 1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_uint(unsigned int nb, char *base)
{
	int	char_count;

	char_count = 0;
	if (nb >= (unsigned int)ft_strlen(base))
		char_count += print_uint(nb / ft_strlen(base), base);
	ft_putchar_fd(base[nb % ft_strlen(base)], 1);
	char_count++;
	return (char_count);
}

