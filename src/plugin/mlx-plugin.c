/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:59:44 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 16:27:38 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>

extern void	mlx_scroll_get(double deltax, double deltay, void *param);
extern void	mlx_mouse_pos(double x, double y, void *param);
extern void	mlx_mouse_press(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);

void	draw_pixel(t_image *set, int x, int y, int color)
{
	int			offset;
	uint8_t		*start;
	mlx_image_t	*img;

	img = set->data;
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	offset = (y * img->width + x) * sizeof(uint32_t);
	start = img->pixels + offset;
	*(uint32_t *)start = color;
}

void	mlx_event_start(t_machine *set)
{
	if (!set)
		return ;
	mlx_scroll_hook(set->plugin, &mlx_scroll_get, set);
	mlx_cursor_hook(set->plugin, &mlx_mouse_pos, set);
	mlx_mouse_hook(set->plugin, &mlx_mouse_press, set);
}
