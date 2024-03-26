/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:36:57 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/01 18:23:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*update;
	t_list	*last;

	last = *lst;
	while (last)
	{
		update = last->next;
		del(last->content);
		free(last);
		last = update;
	}
	*lst = last;
}
