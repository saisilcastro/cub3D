/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:26:36 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/14 21:49:36 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vf2d	inc_get(t_vf2d b, t_vf2d e, int *step)
{
	t_vf2d	slope;
	t_vf2d	inc;

	slope = vf2d_start(e.x - b.x, e.y - b.y);
	*step = (int)(fabs(slope.y));
	if (fabs(slope.x) > fabs(slope.y))
		*step = (int)fabs(slope.x);
	inc = vf2d_start(slope.x / (float)*step, slope.y / (float)*step);
	return (inc);
}

void	mlx_draw_line(t_image *set, t_vf2d b, t_vf2d e, int color)
{
	t_vf2d	inc;
	t_vf2d	pos;
	int		i;
	int		step;

	inc = inc_get(b, e, &step);
	pos = b;
	i = -1;
	while (++i < step)
	{
		draw_pixel(set, pos.x, pos.y, color);
		pos.x += inc.x;
		pos.y += inc.y;
	}
}
