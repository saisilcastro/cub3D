/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:20 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 01:38:24 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_init(t_cub3d *set, void *data)
{
	set->image_next_last(set->image_create(0, set->gear->size[0]));
	set->map_set(0);
	int	i;

	i = -1;
	while (++i < 40)
	{
		draw_pixel(set->gear->map->image, i / 20, i % 20, 0xFFFFFFFF);
	}
}
