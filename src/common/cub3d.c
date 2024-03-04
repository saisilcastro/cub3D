/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:01:46 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 19:01:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void			cub_function(t_cub3d *set);
extern t_vi2d		*cub_mouse_pos(void);
extern char			cub_mouse_press(t_mouse_status button);
extern t_chained	*image_create(int id, t_vf2d size);
extern char			image_next_last(t_chained *image);
extern char			image_next_first(t_chained *image);
extern t_image		*image_search(int id);
extern void			cub_map_set(int id);
extern t_chained	*cub_object_push(int id, char *n, t_vf2d pos, t_image *i);
extern t_object		*cub_object_search(int id);
extern char			object_next_first(t_chained *object);
extern char			object_next_last(t_chained *object);

t_cub3d	*cub_get(void)
{
	static t_cub3d	set;

	return (&set);
}

void	cub_set(t_cub3d *set, char *level)
{
	char	*title;

	title = "cub3D by Luiza and Lisias";
	machine_set(set->gear, title, vi2d_start(0, 0), vf2d_start(800, 600));
	if (!set->gear->start(set->gear, Off))
		return ;
	cub_function(set);
}

void	cub_pop(t_cub3d *set)
{
	set->gear->pop(set->gear);
	mlx_terminate(set->gear->plugin);
}

static void inline	cub_show(void *data)
{
	t_machine	*gear;
	t_image		*image;
	t_vi2d		pos;

	gear = ((t_cub3d *)data)->gear;
	image = gear->map->image;
	mlx_image_clear(image, 0xFF000000);
	if (((t_cub3d *)data)->draw)
		((t_cub3d *)data)->draw(data);
	if (gear->map->image)
	{
		pos = vi2d_start(gear->map->pos->x, gear->map->pos->y);
		mlx_image_to_window(gear->plugin, image->buffer, pos.x, pos.y);
	}
}

static void	cub_function(t_cub3d *set)
{
	set->init = NULL;
	set->mouse_pos = cub_mouse_pos;
	set->mouse_press = cub_mouse_press;
	set->image_create = image_create;
	set->image_next_first = image_next_first;
	set->image_next_last = image_next_last;
	set->image_search = image_search;
	set->map_set = cub_map_set;
	set->object_push = cub_object_push;
	set->object_search = cub_object_search;
	set->object_next_first = object_next_first;
	set->object_next_last = object_next_last;
	set->update = NULL;
	set->draw = NULL;
	set->show = cub_show;
	set->run = cub_run;
	set->pop = NULL;
}
