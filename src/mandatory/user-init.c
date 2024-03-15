/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:20 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/13 19:47:08 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline t_vf2d	player_start(void)
{
	t_vf2d	pos;
	t_map	*level;

	level = cub_get()->level;
	pos = player_vector_pos(level);
	pos.x = (pos.x * level->block->x) + (level->block->x * .5);
	pos.y = (pos.y * level->block->y) + (level->block->y * .5);
	return (pos);
}

void	user_init(t_cub3d *set, void *data)
{
	t_vf2d	pos;

	set->image_next_last(set->image_create(0, set->gear->size[0]));
	set->image_next_last(set->image_load(1, set->level->textures[0]));
	set->image_next_last(set->image_load(2, set->level->textures[1]));
	set->image_next_last(set->image_load(3, set->level->textures[2]));
	set->image_next_last(set->image_load(4, set->level->textures[3]));
	set->map_set(0);
	set->object_next_last(set->object_push(0, "hero", player_start(), NULL));
}
