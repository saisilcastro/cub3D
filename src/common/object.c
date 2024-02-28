/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:44:38 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 01:26:30 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_object	object_start(int id, char *name, t_vf2d pos, t_image *image)
{
	t_object	set;

	set.id = id;
	set.name = strdup(name);
	set.pos[0] = pos;
	set.angle = 0;
	set.vel->x = cos(degree_to_rad(set.angle));
	set.vel->y = sin(degree_to_rad(set.angle));
	set.image = image;
	set.status = 0x2;
	return (set);
}

t_object	*object_push(int id, char *name, t_vf2d pos, t_image *image)
{
	t_object	*set;

	set = (t_object *)malloc(sizeof(t_object));
	if (!set)
		return (NULL);
	set->id = id;
	set->name = strdup(name);
	set->pos[0] = pos;
	set->angle = 270;
	set->vel->x = cos(degree_to_rad(set->angle));
	set->vel->y = sin(degree_to_rad(set->angle));
	set->image = image;
	set->status = 0x3;
	return (set);
}

void	object_pop(void *data)
{
	t_object	*object;

	object = data;
	if (object->name)
		free(object->name);
	if (object->status & 1 << OBJECT_PUSH)
		free(object);
}
