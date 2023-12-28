/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-ray-cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:02:24 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 22:04:19 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>
#include <math.h>
#include <mlx_plugin.h>

#define MAP_X  8      //map width
#define MAP_Y  8      //map height
#define MAP_S 64      //map cube size

static inline t_vf2d	ray_draw(t_object *o, t_image *img, t_vf2d size, int r)
{
	float	angle;
	t_vf2d	end;

	angle = o->angle - 30 + r;
	end = line_angle_end(o->pos[0], line_angle_get(&angle, size));
	mlx_draw_line(img, o->pos[0], end, 0xFF00eeee);
	return (end);
}

void	ray_cast(t_object *obj, t_image *img, t_vf2d size, char *map)
{
	int		r;
	t_vf2d	end;

	r = -1;
	while (++r < 60)
	{
		end = ray_draw(obj, img, size, r);
	}
}
