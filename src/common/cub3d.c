/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:01:46 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/27 18:00:07 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	cub_function(t_cub3d *set);

t_cub3d	*cub_get(void)
{
	static t_cub3d	set;

	return (&set);
}

void	cub_set(t_cub3d *set, char *level)
{
	//level_load(set->area, level);
	machine_set(set->gear, "cub3D", vi2d_start(0, 0), vi2d_start(640, 480));
	if (!set->gear->start(set->gear, On))
		return ;
	cub_function(set);
}

static t_vi2d	cub_mouse_pos(t_cub3d *set)
{
	return (set->gear->mouse->pos[0]);
}

void	cub_pop(t_cub3d *set)
{
	set->gear->pop(set->gear);
	mlx_terminate(set->gear->plugin);
}

static void inline	cub_show(void *data)
{
	t_machine	*gear;

	gear = ((t_cub3d *)data)->gear;
	if (gear->image)
		mlx_image_clear(gear->image, 0xFF000000);
	if (((t_cub3d *)data)->draw)
		((t_cub3d *)data)->draw(data);
	if (gear->image)
		mlx_image_to_window(gear->plugin, gear->image->data, 0, 0);
}

static void	cub_function(t_cub3d *set)
{
	set->init = NULL;
	set->mouse_pos = cub_mouse_pos;
	set->update = NULL;
	set->draw = NULL;
	set->show = cub_show;
	set->run = cub_run;
	set->pop = NULL;
}
