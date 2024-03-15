/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:44:38 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/14 05:22:20 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_object	object_start(int id, char *name, t_vf2d pos, t_image *image)
{
	t_object	set;

	set.id = id;
	set.name = strdup(name);
	set.a = image;
	*(set.pos) = *(set.route) = pos;
	set.angle = 270;
	set.vel->x = cos(deg_to_rad(set.angle));
	set.vel->y = -sin(deg_to_rad(set.angle));
	if (!set.a)
		*(set.size) = vf2d_start(16, 16);
	*(set.zoom) = vf2d_start(1, 1);
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
	set->a = image;
	*(set->pos) = *(set->size) = pos;
	set->angle = 270;
	set->vel->x = cos(deg_to_rad(set->angle));
	set->vel->y = -sin(deg_to_rad(set->angle));
	if (!set->a)
		*(set->size) = vf2d_start(16, 16);
	*(set->zoom) = vf2d_start(1, 1);
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
