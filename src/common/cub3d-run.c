/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:43:49 by mister-code       #+#    #+#             */
/*   Updated: 2024/02/28 01:05:16 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	mlx_plugin_run(t_cub3d *set)
{
	if (set->update)
		mlx_loop_hook(set->gear->plugin, set->update, set);
	if (set->show)
		mlx_loop_hook(set->gear->plugin, set->show, set);
	mlx_event_start(set->gear);
}

void	cub_run(t_cub3d *set, void *data)
{
	if (set->init)
		set->init(set, data);
	mlx_plugin_run(set);
	if (set->update)
		set->update(set);
	mlx_loop(set->gear->plugin);
	if (set->pop)
		set->pop(set);
	cub_pop(set);
}

void	cub_map_set(int id)
{
	cub_get()->gear->map->image = cub_get()->image_search(id);
}
