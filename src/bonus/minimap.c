/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:03:52 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/25 23:08:05 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_draw(t_game *game)
{
	t_vd2d	b;
	t_vd2d	e;
	t_vd2d	dir;

	dir = vd2d_start(game->player->dir->x, game->player->dir->y);
	b.x = game->player->pos->x * game->level->cell->x;
	b.y = game->player->pos->y * game->level->cell->y;
	e = vd2d_start(b.x + 1, b.y + 1);
	draw_rect_fill(b, e, 10, 0x11ff0000);
	e.x = b.x + (game->player->dir->x * 15);
	e.y = b.y + (game->player->dir->y * 15);
	draw_line(b, e, 3, 0x110000FF);
}

t_status	special_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (On);
	return (Off);
}

void	minimap_draw(t_game *game)
{
	t_vi2d	p;
	t_vd2d	b;
	t_vd2d	e;
	t_vd2d	cell;

	if (!game || !game->level->map)
		return ;
	draw_rect_fill(vd2d_start(0, 0), game->size[0], 1, 0x33555555);
	cell = *(game->level->cell);
	p.y = -1;
	while (++p.y < game->level->size->y)
	{
		p.x = -1;
		while (++p.x < game->level->size->x)
		{
			if (game->level->map && game->level->map[p.y] && game->level->map[p.y][p.x] > 0)
			{
				b = vd2d_start((cell.x * p.x), (cell.y * p.y));
				e = vd2d_start(b.x + cell.x, b.y + cell.y);
				draw_rect_fill(b, e, 1, 0x33FFFFFF);
			}
		}
	}
	player_draw(game);
}
