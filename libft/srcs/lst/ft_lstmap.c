/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:22:35 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/22 17:09:36 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
		return (NULL);
	new = tmp;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->next)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (tmp);
}
