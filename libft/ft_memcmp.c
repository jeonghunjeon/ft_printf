/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:26 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/12/10 17:28:20 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;
	size_t			idx;

	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n)
	{
		if (cpy1[idx] != cpy2[idx])
			return ((int)(cpy1[idx] - cpy2[idx]));
		idx++;
	}
	return (0);
}
