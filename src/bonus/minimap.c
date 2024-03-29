/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:03:52 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/26 17:33:32 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_draw(t_game *game)
{
	t_vd2d	b;
	t_vd2d	e;
	t_vd2d	dir;
	double	map_pixel;

	dir = vd2d_start(game->player->dir->x, game->player->dir->y);
	map_pixel = (game->level->size->x * game->level->cell->x);
	b.x = map_pixel - (game->player->pos->x * game->level->cell->x);
	b.y = (game->player->pos->y * game->level->cell->y);
	e = vd2d_start(b.x + 1, b.y + 1);
	draw_rect_fill(b, e, 10, 0x11ff0000);
	e.x = b.x - (dir.x * 15);
	e.y = b.y + (dir.y * 15);
	draw_line(b, e, 3, 0x110000FF);
}

t_status	special_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (On);
	return (Off);
}

void	minimap_draw(t_game *game, t_vi2d *p, t_vd2d *cell)
{
	int		size;
	t_vd2d	b;
	t_vd2d	e;

	size = game->level->size->x - p->x - 1;
	b = vd2d_start((cell->x * size), (cell->y * p->y));
	e = vd2d_start(b.x + cell->x, b.y + cell->y);
	draw_rect_fill(b, e, 1, 0x33FFFFFF);
}

void	minimap_run(t_game *game)
{
	t_vi2d	p;
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
			if (game->level->map && game->level->map[p.y] && \
			game->level->map[p.y][p.x] > 0)
				minimap_draw(game, &p, &cell);
	}
	player_draw(game);
}
