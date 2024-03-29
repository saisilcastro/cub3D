/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector-vi2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:32:30 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:32:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vi2d	vi2d_start(int x, int y)
{
	return ((t_vi2d){x, y});
}

int	vi2d_limit(t_vi2d *set, t_vi2d b, t_vi2d e)
{
	if (set->x <= b.x)
	{
		set->x = b.x;
		return (0);
	}
	if (set->x >= e.x)
	{
		set->x = e.x;
		return (0);
	}
	if (set->y <= b.y)
	{
		set->y = b.y;
		return (0);
	}
	if (set->y >= e.y)
	{
		set->y = e.y;
		return (0);
	}
	return (1);
}

void	vi2d_show(t_vi2d *set, char *x, char *y)
{
	if (x == NULL)
		x = "x:";
	if (y == NULL)
		y = "y:";
	printf("%s %i %s %i\n", x, set->x, y, set->y);
}
