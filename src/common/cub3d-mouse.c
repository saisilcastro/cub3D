/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:11:07 by mister-code       #+#    #+#             */
/*   Updated: 2024/02/28 23:53:54 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vi2d	*cub_mouse_pos()
{
	return (cub_get()->gear->mouse->pos);
}

char	cub_mouse_press(t_mouse_status button)
{
	return (cub_get()->gear->mouse->button & (1 << button));
}
