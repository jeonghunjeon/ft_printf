/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:57:39 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/11/23 15:19:30 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	a;
	int	b;

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
