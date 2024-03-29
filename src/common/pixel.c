/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:10:18 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:28:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

uint32_t	*pixel_set(void *buffer, t_vi2d p, int w, int bpp)
{
	int		offset;

	offset = (p.y * w + p.x) * bpp;
	return ((uint32_t *)(buffer + offset));
}

int	pixel_get(void *buffer, t_vi2d p, int w, int bpp)
{
	return (*(uint32_t *)(buffer + (p.y * w + p.x) * bpp));
}

int	pixel_to_int(t_pixel *set)
{
	return ((set->a << 24) | (set->b << 16) | (set->g << 8) | (set->r << 0));
}

void	pixel_show(int color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (color >> 0);
	g = (color >> 8);
	b = (color >> 16);
	a = (color >> 24);
	printf("%i %i %i %i\n", r, g, b, a);
}

void	pixel_divider(uint32_t *pixel)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;

	r = (*pixel >> 0) & 0xFF;
	g = (*pixel >> 8) & 0xFF;
	b = (*pixel >> 16) & 0xFF;
	a = (*pixel >> 24) & 0xFF;
	*pixel = (a << 24) | ((b >> 1) << 16) | ((g >> 1) << 8) | ((r >> 1) << 0);
}
