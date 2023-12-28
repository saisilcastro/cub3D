/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:11:45 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 21:53:16 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <math.h>
#include <string.h>

static void	key_event(t_machine *set)
{
	if (mlx_is_key_down(set->plugin, MLX_KEY_LEFT))
	{
		set->object->angle += 5;
		object_angle_limit(set->object, vf2d_local(10, 10));
	}
	if (mlx_is_key_down(set->plugin, MLX_KEY_RIGHT))
	{
		set->object->angle -= 5;
		object_angle_limit(set->object, vf2d_local(10, 10));
	}
	if (mlx_is_key_down(set->plugin, MLX_KEY_UP))
	{
		set->object->pos->x += set->object->vel->x;
		set->object->pos->y += set->object->vel->y;
	}
	if (mlx_is_key_down(set->plugin, MLX_KEY_DOWN))
	{
		set->object->pos->x -= set->object->vel->x;
		set->object->pos->y -= set->object->vel->y;
	}
}

void	user_update(void *set)
{
	key_event(((t_cub *)set)->gear);
}
