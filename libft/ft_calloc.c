/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:45 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/12/10 19:29:46 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	idx;

	idx = 0;
	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	while (idx < size * count)
	{
		*(ret + idx) = 0;
		idx++;
	}
	return (ret);
}
