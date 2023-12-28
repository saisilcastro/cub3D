/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:20:48 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:33:09 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>

void	mlx_scroll_get(double xdelta, double ydelta, void *param)
{
	t_machine	*gear;

	gear = param;
	if (xdelta < 0.0)
		gear->mouse->s_wheel->left = 0;
	else
		gear->mouse->s_wheel->left = 1;
	if (ydelta < 0.0)
		gear->mouse->s_wheel->top = 0;
	else
		gear->mouse->s_wheel->top = 1;
}

void	mlx_mouse_pos(double x, double y, void *param)
{
	t_machine	*gear;

	gear = param;
	gear->mouse->pos->x = x;
	gear->mouse->pos->y = y;
}

void	mlx_mouse_press(mouse_key_t button,
		action_t action, modifier_key_t mods, void *param)
{
	t_machine	*gear;

	gear = param;
	if (action)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
			gear->mouse->button |= (1 << 0);
		if (button == MLX_MOUSE_BUTTON_MIDDLE)
			gear->mouse->button |= (1 << 1);
		if (button == MLX_MOUSE_BUTTON_RIGHT)
			gear->mouse->button |= (1 << 2);
	}
	else
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
			gear->mouse->button &= ~(1 << 0);
		if (button == MLX_MOUSE_BUTTON_MIDDLE)
			gear->mouse->button &= ~(1 << 1);
		if (button == MLX_MOUSE_BUTTON_RIGHT)
			gear->mouse->button &= ~(1 << 2);
	}
}
