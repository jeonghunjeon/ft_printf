/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:51:30 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/12 00:26:01 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	split_len(char const *s, char c)
{
	size_t	len;
	char	*cpy;

	len = 0;
	cpy = (char *)s;
	while (*cpy)
	{
		while (*cpy && (*cpy == c))
			cpy++;
		if (*cpy == '\0')
			break ;
		len++;
		while (*cpy && (*cpy != c))
			cpy++;
	}
	return (len);
}

void	ft_free(t_split *v)
{
	while (v->ret >= 0)
		free(v->ret[v->idx--]);
	free(v->ret);
	v->ret = NULL;
	return ;
}

void	ft_split_sub(char c, t_split *v)
{
	while (v->cpy[v->split])
	{
		while (v->cpy[v->split] && (v->cpy[v->split] == c))
			v->split++;
		if (v->cpy[v->split] == '\0')
			break ;
		v->top = v->split;
		while (v->cpy[v->split] && (v->cpy[v->split] != c))
			v->split++;
		v->ret[v->idx] = (char *)malloc(v->split - v->top + 1);
		if (v->ret[v->idx] == NULL)
		{
			ft_free(v);
			return ;
		}
		ft_strlcpy(v->ret[v->idx], &v->cpy[v->top], (v->split - v->top + 1));
		v->idx++;
	}
	v->ret[v->idx] = NULL;
}

char	**ft_split(char const *s, char c)
{
	t_split	v;

	ft_memset(&v, 0, sizeof(v));
	v.cpy = (char *)s;
	v.cnt = split_len(s, c);
	v.ret = (char **)malloc(sizeof(char *) * (v.cnt + 1));
	if (v.ret == NULL)
		return (0);
	ft_split_sub(c, &v);
	return (v.ret);
}
