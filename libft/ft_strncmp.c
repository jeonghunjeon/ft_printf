/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:00:37 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/12/07 20:44:40 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	i = 0;
	while ((*cpy1 || *cpy2) && i < n)
	{
		if (*cpy1 == *cpy2)
		{
			cpy1++;
			cpy2++;
		}
		else if (*cpy1 > *cpy2)
			return (*cpy1 - *cpy2);
		else if (*cpy1 < *cpy2)
			return (*cpy1 - *cpy2);
		i++;
	}
	return (0);
}
