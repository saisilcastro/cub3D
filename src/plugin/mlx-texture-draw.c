/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-texture-draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:29:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/12 16:24:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	mlx_texture_draw(t_image *s, t_vi2d b, t_vf2d zoom)
{
	int				i;
	int				size;
	mlx_texture_t	*text;
	t_vi2d			pos;
	t_image			*img;

	img = cub_get()->gear->map->a;
	text = s->texture;
	size = (text->width * zoom.x) * (text->height * zoom.y);
	i = -1;
	while (++i < size)
	{
		pos.x = i % (int)(text->width * zoom.x);
		pos.y = i / (text->width * zoom.x);
		draw_pixel(img, pos.x + b.x, pos.y + b.y,
			texture_to_int(text, (float)pos.x / zoom.x, (float)pos.y / zoom.y));
	}
}
