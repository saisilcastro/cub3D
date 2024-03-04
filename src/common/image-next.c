/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:58:56 by mister-code       #+#    #+#             */
/*   Updated: 2024/02/27 23:52:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char    image_next_first(t_chained *image)
{
	return (chained_next_first(&cub_get()->gear->image, image));
}

char    image_next_last(t_chained *image)
{
	t_status	status;

	status = chained_next_last(&cub_get()->gear->image, image);
	return (status);
}
