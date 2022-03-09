/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:18:43 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/12 11:30:44 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		idx;
	char		*ret;
	char		*cpy;

	idx = 0;
	cpy = (char *)s;
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (idx < len && cpy[start + idx])
	{
		ret[idx] = cpy[start + idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
