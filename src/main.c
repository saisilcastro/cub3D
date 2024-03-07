/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:00:03 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/07 15:55:20 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	pop_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->textures[i])
		while (++i < 4)
			free(map->textures[i]);
	i = -1;
	if (map->map)
		while (map->map[++i])
			free(map->map[i]);
}

int	main(int argc, char **argv)
{
	static t_map	map;

	if (!check_input(argc, argv, &map))
		return (0);
	pop_map(&map);
}
