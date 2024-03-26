/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-bonus-utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:34:55 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/25 14:36:35 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*texture_breaker(char *texture, char *direction)
{
	char	*str;
	char	*str2;

	str = ft_strtrim(texture, direction);
	str2 = ft_strtrim(str, " ");
	free(str);
	str = ft_strdup(str2);
	free(str2);
	return (str);
}

t_status	is_character_of_map(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (On);
	return (Off);
}

t_vd2d	player_start_point(t_map *set)
{
	int		i;
	int		size;
	t_vd2d	pos;

	pos = vd2d_start(0, 0);
	size = set->size->x * set->size->y;
	i = -1;
	while (++i < size)
	{
		pos.x = i % set->size->x;
		pos.y = i / set->size->x;
		if (set->map[(int)pos.y][(int)pos.x] == 'N' || \
			set->map[(int)pos.y][(int)pos.x] == 'E' || \
			set->map[(int)pos.y][(int)pos.x] == 'S' || \
			set->map[(int)pos.y][(int)pos.x] == 'W')
			return (pos);
	}
	return (pos);
}

t_status	map_solid(int x, int y)
{
	t_map	*level;

	level = cub_get()->level;
	if (!level || !level->map || x < 0 || y < 0)
		return (On);
	if (x >= level->size->x || y >= level->size->y)
		return (On);
	if (level->map[y][x] > 0)
		return (On);
	return (Off);
}

void	array_pop(char **arr)
{
	int		i;
	char	**temp;

	i = -1;
	temp = arr;
	while (temp[++i])
		free(temp[i]);
	free(arr);
}
