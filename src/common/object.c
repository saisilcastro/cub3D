/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:52:45 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:28:12 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	object_rotate(t_object *obj, int clockwise)
{
	if (clockwise == 1)
	{
		vd2d_rotate(obj->dir, obj->angle);
		vd2d_rotate(obj->plane, obj->angle);
	}
	else if (!clockwise)
	{
		vd2d_rotate(obj->dir, -obj->angle);
		vd2d_rotate(obj->plane, -obj->angle);
	}
}

void	object_forward(t_object *obj)
{
	int	x;
	int	y;

	x = obj->pos->x + obj->dir->x * obj->speed;
	y = obj->pos->y + obj->dir->y * obj->speed;
	if (!map_solid(x, obj->pos->y))
		obj->pos->x += obj->dir->x * obj->speed;
	if (!map_solid(obj->pos->x, y))
		obj->pos->y += obj->dir->y * obj->speed;
}

void	object_backward(t_object *obj)
{
	int	x;
	int	y;

	x = obj->pos->x - obj->dir->x * obj->speed;
	y = obj->pos->y - obj->dir->y * obj->speed;
	if (!map_solid(x, obj->pos->y))
		obj->pos->x -= obj->dir->x * obj->speed;
	if (!map_solid(obj->pos->x, y))
		obj->pos->y -= obj->dir->y * obj->speed;
}

void	object_left(t_object *obj)
{
	t_vd2d	new_dir;
	int		x;
	int		y;

	new_dir = vd2d_start(obj->dir->x, obj->dir->y);
	vd2d_rotate(&new_dir, (obj->angle + (M_PI * 0.5)));
	x = obj->pos->x + new_dir.x * obj->speed;
	y = obj->pos->y + new_dir.y * obj->speed;
	if (!map_solid(x, obj->pos->y))
		obj->pos->x += new_dir.x * obj->speed;
	if (!map_solid(obj->pos->x, y))
		obj->pos->y += new_dir.y * obj->speed;
}

void	object_right(t_object *obj)
{
	t_vd2d	new_dir;
	int		x;
	int		y;

	new_dir = vd2d_start(obj->dir->x, obj->dir->y);
	vd2d_rotate(&new_dir, -(obj->angle + (M_PI * 0.5)));
	x = obj->pos->x + new_dir.x * obj->speed;
	y = obj->pos->y + new_dir.y * obj->speed;
	if (!map_solid(x, obj->pos->y))
		obj->pos->x += new_dir.x * obj->speed;
	if (!map_solid(obj->pos->x, y))
		obj->pos->y += new_dir.y * obj->speed;
}
