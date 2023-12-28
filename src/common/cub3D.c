/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:07:08 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:28:29 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	cub_function(t_cub *set);

void	cub_set(t_cub *set, char *level)
{
	level_load(set->area, level);
	machine_set(set->gear, "cub3D", vf2d_local(640, 480), vf2d_local(0, 0));
	if (!set->gear->start(set->gear, On))
		return ;
	cub_function(set);
}

static t_vi2d	cub_mouse_pos(t_cub *set)
{
	return (set->gear->mouse->pos[0]);
}

void	cub_pop(t_cub *set)
{
	set->gear->pop(set->gear);
	mlx_terminate(set->gear->plugin);
}

static void inline	cub_show(void *data)
{
	t_machine	*gear;

	gear = ((t_cub *)data)->gear;
	mlx_image_clear(gear->image, 0xFF000000);
	if (((t_cub *)data)->draw)
		((t_cub *)data)->draw(data);
	mlx_image_to_window(gear->plugin, gear->image->data, 0, 0);
}

static void	cub_function(t_cub *set)
{
	set->init = NULL;
	set->mouse_pos = cub_mouse_pos;
	set->update = NULL;
	set->draw = NULL;
	set->show = cub_show;
	set->run = cub_run;
	set->pop = NULL;
}
