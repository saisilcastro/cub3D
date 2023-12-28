/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:16:46 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 16:26:57 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image_of.h>
#include <stdlib.h>

t_image	*image_push(void *data)
{
	t_image	*set;

	set = (t_image *)malloc(sizeof(t_image));
	set->data = data;
	set->next = NULL;
	return (set);
}

void	image_next_last(t_image **head, t_image *set)
{
	t_image	*upd;

	if (!*head)
	{
		*head = set;
		return ;
	}
	upd = *head;
	while (upd->next)
		upd = upd->next;
	upd->next = set;
}

void	image_pop(void *plugin, t_image **head)
{
	t_image	*next;

	while (*head)
	{
		next = (*head)->next;
		if ((*head)->data)
			mlx_delete_image(plugin, (*head)->data);
		free(*head);
		*head = next;
	}
}
