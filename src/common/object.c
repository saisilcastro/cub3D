/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:30:34 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/26 17:32:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>
#include <stdlib.h>
#include <math.h>

t_object	object_start(int id, char *name, t_vf2d pos, t_image *image)
{
	t_object	set;

	set.id = id;
	set.name = name;
	set.pos[0] = pos;
	set.angle = 0;
	set.vel->x = cos(degree_to_rad(set.angle));
	set.vel->y = sin(degree_to_rad(set.angle));
	set.image = image;
	set.next = NULL;
	return (set);
}

t_object	*object_push(int id, char *name, t_vf2d pos, t_image *image)
{
	t_object	*set;

	set = (t_object *)malloc(sizeof(t_object));
	if (!set)
		return (NULL);
	set->id = id;
	set->name = name;
	set->pos[0] = pos;
	set->angle = 270;
	set->vel->x = cos(degree_to_rad(set->angle));
	set->vel->y = sin(degree_to_rad(set->angle));
	set->image = image;
	set->next = NULL;
	return (set);
}

void	object_next_last(t_object **head, t_object *set)
{
	t_object	*upd;

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

void	object_pop(t_object **head)
{
	t_object	*next;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}
