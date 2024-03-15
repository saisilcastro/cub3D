/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:11:34 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/14 02:14:19 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline void	minimap(t_cub3d *set);
static inline void	player_draw(t_cub3d *set, int half);

void	map_draw(t_cub3d *set)
{
	if (set->map_show)
	{
		minimap(set);
		player_draw(set, 4);
	}
}

static inline void	minimap(t_cub3d *set)
{
	t_vi2d	i;
	t_vi2d	pos;
	t_vf2d	b;
	t_vf2d	e;
	int		color;

	i.x = -1;
	i.y = set->level->size->x * set->level->size->y;
	while (++i.x < i.y)
	{
		pos.x = i.x % set->level->size->x;
		pos.y = i.x / set->level->size->x;
		if (set->level->map[pos.y][pos.x] == '1')
			color = 0xFFFF0000;
		else
			color = 0xFFFFFFFF;
		b.x = (pos.x * (int)set->level->block->x) + 1;
		b.y = (pos.y * (int)set->level->block->y) + 1;
		e.x = b.x + set->level->block->x - 1;
		e.y = b.y + set->level->block->y - 1;
		mlx_draw_fill_rect(set->gear->map->a, b, e, color);
	}
}

static inline void	player_draw(t_cub3d *set, int half)
{
	t_object	*player;
	t_image		*img;
	t_vf2d		b;
	t_vf2d		e;
	int			i;

	img = set->gear->map->a;
	player = set->object_search(0);
	b = vf2d_start(player->pos->x - half, player->pos->y - half);
	e = vf2d_start(player->pos->x + half, player->pos->y + half);
	mlx_draw_fill_rect(img, b, e, 0xFF0000FF);
	i = -1;
	while (++ i < 5)
	{
		b = vf2d_start(player->pos->x - (half * 0.5) + i, player->pos->y);
		e = object_angle_end(player, b, vf2d_start(15, 15));
		mlx_draw_line(img, b, e, 0xFFAAAA00);
	}	
}