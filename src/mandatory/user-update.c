/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:53:05 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/14 06:12:09 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	user_key()
{
	t_object	*object;

	object = cub_get()->object_search(0);
	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_LEFT))
	{
		object->angle += 1;
		object_angle_limit(object, vf2d_start(1, 1));
	}
	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_RIGHT))
	{
		object->angle -= 1;
		object_angle_limit(object, vf2d_start(1, 1));
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

static inline void	map_show()
{
	static t_status	tab;

	if (mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_TAB))
		tab = On;
	if (tab && !mlx_is_key_down(cub_get()->gear->plugin, MLX_KEY_TAB))
	{
		tab = Off;
		cub_get()->map_show ^= On;
	}
}

static inline void	mouse_angle()
{
	static t_vi2d	mouse;

	if (mouse.x == 0 && mouse.y == 0)
		mouse = *(cub_get()->gear->mouse->pos);
	if (mouse.x != cub_get()->gear->mouse->pos->x)
	{
	}
}

void	user_update(void *data)
{
	user_key();
	map_show();
}
