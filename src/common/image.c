/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:25:14 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/11 15:42:07 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_image	*image_push(int id, void *image, void *texture)
{
	t_image	*set;

	set = malloc(sizeof(t_image));
	if (!set)
		return (NULL);
	set->id = id;
	set->image = image;
	set->texture = texture;
	return (set);
}

t_chained	*image_create(int id, t_vf2d size)
{
	t_image	*image;
	t_vi2d	a;

	a = vi2d_start(size.x, size.y);
	image = image_push(id,
			mlx_new_image(cub_get()->gear->plugin, a.x, a.y), NULL);
	return (chained_push(image));
}

t_chained	*image_load(int id, char *path)
{
	t_image	*image;

	image = image_push(id, NULL, mlx_load_png(path));
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
	t_image	*set;

	set = data;
	if (set->image)
		mlx_delete_image(cub_get()->gear->plugin, set->image);
	if (set->texture)
		mlx_delete_image(cub_get()->gear->plugin, set->texture);
	free(set);
}
