/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:20 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/12 22:51:18 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_init(t_cub3d *set, void *data)
{
	set->image_next_last(set->image_create(0, set->gear->size[0]));
	set->image_next_last(set->image_load(1, set->level->textures[0]));
	set->image_next_last(set->image_load(2, set->level->textures[1]));
	set->image_next_last(set->image_load(3, set->level->textures[2]));
	set->image_next_last(set->image_load(4, set->level->textures[3]));
	set->map_set(0);
	set->object_next_last(set->object_push(0, "hero", vf2d_start(320, 240), NULL));
}
