/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:57:51 by jeonjeon          #+#    #+#             */
/*   Updated: 2021/11/09 13:57:51 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	idx;

	idx = 0;
	if (fd < 0)
		return ;
	while (s[idx])
	{
		write(fd, &s[idx], 1);
		idx++;
	}
}
