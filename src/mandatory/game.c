/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:50:10 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 16:21:09 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*cub_get(void)
{
	static t_game	game;

	return (&game);
}

void	game_start(t_game *game)
{
	if (!(game->status & 1 << MACHINE_RUNNING))
		return ;
	*(game->player->dir) = vd2d_start(-1, 0);
	*(game->player->plane) = vd2d_start(0, 0.66);
	object_rotate(game->player, 1);
	*(game->size) = vd2d_start(800, 600);
	game->mlx = mlx_init(game->size->x, game->size->y, "cub3d", false);
	mlx_set_window_size(game->mlx, game->size->x, game->size->y);
	mlx_set_window_pos(game->mlx, 250, 50);
	game->screen->img = mlx_new_image(game->mlx, game->size->x, game->size->y);
	game->screen->tex = NULL;
	game->gf[NO] = image_push(0, NULL, mlx_load_png(game->level->textures[NO]));
	game->gf[EA] = image_push(1, NULL, mlx_load_png(game->level->textures[EA]));
	game->gf[SO] = image_push(2, NULL, mlx_load_png(game->level->textures[SO]));
	game->gf[WE] = image_push(3, NULL, mlx_load_png(game->level->textures[WE]));
	event_start(game);
}

t_status	special_char(char c)
{
	if (c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (On);
	return (Off);
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
