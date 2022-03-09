/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:18:22 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/03 20:44:40 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	char const	*front;
	char const	*rear;

	ret = NULL;
	if (s1)
	{
		front = s1;
		rear = s1 + ft_strlen(s1) - 1;
		while (*front && ft_strchr(set, *front))
			front++;
		while (*rear && ft_strchr(set, *rear) && front <= rear)
			rear--;
		if (front > rear)
			return (ft_strdup(""));
		ret = (char *)malloc(sizeof(char) * (rear - front + 2));
		if (ret == NULL)
			return (0);
		ft_strlcpy(ret, front, rear - front + 2);
	}
	return (ret);
}
