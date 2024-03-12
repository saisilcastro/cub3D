/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:11:07 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/05 17:03:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vi2d	*cub_mouse_pos(void)
{
	return (cub_get()->gear->mouse->pos);
}

char	cub_mouse_press(t_mouse_status button)
{
	return (cub_get()->gear->mouse->button & (1 << button));
}
