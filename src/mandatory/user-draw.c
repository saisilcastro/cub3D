/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:04:15 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 22:07:07 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	user_draw(t_cub *set)
{
	t_vf2d	begin;
	t_vf2d	end;

	begin = set->gear->object->pos[0];
	end = object_angle_end(set->gear->object, begin, (t_vf2d){10, 10});
	ray_cast(set->gear->object, set->gear->image, set->gear->size[0], set->area->data);
	mlx_draw_line(set->gear->image, begin, end, 0xFFFF0000);
}
