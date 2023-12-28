/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:14:46 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/25 22:52:10 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	user_init(t_cub *set, void *data)
{
	image_next_last(&set->gear->image,
		image_push(mlx_new_image(set->gear->plugin,
				set->gear->size->x, set->gear->size->y)));
	object_next_last(&set->gear->object,
		object_push(0, "line", vf2d_local(320, 240), NULL));
}
