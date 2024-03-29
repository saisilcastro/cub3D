/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:20:14 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/29 14:47:57 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_status	image_validate(t_map *level)
{
	if (access(level->textures[NO], R_OK) == -1)
		return (printf("Invalid \"NO\" image\n"), Off);
	if (access(level->textures[WE], R_OK) == -1)
		return (printf("Invalid \"EA\" image\n"), Off);
	if (access(level->textures[SO], R_OK) == -1)
		return (printf("Invalid \"SO\" image\n"), Off);
	if (access(level->textures[EA], R_OK) == -1)
		return (printf("Invalid \"WE\" image\n"), Off);
	return (On);
}
