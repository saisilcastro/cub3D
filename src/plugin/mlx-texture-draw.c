/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-texture-draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:29:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/12 11:52:58 by lumedeir         ###   ########.fr       */
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
		draw_pixel(img, pos.x + b.x, pos.y + b.y, color);
	}
}
