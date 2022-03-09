/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:08 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/11/23 15:15:20 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*cpy;

	idx = 0;
	cpy = (unsigned char *)s;
	while (idx < n)
	{
		if (cpy[idx] == (unsigned char)c)
			return (&cpy[idx]);
		idx++;
	}
	return (NULL);
}
