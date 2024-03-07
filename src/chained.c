/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:09:49 by lumedeir          #+#    #+#             */
/*   Updated: 2024/02/29 15:17:14 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_chained	*chained_push(void *data)
{
	t_chained	*set;

	set = malloc(sizeof(t_chained));
	if (!set)
		return (NULL);
	set->data = data;
	set->prev = NULL;
	set->next = NULL;
	return (set);
}

t_status	chained_next_first(t_chained **head, t_chained *set)
{
	if (!set)
		return (Off);
	set->next = *head;
	if (*head)
		(*head)->prev = set;
	*head = set;
	return (On);
}

t_status	chained_next_last(t_chained **head, t_chained *set)
{
	t_chained	*upd;

	if (!set)
		return (Off);
	if (!*head)
	{
		*head = set;
		return (On);
	}
	upd = *head;
	while (upd->next)
		upd = upd->next;
	set->prev = upd;
	upd->next = set;
	return (On);
}

void	chained_pop(t_chained **head, void (*pop)(void *data))
{
	t_chained	*next;

	while (*head)
	{
		next = (*head)->next;
		if (pop)
			pop((*head)->data);
		free(*head);
		*head = next;
	}
}
