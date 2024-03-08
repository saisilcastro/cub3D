/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:25:14 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/08 17:09:42 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_image	*image_push(int id, void *buffer)
{
	t_image	*set;

	set = malloc(sizeof(t_image));
	if (!set)
		return (NULL);
	set->id = id;
	set->buffer = buffer;
	return (set);
}

t_chained	*image_create(int id, t_vf2d size)
{
	t_image	*image;
	t_vi2d	area;

	area = vi2d_start(size.x, size.y);
	image = image_push(id, mlx_new_image(cub_get()->gear->plugin, area.x, area.y));
	return (chained_push(image));
}

t_image	*image_search(int id)
{
	t_chained	*update;
	t_image		*image;

	update = cub_get()->gear->image;
	while (update)
	{
		image = update->data;
		if (image && image->id == id)
			return (image);
		update = update->next;
	}
	return (NULL);
}

void	image_pop(void *data)
{
	t_image	*image;

	image = data;
	if (image->buffer)
		mlx_delete_image(cub_get()->gear->plugin, image->buffer);
	free(image);
}
