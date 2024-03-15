/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:52:30 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/14 23:38:20 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline void	floor_ceil_draw(t_cub3d *set);

void	user_draw(t_cub3d *set)
{
	t_vf2d	begin;
	t_vf2d	end;

	floor_ceil_draw(set);
	map_draw(set);
	ray_cast(set->object_search(0), set->gear->map->a);
}

static inline void	floor_ceil_draw(t_cub3d *set)
{
	t_vf2d	b;
	t_vf2d	e;
	t_image	*img;
	int		color;

	if (set->map_show == Off)
	{
		img = set->gear->map->a;
		e = vf2d_start(set->gear->size->x, set->gear->size->y * 0.5);
		mlx_draw_fill_rect(img, vf2d_start(0, 0), e,
			pixel_to_int(&set->level->color[1]));
		e = vf2d_start(set->gear->size->x, set->gear->size->y);
		mlx_draw_fill_rect(img, vf2d_start(0, set->gear->size->y * 0.5), e,
			pixel_to_int(set->level->color));
	}
}