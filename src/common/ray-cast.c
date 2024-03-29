/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:30:32 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:30:32 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	wall_prop(t_vd2d *screen, t_caster *cast)
{
	if (cast->e_compass == WE || cast->e_compass == EA)
		cast->per_wall_dist = (cast->side_dist->x - cast->delta_dist->x);
	else
		cast->per_wall_dist = (cast->side_dist->y - cast->delta_dist->y);
	cast->line_height = (int)(screen->y / cast->per_wall_dist);
}

double	wall_x_get(t_game *game, t_object *obj, t_caster *cast)
{
	double	wall_x;

	if (cast->e_compass == WE || cast->e_compass == EA)
		wall_x = obj->pos->y + cast->per_wall_dist * cast->ray_dir->y;
	else
		wall_x = obj->pos->x + cast->per_wall_dist * cast->ray_dir->x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

t_vi2d	texture_x_get(t_game *game, t_caster *cast, t_image *img, double wall_x)
{
	t_vi2d	tex;

	tex.x = (int)(wall_x * img->tex->width);
	if ((cast->e_compass == WE || cast->e_compass == EA)
		&& cast->ray_dir->x > 0)
		tex.x = img->tex->width - tex.x - 1;
	if ((cast->e_compass == NO || cast->e_compass == SO)
		&& cast->ray_dir->y < 0)
		tex.x = img->tex->width - tex.x - 1;
	return (tex);
}

void	texture_apply(t_caster *cast, t_image *img, t_vi2d tex, t_vi2d p)
{
	t_game		*game;
	double		step;
	double		tex_pos;
	uint32_t	color;

	game = cub_get();
	if (game->status & 1 << MINIMAP_SHOW)
		return ;
	step = 1.0 * img->tex->height / cast->line_height;
	tex_pos = (cast->s_v_draw->begin - cast->pitch - game->size->y * .5
			+ cast->line_height * .5) * step;
	while (++p.y < cast->s_v_draw->end)
	{
		tex.y = (int)tex_pos & (img->tex->height - 1);
		tex_pos += step;
		color = pixel_get(img->tex->pixels, vi2d_start(tex.x, tex.y),
				img->tex->width, sizeof(uint32_t));
		*pixel_set(game->screen->img->pixels, p, game->screen->img->width,
			sizeof(uint32_t)) = color;
	}
}

void	ray_cast_start(t_game *game, int x)
{
	t_caster	cast;
	int			color;
	double		wall_x;
	t_vi2d		tex;

	cast.pitch = 0;
	while (++x < game->size->x)
	{
		ray_pos_dir_get(game, game->player, &cast, x);
		delta_dist_get(&cast);
		step_and_side_get(game->player->pos, &cast);
		dda_get(&cast);
		wall_prop(game->size, &cast);
		vertical_limit(game->size, &cast);
		wall_x = wall_x_get(game, game->player, &cast);
		tex = texture_x_get(game, &cast, game->gf[cast.e_compass], wall_x);
		texture_apply(&cast, game->gf[cast.e_compass], tex,
			vi2d_start(x, cast.s_v_draw->begin - 1));
	}
}
