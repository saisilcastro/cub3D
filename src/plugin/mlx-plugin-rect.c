/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:04:55 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/11 15:35:41 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_draw_fill_rect(t_image *set, t_vf2d b, t_vf2d size, int color)
{
	int	i;
	int	max;

	i = -1;
	max = size.x * size.y;
	while (++i < max)
		draw_pixel(set, b.x + (i % (int)size.x), b.y
			+ (i / size.x), color);
}

void	mlx_draw_rect(t_image *set, t_vf2d b, t_vf2d e, int color)
{
	t_vf2d	top;
	t_vf2d	right;
	t_vf2d	bottom;

	top = vf2d_start(e.x, b.y);
	right = vf2d_start(e.x, e.y);
	bottom = vf2d_start(b.x, e.y);
	mlx_draw_line(set, b, top, color);
	mlx_draw_line(set, top, right, color);
	mlx_draw_line(set, right, bottom, color);
	mlx_draw_line(set, bottom, b, color);
}

void	mlx_image_clear(t_image *set, int color)
{
	int		i;
	int		size;
	int		offset;
	uint8_t	*start;

	if (!set)
		return ;
	i = -1;
	size = ((mlx_image_t *)set->image)->width
		* ((mlx_image_t *)set->image)->height;
	while (++i < size)
	{
		offset = ((i / ((mlx_image_t *)set->image)->width)
				* ((mlx_image_t *)set->image)->width
				+ (i % ((mlx_image_t *)set->image)->width))
			* sizeof(uint32_t);
		start = ((mlx_image_t *)set->image)->pixels + offset;
		*(uint32_t *)start = color;
	}
}