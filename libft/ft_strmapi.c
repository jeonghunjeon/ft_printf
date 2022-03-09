/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:00:23 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/03 20:43:59 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		idx;
	char		*str;
	char		*cpy;

	len = ft_strlen(s);
	idx = 0;
	cpy = (char *)s;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (0);
	while (cpy[idx])
	{
		str[idx] = f(idx, cpy[idx]);
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
