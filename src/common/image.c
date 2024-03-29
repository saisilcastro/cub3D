/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:22:39 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/25 12:25:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_image	*image_push(int id, void *img, void *tex)
{
	t_image	*graph;

	graph = (t_image *)malloc(sizeof(t_image));
	if (!graph)
		return (NULL);
	graph->img = img;
	graph->tex = tex;
	return (graph);
}

void	image_pop(void *data)
{
	t_image	*set;

	set = data;
	if (set->img)
		mlx_delete_image(cub_get()->mlx, set->img);
	if (set->tex)
		mlx_delete_texture(set->tex);
	free(set);
}
