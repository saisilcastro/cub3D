/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:10:43 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/03 17:28:16 by mister-code      ###   ########.fr       */
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
}