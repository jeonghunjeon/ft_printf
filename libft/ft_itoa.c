/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:53:38 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/11/09 13:53:38 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

long	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return ((long)i);
}

char	*transform(char *str, long nb, int len)
{
	int	idx;

	idx = 0;
	if (nb < 0)
	{
		str[idx] = '-';
		idx++;
		len--;
		nb *= -1;
	}
	while (len > 0)
	{
		if (len > 1)
			str[idx] = (nb / ft_div(len) + '0');
		else
			str[idx] = (nb % 10 + '0');
		nb %= ft_div(len);
		idx++;
		len--;
	}
	str[idx] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ret;
	int		len;

	nb = (long)n;
	len = nbr_len(nb);
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (0);
	ret = transform(ret, nb, len);
	return (ret);
}
