/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:23:17 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:52:32 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ray_pos_dir_get(t_game *game, t_object *obj, t_caster *cast, int x)
{
	double	camera_x;

	camera_x = 2 * x / game->size->x - 1;
	cast->ray_dir->x = obj->dir->x + obj->plane->x * camera_x;
	cast->ray_dir->y = obj->dir->y + obj->plane->y * camera_x;
	cast->map->x = (int)obj->pos->x;
	cast->map->y = (int)obj->pos->y;
}

void	delta_dist_get(t_caster *cast)
{
	if (cast->ray_dir->x == 0)
		cast->delta_dist->x = 1e30;
	else
		cast->delta_dist->x = fabs(1 / cast->ray_dir->x);
	if (cast->ray_dir->y == 0)
		cast->delta_dist->y = 1e30;
	else
		cast->delta_dist->y = fabs(1 / cast->ray_dir->y);
}

void	step_and_side_get(t_vd2d *player, t_caster *cast)
{
	if (cast->ray_dir->x < 0)
	{
		cast->step->x = -1;
		cast->side_dist->x = (player->x - cast->map->x) * cast->delta_dist->x;
	}
	else
	{
		cast->step->x = 1;
		cast->side_dist->x = (cast->map->x + 1.0 - player->x)
			* cast->delta_dist->x;
	}
	if (cast->ray_dir->y < 0)
	{
		cast->step->y = -1;
		cast->side_dist->y = (player->y - cast->map->y) * cast->delta_dist->y;
	}
	else
	{
		cast->step->y = 1;
		cast->side_dist->y = (cast->map->y + 1.0 - player->y)
			* cast->delta_dist->y;
	}
}

void	dda_get(t_caster *cast)
{
	while (1)
	{
		if (cast->side_dist->x < cast->side_dist->y)
		{
			cast->side_dist->x += cast->delta_dist->x;
			cast->map->x += cast->step->x;
			cast->e_compass = WE;
			if (cast->step->x == 1)
				cast->e_compass = EA;
		}
		else
		{
			cast->side_dist->y += cast->delta_dist->y;
			cast->map->y += cast->step->y;
			cast->e_compass = NO;
			if (cast->step->y == 1)
				cast->e_compass = SO;
		}
		if (map_solid(cast->map->x, cast->map->y))
			break ;
	}
}

void	vertical_limit(t_vd2d *screen, t_caster	*cast)
{
	cast->s_v_draw->begin = (int)((screen->y - cast->line_height)
			* 0.5) + cast->pitch;
	if (cast->s_v_draw->begin < 0)
		cast->s_v_draw->begin = 0;
	cast->s_v_draw->end = cast->s_v_draw->begin + cast->line_height
		+ cast->pitch;
	if (cast->s_v_draw->end >= screen->y)
		cast->s_v_draw->end = screen->y - 1;
}
