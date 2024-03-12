/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:25:16 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/12 12:20:35 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

inline static t_status	character_validade(t_map *level, char **map)
{
	int	i;
	int	j;
	int	count_player;

	i = -1;
	j = 0;
	count_player = 0;
	while (map[j])
	{
		while (map[j][++i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'N'
				&& map[j][i] != 'S' && map[j][i] != 'E' && map[j][i] != 'W'
					&& map[j][i] != ' ')
				return (printf("Invalid character\n"), Off);
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'E' || map[j][i] == 'W')
				check_player(level, count_player++, map[j][i]);
		}
		i = -1;
		j++;
	}
	if (count_player != 1)
		return (printf("Invalid number of players\n"), Off);
	return (On);
}

inline static t_status	parameters_validate(t_map *map)
{
	int	i;

	if (map->textures[0] == NULL || map->textures[1] == NULL
		|| map->textures[2] == NULL || map->textures[3] == NULL
		|| map->color[0].a == 0 || map->color[1].a == 0)
		return (printf("Invalid parameters\n"), Off);
	i = -1;
	while (++i < 4)
		if (ft_strncmp(".png", map->textures[i]
				+ (ft_strlen(map->textures[i]) - 4), 4) != 0)
			return (printf("Invalid texture extension\n"), Off);
	return (On);
}

inline static t_status	has_invalid_walls(char **map)
{
	int	l_index;
	int	c_index;

	l_index = 0;
	while (map[l_index])
	{
		c_index = 0;
		while (map[l_index][c_index])
		{
			if ((map[l_index][c_index] == '0'
				|| ft_strchr("NSEW", map[l_index][c_index]))
			&& ((l_index == 0 || !map[l_index + 1] || c_index == 0)
			|| !map[l_index][c_index + 1]
			|| map[l_index][c_index + 1] == ' '
			|| !map[l_index - 1][c_index]
			|| map[l_index - 1][c_index] == ' '
			|| !map[l_index][c_index - 1]
			|| map[l_index][c_index - 1] == ' '
			|| !map[l_index + 1][c_index] || map[l_index + 1][c_index] == ' '))
				return (printf("No closed map\n"), Off);
			c_index++;
		}
		l_index++;
	}
	return (On);
}

t_status	map_validate(t_map *level, char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		level->map[i] = array[i];
	level->map[i] = NULL;
	if (!parameters_validate(level) || !character_validade(level, level->map)
		|| !has_invalid_walls(level->map))
		return (Off);
	return (On);
}
