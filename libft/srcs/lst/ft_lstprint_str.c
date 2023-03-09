/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:30:22 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/07 16:18:09 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_str(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putstr(lst->content);
		lst = lst->next;
	}
}
