/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:12:15 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/07 16:18:05 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_int(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
	{
		ft_putstr_fd("Empty list", 2);
		return ;
	}
	tmp = lst;
	while (tmp)
	{
		ft_printf("|%d| >> ", tmp->content);
		tmp = tmp->next;
	}
}
