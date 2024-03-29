/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector-vd2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:25 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/27 00:50:43 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vd2d	vd2d_start(double x, double y)
{
	return ((t_vd2d){x, y});
}

void	vd2d_rotate(t_vd2d *pos, double rotation)
{
	double	old_x;
	double	x;
	double	y;

	if (rotation < 0)
		rotation += 2 * M_PI;
	if (rotation > 2 * M_PI)
		rotation -= 2 * M_PI;
	old_x = pos->x;
	x = pos->x * cos(rotation) - pos->y * sin(rotation);
	if (map_solid(x, pos->y))
		pos->x = pos->x * cos(rotation) - pos->y * sin(rotation);
	y = old_x * sin(rotation) + pos->y * cos(rotation);
	if (map_solid(pos->x, y))
		pos->y = old_x * sin(rotation) + pos->y * cos(rotation);
}

int	vd2d_limit(t_vd2d *set, t_vd2d b, t_vd2d e)
{
	if (set->x <= b.x)
	{
		set->x = b.x;
		return (0);
	}
	if (set->x >= e.x)
	{
		set->x = e.x;
		return (0);
	}
	if (set->y <= b.y)
	{
		set->y = b.y;
		return (0);
	}
	if (set->y >= e.y)
	{
		set->y = e.y;
		return (0);
	}
	return (1);
}

void	vd2d_show(t_vd2d *set, char *x, char *y)
{
	if (x == NULL)
		x = "x:";
	if (y == NULL)
		y = "y:";
	printf("%s %.6lf %s %.6lf\n", x, set->x, y, set->y);
}
