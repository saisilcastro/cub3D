/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:25:56 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:25:56 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	deg_to_rad(float angle)
{
	float	value;

	value = angle * M_PI / 180.0;
	if (value >= -(M_PI + M_PI) && value <= M_PI + M_PI)
		return (value);
	return (0);
}
