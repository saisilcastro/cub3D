/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:11:34 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/12 16:26:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline void	minimap(t_cub3d *set);
static inline void	floor_ceil_draw(t_cub3d *set);

void	map_draw(t_cub3d *set)
{
	floor_ceil_draw(set);
}

static inline void	floor_ceil_draw(t_cub3d *set)
{
	t_vf2d	b;
	t_vf2d	size;
	t_image	*img;
	int		color;

	img = set->gear->map->a;
	size = vf2d_start(set->gear->size->x, set->gear->size->y * 0.5);
	mlx_draw_fill_rect(img, vf2d_start(0, 0), size,
		pixel_to_int(&set->level->color[1]));
	mlx_draw_fill_rect(img, vf2d_start(0, set->gear->size->y * 0.5), size,
		pixel_to_int(set->level->color));
	mlx_texture_draw(set->image_search(1), vi2d_start(10, 50), vf2d_start(5, 5));
}

static inline void	minimap(t_cub3d *set)
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
		b.x = (pos.x * 11) + 1;
		b.y = (pos.y * 11) + 1;
		e.x = 11 - 1;
		e.y = 11 - 1;
		mlx_draw_fill_rect(set->gear->map->a, b, e, color);
	}
}
