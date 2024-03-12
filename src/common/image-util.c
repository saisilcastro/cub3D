/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:11:02 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/11 17:18:05 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vi2d	image_size(t_image *set)
{
	t_vi2d	size;

	if (!set)
		return ((t_vi2d){0, 0});
	if (set->image)
	{
		size.x = ((mlx_image_t *)set->image)->width;
		size.y = ((mlx_image_t *)set->image)->height;
	}
	else if (set->texture)
	{
		size.x = ((mlx_texture_t *)set->texture)->width;
		size.y = ((mlx_texture_t *)set->texture)->height;
	}
	return (size);
}
