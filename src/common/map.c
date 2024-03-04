/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:10:43 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/04 12:19:09 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_status	map_load(t_map *set, char *path)
{
	int	fd;

	if (!set)
		return (Off);
	fd = open(path);
	close(fd);
	return (On);
}
