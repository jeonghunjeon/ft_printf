/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:07 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/05 18:14:54 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	size_t	ret;
	int		sign;

	str = (char *)nptr;
	sign = 1;
	ret = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + *str++ - 48;
		if (sign == 1 && ret > 9223372036854775807L)
			return (-1);
		if (sign == -1 && ret > 9223372036854775808UL)
			return (0);
	}
	return (sign * ret);
}
