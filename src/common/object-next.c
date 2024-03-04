/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:27:33 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 18:53:39 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_chained	*cub_object_push(int id, char *name, t_vf2d pos, t_image *image)
{
	return (chained_push(object_push(id, name, pos, image)));
}

t_object	*cub_object_search(int id)
{
	t_chained	*upd;
	t_object	*obj;

	upd = cub_get()->gear->object;
	while (upd)
	{
		obj = upd->data;
		if (obj && obj->id == id)
			return (obj);
		upd = upd->next;
	}
	return (NULL);
}

char	object_next_first(t_chained *object)
{
	return (chained_next_first(&cub_get()->gear->object, object));
}

char	object_next_last(t_chained *object)
{
	return (chained_next_last(&cub_get()->gear->object, object));
}
