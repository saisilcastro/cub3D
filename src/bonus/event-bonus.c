/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event-bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:21:00 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:21:00 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline void	game_clear(void *set)
{
	t_game	*game;
	int		i;
	int		size;
	t_vd2d	b;
	t_vd2d	e;

	game = set;
	if (!(game->status & 1 << MINIMAP_SHOW))
	{
		b = vd2d_start(0, 0);
		e = vd2d_start(game->size->x, game->size->y * 0.5);
		draw_rect_fill(b, e, 1, pixel_to_int(&game->level->color[1]));
		b = vd2d_start(0, e.y + 1);
		e = vd2d_start(e.x, game->size->y);
		draw_rect_fill(b, e, 1, pixel_to_int(game->level->color));
	}
	game->player->speed = 7.0 * (game->mlx->delta_time);
	if (game->status & (1 << MOUSE_MOVE))
	{
		game->player->angle = 1.5 * (game->mlx->delta_time);
		object_rotate(game->player, mouse_move(game));
	}
	else
		game->player->angle = 2.0 * (game->mlx->delta_time);
}

static inline void	game_show(void *set)
{
	t_game	*game;

	game = set;
	if (game->status & 1 << MACHINE_SHOW)
		mlx_image_to_window(game->mlx, game->screen->img, 0, 0);
	game->status &= ~(1 << MACHINE_SHOW);
}

static inline void	game_update(void *set)
{
	t_game			*game;
	static t_status	key_m;
	static t_status	key_tab;

	game = set;
	object_control(game, game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_M))
		key_m = On;
	if (!mlx_is_key_down(game->mlx, MLX_KEY_M) && key_m == On)
	{
		game->status ^= (1 << MOUSE_MOVE);
		key_m = Off;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_TAB))
		key_tab = On;
	if (!mlx_is_key_down(game->mlx, MLX_KEY_TAB) && key_tab == On)
	{
		game->status ^= (1 << MINIMAP_SHOW);
		key_tab = Off;
	}
}

static inline void	game_draw(void *set)
{
	t_game	*game;

	game = set;
	ray_cast_start(set, -1);
	if (game->status & 1 << MINIMAP_SHOW)
		minimap_draw(set);
	game->status |= 1 << MACHINE_SHOW;
}

void	event_start(t_game *set)
{
	mouse_event_start(set);
	mlx_loop_hook(set->mlx, game_clear, set);
	mlx_loop_hook(set->mlx, game_update, set);
	mlx_loop_hook(set->mlx, game_draw, set);
	mlx_loop_hook(set->mlx, game_show, set);
	mlx_loop(set->mlx);
}
