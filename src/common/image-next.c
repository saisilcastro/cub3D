/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:58:56 by mister-code       #+#    #+#             */
/*   Updated: 2024/02/28 14:28:35 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	image_next_first(t_chained *image)
{
	return (chained_next_first(&cub_get()->gear->image, image));
}

char	image_next_last(t_chained *image)
{
	t_status	status;

	status = chained_next_last(&cub_get()->gear->image, image);
	return (status);
}
