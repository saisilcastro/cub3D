/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:45:34 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/26 16:32:37 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>
#include <stdlib.h>
#include <math.h>

void	object_angle_limit(t_object *set, t_vf2d size)
{
	set->vel[0] = line_angle_get(&set->angle, size);
}

t_vf2d	object_angle_end(t_object *obj, t_vf2d begin, t_vf2d size)
{
	t_vf2d	end;

	end.x = begin.x + obj->vel->x * size.x;
	end.y = begin.y + obj->vel->y * size.y;
	return (end);
}
