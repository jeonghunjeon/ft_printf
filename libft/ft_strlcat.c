/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:58:47 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/12/10 20:38:17 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	point;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	point = dst_len;
	if (size < dst_len)
		return (src_len + size);
	while (*src && dst_len + 1 < size)
	{
		dst[dst_len] = *src;
		src++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (point + src_len);
}
