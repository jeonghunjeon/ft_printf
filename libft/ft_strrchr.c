/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:28:03 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/11 21:17:11 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cpy;
	char	*ret;
	int		idx;

	cpy = (char *)s;
	ret = NULL;
	idx = 0;
	while (cpy[idx])
	{
		if (cpy[idx] == (char)c)
			ret = &cpy[idx];
		idx++;
	}
	if (cpy[idx] == '\0' && (char)c == '\0')
		ret = &cpy[idx];
	return (ret);
}
