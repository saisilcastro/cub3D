/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:20 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 16:43:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_init(t_cub3d *set, void *data)
{
	int	i;

	set->image_next_last(set->image_create(0, set->gear->size[0]));
	set->map_set(0);
	set->object_next_last(set->object_push(0,
			"hero", vf2d_start(400, 300), NULL));
}
