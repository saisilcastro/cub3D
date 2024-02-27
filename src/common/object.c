/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:44:38 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/27 16:12:21 by lde-cast         ###   ########.fr       */
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

void	object_pop(void *set)
{
	t_object	*remover;

	remover = set;
	if (remover->name)
		free(remover->name);
	if (remover->status & 1 << OBJECT_PUSH)
		free(remover);
}
