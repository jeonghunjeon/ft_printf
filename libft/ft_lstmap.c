/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:36:10 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/01/03 20:01:31 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*curr;

	ret = NULL;
	if (f)
	{
		while (lst)
		{
			curr = ft_lstnew(f(lst->content));
			if (!curr)
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			ft_lstadd_back(&ret, curr);
			lst = lst->next;
		}
	}
	return (ret);
}
