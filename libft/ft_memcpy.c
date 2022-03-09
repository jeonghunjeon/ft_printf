/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:56:19 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/03 20:08:37 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int len)
{
	int	idx;

	if (!dest && !src)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		*((char *)dest + idx) = *((char *)src + idx);
		idx++;
	}
	return (dest);
}
