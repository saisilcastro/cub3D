/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:13:08 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 01:27:45 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static inline void	machine_function(t_machine *set);
extern void	image_pop(void *data);

void	machine_set(t_machine *set, char *title, t_vi2d pos, t_vf2d size)
{
	if (!set)
		return ;
	set->title = title;
	set->pos[0] = pos;
	set->size[0] = size;
	set->mouse->pos[0] = vi2d_start(0, 0);
	set->mouse->button = 0;
	set->mouse->s_wheel->left = 0;
	set->mouse->s_wheel->top = 0;
	set->map[0] = object_start(0, "object", vf2d_start(0, 0), NULL);
	set->image = NULL;
	set->object = NULL;
	set->plugin = NULL;
	machine_function(set);
}

static inline char	machine_start(t_machine *set, t_status resize)
{
	if (!set->size->x || !set->size->y)
		return (0);
	set->plugin = mlx_init(set->size->x, set->size->y, set->title, resize);
	if (!set->plugin)
		return (0);
	return (1);
}

static inline void	machine_pop(t_machine *set)
{
	if (set->image)
		chained_pop(&set->image, image_pop);
	if (set->object)
		chained_pop(&set->object, object_pop);
}

static inline void	machine_function(t_machine *set)
{
	set->start = machine_start;
	set->pop = machine_pop;
}
