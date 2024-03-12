/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:52:33 by mister-code       #+#    #+#             */
/*   Updated: 2024/02/29 00:01:37 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_chained	*cub_object_push(int id, char *name, t_vf2d pos, t_image *img)
{
	return (chained_push(object_push(id, name, pos, img)));
}

char	object_next_first(t_chained *object)
{
	return (chained_next_first(&cub_get()->gear->object, object));
}

char	object_next_last(t_chained *object)
{
	return (chained_next_last(&cub_get()->gear->object, object));
}

t_object	*object_search(int id)
{
	t_chained	*update;
	t_object	*object;

	update = cub_get()->gear->object;
	while (update)
	{
		object = update->data;
		if (object && object->id == id)
			return (object);
		update = update->next;
	}
	return (NULL);
}
