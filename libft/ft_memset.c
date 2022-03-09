/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:56:33 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/11/09 13:56:33 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		*((char *)ptr + idx) = value;
		idx++;
	}
	return (ptr);
}
