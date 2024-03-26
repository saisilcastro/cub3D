/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:38:18 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/25 12:26:40 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	object_control(t_game *game, t_object *obj)
{
	t_vi2d	p;

	if (game->status & 1 << MINIMAP_SHOW)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		object_backward(obj);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		object_forward(obj);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		object_left(obj);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		object_right(obj);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		object_rotate(obj, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		object_rotate(obj, 1);
}
