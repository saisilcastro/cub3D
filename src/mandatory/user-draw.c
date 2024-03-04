/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:52:30 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/29 12:17:59 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_draw(t_cub3d *set)
{
	t_vf2d	begin;
	t_vf2d	end;

	begin = *(set->object_search(0)->pos);
	*(set->object_search(0)->size) = end = vf2d_start(20, 20);
	mlx_draw_fill_rect(set->gear->map->image, begin, end, 0xFF0000FF);
	ray_cast(set->object_search(0), set->gear->map->image, *(set->gear->size), "");
}
