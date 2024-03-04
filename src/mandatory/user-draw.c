/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:52:30 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 20:13:21 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	user_draw(t_cub3d *set)
{
	t_vf2d	begin;
	t_vf2d	end;

	begin = set->object_search(0)->pos[0];
	//end = object_angle_end(set->object_search(0), begin, (t_vf2d){10, 10});
	ray_cast(set->gear->object, set->gear->image, set->gear->size[0], set->area->data);
	//mlx_draw_line(set->gear->image, begin, end, 0xFFFF0000);
}
