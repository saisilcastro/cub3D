/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:37:16 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/12 17:55:35 by lde-cast         ###   ########.fr       */
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

int	calculate_rx(float px, int blocksize)
{
	int	shiftamount;
	int	blockmask;

	shiftamount = 0;
	blockmask = 0;
	while ((1 << shiftamount) < blocksize)
		shiftamount++;
	blockmask = (1 << shiftamount) - 1;
	return ((int)(px / blocksize) & ~blockmask) + blocksize;
}
