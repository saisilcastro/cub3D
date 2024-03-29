/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:23:19 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/03 20:04:54 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*backup;
	t_list	*next;

	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	backup = new;
	while (lst)
	{
		next = lst->next;
		lst = next;
		if (lst)
		{
			new->next = ft_lstnew(f(lst->content));
			if (!new->next)
			{
				del(lst->content);
				return (NULL);
			}
			new = new->next;
		}
	}
	new = backup;
	return (new);
}
