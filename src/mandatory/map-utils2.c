/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:20:14 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/29 10:17:31 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_status	image_validate(t_map *level)
{
	if (access(level->textures[NO], R_OK) == -1)
		return (printf("Invalid \"NO\" image\n"), 0);
	if (access(level->textures[WE], R_OK) == -1)
		return (printf("Invalid \"EA\" image\n"), 0);
	if (access(level->textures[SO], R_OK) == -1)
		return (printf("Invalid \"SO\" image\n"), 0);
	if (access(level->textures[EA], R_OK) == -1)
		return (printf("Invalid \"WE\" image\n"), 0);
	return (On);
}
