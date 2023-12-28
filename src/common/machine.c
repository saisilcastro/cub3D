/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:47:08 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/26 16:47:57 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>

static void	machine_function(t_machine *set);

void	machine_set(t_machine *set, char *title, t_vf2d size, t_vf2d pos)
{
	int	i;

	set->title = title;
	set->size[0] = size;
	set->pos[0] = pos;
	set->plugin = NULL;
	set->mouse->button = 0;
	set->image = NULL;
	set->object = NULL;
	set->map[0] = object_start(0, "map", vf2d_local(0, 0), NULL);
	i = -1;
	while (++i < 255)
		set->key[i] = Off;
	machine_function(set);
}

static t_status	machine_start(t_machine *gear, t_status resize)
{
	gear->plugin = mlx_init(gear->size->x, gear->size->y, gear->title, resize);
	if (!gear->plugin)
		return (Off);
	return (On);
}

static void	machine_pop(t_machine *set)
{
	image_pop(set->plugin, &set->image);
	object_pop(&set->object);
}

static void	machine_function(t_machine *set)
{
	set->start = machine_start;
	set->pop = machine_pop;
}
