/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:24:21 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/25 13:12:33 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_pixel(t_vd2d pos, int color, int len)
{
	t_vd2d		b;
	t_vd2d		e;
	t_vi2d		i;
	uint8_t		*start;
	mlx_image_t	*img;

	img = cub_get()->screen->img;
	b = vd2d_start(pos.x - len * .5, pos.y - len * .5);
	e = vd2d_start(b.x + len, b.y + len);
	if (!vd2d_limit(&b, vd2d_start(0, 0), vd2d_start(cub_get()->size->x - 1,
				cub_get()->size->y - 1)) || !vd2d_limit(&e, vd2d_start(0, 0),
			vd2d_start(cub_get()->size->x - 1, cub_get()->size->y - 1)))
		return ;
	i.y = b.y;
	while (i.y <= e.y)
	{
		i.x = b.x;
		while (i.x <= e.x)
		{
			*pixel_set(img->pixels, i, img->width, sizeof(uint32_t)) = color;
			i.x++;
		}
		i.y++;
	}
}

t_vd2d	angle_get(t_vd2d b, t_vd2d e, int *step)
{
	t_vd2d	delta;
	t_vd2d	angle;

	delta = vd2d_start(e.x - b.x, e.y - b.y);
	*step = (int)(fabs(delta.y));
	if (fabs(delta.x) > fabs(delta.y))
		*step = (int)fabs(delta.x);
	angle = vd2d_start(delta.x / (double)*step, delta.y / (double)*step);
	return (angle);
}

void	draw_line(t_vd2d b, t_vd2d e, int len, int color)
{
	int			i;
	int			step;
	t_vd2d		pos;
	t_vd2d		angle;
	static int	o_color;

	if (o_color != color)
	{
		o_color = color;
	}
	pos = b;
	angle = angle_get(b, e, &step);
	if (step > cub_get()->size->x * cub_get()->size->y)
		return ;
	i = -1;
	while (++i < step)
	{
		draw_pixel(pos, color, len);
		pos.x += angle.x;
		pos.y += angle.y;
	}
}

void	draw_rect_fill(t_vd2d b, t_vd2d e, int lenght, int color)
{
	t_vd2d	i;

	i.y = b.y;
	while (i.y < e.y)
	{
		i.x = e.x;
		while (i.x >= b.x)
		{
			draw_pixel(i, color, lenght);
			i.x--;
		}
		i.y++;
	}
}
