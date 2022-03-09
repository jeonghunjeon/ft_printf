/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:58:36 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/12/10 21:21:00 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, char *src, int start)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dst[start + idx] = src[idx];
		idx++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s2_len += s1_len;
	ret = (char *)malloc(sizeof(char) * (s2_len + 1));
	if (ret == NULL)
		return (0);
	ft_strcpy(ret, (char *)s1, 0);
	ft_strcpy(ret, (char *)s2, s1_len);
	ret[s2_len] = '\0';
	return (ret);
}
