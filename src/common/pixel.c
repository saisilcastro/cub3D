/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:27:06 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/11 17:46:06 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	pixel_to_int(t_pixel *set)
{
	return (set->a << 24 | set->b << 16 | set->g << 8 | set->r);
}

uint32_t	texture_to_int(mlx_texture_t *a, int x, int y)
{
	uint8_t	*color;

	color = a->pixels + (y * a->width + x) * a->bytes_per_pixel;
	return (*(uint32_t *)color);
}

t_pixel	int_to_pixel(unsigned int color)
{
	t_pixel	pixel;

	pixel.r = color >> 0;
	pixel.g = color >> 8;
	pixel.b = color >> 16;
	pixel.a = color >> 24;
	return (pixel);
}
