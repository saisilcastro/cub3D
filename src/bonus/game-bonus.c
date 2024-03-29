/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game-bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:08:16 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/29 15:00:51 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*cub_get(void)
{
	static t_game	game;

	return (&game);
}

t_vd2d	cell_get(t_game *game)
{
	t_vd2d	cell;

	cell.x = game->size->x / (double)game->level->size->x;
	cell.y = game->size->y / (double)game->level->size->y;
	return (cell);
}

void	game_start(t_game *game)
{
	if (!(game->status & 1 << MACHINE_RUNNING))
		return ;
	*(game->player->dir) = vd2d_start(-1, 0);
	*(game->player->plane) = vd2d_start(0, 0.66);
	object_rotate(game->player, 1);
	*(game->size) = vd2d_start(1366, 768);
	*(game->level->cell) = cell_get(game);
	mlx_set_setting(MLX_FULLSCREEN, true);
	game->mlx = mlx_init(game->size->x, game->size->y, "cub3d", false);
	mlx_set_window_size(game->mlx, game->size->x, game->size->y);
	mlx_set_window_pos(game->mlx, 250, 50);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->screen->img = mlx_new_image(game->mlx, game->size->x, game->size->y);
	game->screen->tex = NULL;
	game->gf[NO] = image_push(0, NULL, mlx_load_png(game->level->textures[NO]));
	game->gf[EA] = image_push(1, NULL, mlx_load_png(game->level->textures[EA]));
	game->gf[SO] = image_push(2, NULL, mlx_load_png(game->level->textures[SO]));
	game->gf[WE] = image_push(3, NULL, mlx_load_png(game->level->textures[WE]));
	event_start(game);
}

void	game_pop(t_game *set)
{
	int	i;

	if (set->screen->img)
		mlx_delete_image(set->mlx, set->screen->img);
	i = -1;
	while (++i < 4 && set->gf[i])
		image_pop(set->gf[i]);
	if (set->mlx)
		mlx_terminate(set->mlx);
	i = -1;
	while (++i < 4 && set->level->textures[i])
		free(set->level->textures[i]);
	i = -1;
	while (set->level->map[++i])
		free(set->level->map[i]);
	free(set->level->map);
}
