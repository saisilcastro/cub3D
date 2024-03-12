/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:53:05 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/29 12:19:21 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_update(void *data)
{
	t_object	*object;

	object = cub_get()->object_search(0);
	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_LEFT))
	{
		object->angle += 5;
		object_angle_limit(object, vf2d_start(20, 20));
	}
	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_RIGHT))
	{
		object->angle -= 5;
		object_angle_limit(object, vf2d_start(20, 20));
	}
	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_UP))
	{
		object->pos->x += object->vel->x;
		object->pos->y += object->vel->y;
	}
	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_DOWN))
	{
		object->pos->x -= object->vel->x;
		object->pos->y -= object->vel->y;
	}
}
