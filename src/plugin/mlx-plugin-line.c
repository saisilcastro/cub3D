/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:26:36 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 21:54:30 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>
#include <mlx_plugin.h>

t_vf2d	make_way(t_image	*set, t_vf2d b, t_vf2d e, int color)
{
	t_vf2d	way;

	way = line_make(b, e);
	draw_pixel(set, (int)way.x, (int)way.y, color);
	return (way);
}

void	mlx_draw_line(t_image *set, t_vf2d b, t_vf2d e, int color)
{
	t_vf2d		way;

	if (!set)
		return ;
	way = vf2d_local(b.x, b.y);
	if (b.x < e.x)
		while (way.x < e.x)
			way = make_way(set, b, e, color);
	else
	{
		if (b.x == e.x)
		{
			if (b.y < e.y)
				while (way.y < e.y)
					way = make_way(set, b, e, color);
			else
				while (way.y > e.y)
					way = make_way(set, b, e, color);
		}
		while (way.x > e.x)
			way = make_way(set, b, e, color);
	}
}
