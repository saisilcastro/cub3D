/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:26:36 by mister-code       #+#    #+#             */
/*   Updated: 2024/02/28 15:20:20 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_draw_line(t_image *set, t_vf2d b, t_vf2d e, int color)
{
	t_vf2d	dest;
	t_vf2d	inc;
	t_vf2d	pos;
	int		i;
	int		step;

	dest = vf2d_start(e.x - b.x, e.y - b.y);
	if (fabs(dest.x) > fabs(dest.y))
		step = (int)fabs(dest.x);
	else
		step = (int)fabs(dest.y);
	inc = vf2d_start(dest.x / (float)step, (float)dest.y / step);
	pos = b;
	i = -1;
	while (++i < step)
	{
		draw_pixel(set, pos.x, pos.y, color);
		pos.x += inc.x;
		pos.y += inc.y;
	}
}
