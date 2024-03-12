/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:16 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/29 07:08:18 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	degree_to_rad(float angle)
{
	return (angle * M_PI / 180.0);
}

t_vi2d	vi2d_start(int x, int y)
{
	return ((t_vi2d){x, y});
}

t_vf2d	vf2d_start(float x, float y)
{
	return ((t_vf2d){x, y});
}