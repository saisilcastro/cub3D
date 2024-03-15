/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:51:04 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/14 05:21:25 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vf2d	line_angle_get(float *angle, t_vf2d size)
{
	t_vf2d	delta;

	if (*angle < 0)
		*angle += 360;
	else if (*angle > 359)
		*angle -= 360;
	delta.x = cos(deg_to_rad(*angle)) * size.x;
	delta.y = -sin(deg_to_rad(*angle)) * size.y;
	return (delta);
}

t_vf2d	line_angle_end(t_vf2d begin, t_vf2d vel)
{
	t_vf2d	end;

	end.x = begin.x + vel.x;
	end.y = begin.y + vel.y;
	return (end);
}

float	angle_limit(float angle)
{
	if (angle < 0)
		return (angle += 360);
	if (angle > 359)
		return (angle -= 360);
	return (angle);
}
