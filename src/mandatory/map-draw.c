/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:11:34 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/08 17:25:16 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	map_draw(t_cub3d *set)
{
	t_vi2d	i;
	t_vi2d	pos;
	t_vf2d	b;
	t_vf2d	e;
	int		color;

	i.x = -1;
	i.y = set->level->width * set->level->height;
	while (++i.x < i.y)
	{
		pos.x = i.x % set->level->width;
		pos.y = i.x / set->level->width;
		if (set->level->map[pos.y][pos.x] == '1')
			color = 0xFFFF0000;
		else
			color = 0xFFFFFFFF;
		b.x = (pos.x * 32) + 1;
		b.y = (pos.y * 32) + 1;
		e.x = b.x + 32 - 1;
		e.y = b.y + 32 - 1;
		mlx_draw_fill_rect(set->gear->map->image, b, e, color);
	}
}
