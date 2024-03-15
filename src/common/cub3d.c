/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:01:46 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/14 02:05:01 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void			cub_function(t_cub3d *set);
extern t_vi2d		*cub_mouse_pos(void);
extern char			cub_mouse_press(t_mouse_status button);
extern t_chained	*image_create(int id, t_vf2d size);
extern t_chained	*image_load(int id, char *path);
extern char			image_next_last(t_chained *image);
extern char			image_next_first(t_chained *image);
extern t_image		*image_search(int id);
extern t_vi2d		image_size(t_image *set);
extern void			cub_map_set(int id);
extern t_chained	*cub_object_push(int id, char *n, t_vf2d p, t_image *i);
extern char			object_next_first(t_chained *object);
extern char			object_next_last(t_chained *object);
extern t_object		*object_search(int id);

t_cub3d	*cub_get(void)
{
	static t_cub3d	set;

	return (&set);
}

void	cub_set(t_cub3d *set)
{
	int	status;

	if (set->gear->status & 1 << MACHINE_RUNNING)
	{
		status = set->gear->status;
		machine_set(set->gear, "cub3D by Luiza and Lisias", vi2d_start(0, 0),
			vf2d_start(800, 600));
		set->gear->status = status;
		if (!set->gear->start(set->gear, Off))
			return ;
	}
	else
		machine_set(set->gear, "cub3D by Luiza and Lisias", vi2d_start(0, 0),
			vf2d_start(800, 600));
	set->level->block->x = set->gear->size->x / set->level->size->x;
	set->level->block->y = set->gear->size->y / set->level->size->y;
	set->map_show = On;
	cub_function(set);
}

static void inline	cub_show(void *data)
{
	t_machine	*gear;
	t_vi2d		pos;

	gear = ((t_cub3d *)data)->gear;
	mlx_image_clear(gear->map->a, 0xFF000000);
	if (((t_cub3d *)data)->draw)
		((t_cub3d *)data)->draw(data);
	if (gear->map->a)
	{
		pos = vi2d_start(gear->map->pos->x, gear->map->pos->y);
		mlx_image_to_window(gear->plugin,
			gear->map->a->image, pos.x, pos.y);
	}
}

void	cub_pop(t_cub3d *set)
{
	int		i;

	i = -1;
	while (++i < 4 && set->level->textures[i])
		free(set->level->textures[i]);
	if (set->level->map)
	{
		i = -1;
		while (*(set->level->map + ++i))
			free(*(set->level->map + i));
		free(set->level->map);
	}
}

static void	cub_function(t_cub3d *set)
{
	set->init = NULL;
	set->mouse_pos = cub_mouse_pos;
	set->mouse_press = cub_mouse_press;
	set->image_create = image_create;
	set->image_load = image_load;
	set->image_next_first = image_next_first;
	set->image_next_last = image_next_last;
	set->image_search = image_search;
	set->image_size = image_size;
	set->map_set = cub_map_set;
	set->object_push = cub_object_push;
	set->object_next_first = object_next_first;
	set->object_next_last = object_next_last;
	set->object_search = object_search;
	set->update = NULL;
	set->draw = NULL;
	set->show = cub_show;
	set->run = cub_run;
	set->pop = NULL;
}
