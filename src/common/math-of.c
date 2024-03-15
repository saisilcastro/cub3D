/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:16 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/15 01:23:49 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	deg_to_rad(float angle)
{
	float	value;

	value = angle * M_PI / 180.0;
	if (value >= -(M_PI + M_PI) && value <= M_PI + M_PI)
		return (value);
	return (0);
}

t_vi2d	vi2d_start(int x, int y)
{
	return ((t_vi2d){x, y});
}

t_vf2d	vf2d_start(float x, float y)
{
	return ((t_vf2d){x, y});
}

float	limit(int begin, int size, float edge)
{
	return ((begin / size * size) - edge);
}

t_vf2d	vector_pos(t_vf2d *pos)
{
	t_map	*the;
	t_vf2d	vec;

	the = cub_get()->level;
	vec.x = floor(pos->x / the->block->x);
	vec.y = floor(pos->y / the->block->y);
	if (vec.x < 0)
		vec.x = 0;
	if (vec.y < 0)
		vec.y = 0;
	if (vec.x > the->size->x - 1)
		vec.x = the->size->x - 1;
	if (vec.y > the ->size->y - 1)
		vec.y = the->size->y - 1;
	return (vec);
}

float pythag(t_vf2d *set) {
    return sqrtf(set->x * set->x + set->y * set->y);
}
