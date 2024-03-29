/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:47:23 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/29 14:43:24 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline void	scroll_get(double xdelta, double ydelta, void *param)
{
	t_game	*game;

	game = param;
	if (xdelta < 0.0)
		game->mouse->s_wheel->left = 0;
	else
		game->mouse->s_wheel->left = 1;
	if (ydelta < 0.0)
		game->mouse->s_wheel->top = 0;
	else
		game->mouse->s_wheel->top = 1;
}

static inline void	mouse_pos(double x, double y, void *param)
{
	t_game	*game;

	game = param;
	if (game->status & 1 << MOUSE_MOVE)
	{
		game->player->angle = 0.25 * (game->mlx->delta_time);
		if (x < game->mouse->pos->x)
			object_rotate(game->player, 1);
		else
			object_rotate(game->player, 0);
		mlx_set_mouse_pos(game->mlx, game->size->x * 0.5,
			game->size->y * 0.5);
	}
	game->mouse->pos->x = x;
	game->mouse->pos->y = y;
}

static inline void	mouse_press(mouse_key_t button,
		action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;

	game = param;
	if (action)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
			game->mouse->button |= (1 << 0);
		if (button == MLX_MOUSE_BUTTON_MIDDLE)
			game->mouse->button |= (1 << 1);
		if (button == MLX_MOUSE_BUTTON_RIGHT)
			game->mouse->button |= (1 << 2);
	}
	else
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
			game->mouse->button &= ~(1 << 0);
		if (button == MLX_MOUSE_BUTTON_MIDDLE)
			game->mouse->button &= ~(1 << 1);
		if (button == MLX_MOUSE_BUTTON_RIGHT)
			game->mouse->button &= ~(1 << 2);
	}
}

void	mouse_event_start(t_game *game)
{
	mlx_scroll_hook(game->mlx, &scroll_get, game);
	mlx_cursor_hook(game->mlx, &mouse_pos, game);
	mlx_mouse_hook(game->mlx, &mouse_press, game);
}
