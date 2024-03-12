/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:34:55 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/08 16:38:12 by lumedeir         ###   ########.fr       */
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
