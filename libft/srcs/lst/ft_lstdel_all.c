/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:07:14 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/07 15:38:22 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_all(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free (tmp);
	}
}
