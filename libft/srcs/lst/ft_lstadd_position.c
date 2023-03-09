/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:16:19 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/23 12:16:57 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_position(t_list **lst, t_list *new, int position)
{
	int		i;
	t_list	*tmp;

	if (!(*lst))
		return ;
	if (position < 2 || position > ft_lstsize(*lst))
		return ;
	i = 2;
	tmp = *lst;
	while (tmp)
	{
		if (i == position)
		{
			new->next = tmp->next;
			tmp->next = new;
		}
		tmp = tmp->next;
		i++;
	}
}
