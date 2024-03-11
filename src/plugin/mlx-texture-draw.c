/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-texture-draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:29:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/11 17:34:40 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_texture_draw(t_image *s, t_vi2d b)
{
	int				i;
	int				size;
	mlx_texture_t	*text;
	t_vi2d			pos;
	t_image			*img;

	img = cub_get()->gear->map->a;
	text = s->texture;
	size = text->width * text->height;
	i = -1;
	while (++i < size)
	{
		pos.x = (i % text->width);
		pos.y = (i / text->width);
		unsigned int	color = texture_to_int(text, pos.x, pos.y);
		t_pixel	p = int_to_pixel(color);
		printf("%i %i %i %i\n", p.r, p.g, p.b, p.a);
		draw_pixel(img, pos.x + b.x, pos.y + b.y, color);
	}
}
