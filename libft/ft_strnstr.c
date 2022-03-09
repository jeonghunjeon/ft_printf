/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:01:21 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/12/07 21:01:34 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	idx2;
	char	*src;
	char	*to_find;

	src = (char *)big;
	to_find = (char *)little;
	idx = 0;
	idx2 = 0;
	if (to_find[idx2] == '\0')
		return (src);
	while (src[idx] && idx < len)
	{
		while ((src[idx + idx2] == to_find[idx2]) && src[idx + idx2])
			idx2++;
		if (idx + idx2 > len)
			return (NULL);
		if (to_find[idx2] == '\0')
			return (src + idx);
		idx++;
		idx2 = 0;
	}
	return (0);
}
