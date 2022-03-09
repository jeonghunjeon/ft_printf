/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:58:21 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/11/09 13:58:21 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*str;
	int		src_len;

	cpy = (char *)s;
	src_len = 0;
	while (cpy[src_len])
		src_len++;
	str = (char *) malloc(sizeof(char) * (src_len + 1));
	if (str == NULL)
		return (0);
	str[src_len] = '\0';
	while (src_len >= 0)
	{
		str[src_len] = cpy[src_len];
		src_len--;
	}
	return (str);
}
