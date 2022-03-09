/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:56:27 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/03 20:25:55 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		idx;
	char		*d_cpy;
	char		*s_cpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	idx = 0;
	d_cpy = (char *)dest;
	s_cpy = (char *)src;
	if (src < dest)
	{
		while (len-- > 0)
			*(d_cpy + len) = *(s_cpy + len);
	}
	else
	{
		while (idx < len)
		{
			*(d_cpy + idx) = *(s_cpy + idx);
			idx++;
		}
	}
	return (dest);
}
