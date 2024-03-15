/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:34:55 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/14 22:46:06 by mister-code      ###   ########.fr       */
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

void	check_player(t_map *level, int count_player, char c)
{
	(void)count_player;
	if (c == 'N')
		level->fov = 90;
	if (c == 'E')
		level->fov = 0;
	if (c == 'S')
		level->fov = 270;
	if (c == 'W')
		level->fov = 180;
}

t_status	is_character_of_map(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (On);
	return (Off);
}

t_vf2d	player_vector_pos(t_map *set)
{
	int		i;
	int		size;
	t_vf2d	pos;

	pos = vf2d_start(0, 0);
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
