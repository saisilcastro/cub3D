/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:52:30 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/08 16:13:39 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_draw(t_cub3d *set)
{
	t_vf2d	begin;
	t_vf2d	end;

	map_draw(set);
	begin = *(set->object_search(0)->pos);
	*(set->object_search(0)->size) = end = vf2d_start(20, 20);
	mlx_draw_fill_rect(set->gear->map->image, begin, end, 0xFF0000FF);
	ray_cast(set->object_search(0), set->gear->map->image, *(set->gear->size), "");
}
