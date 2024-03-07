/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:13:12 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/07 17:32:51 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*texture_breaker(char *texture, char *direction)
{
	char	*str;

	texture = ft_strtrim(texture, direction);
	texture = ft_strtrim(texture, " ");
	str = ft_strdup(texture);
	free(texture);
	return (str);
}

static t_pixel	get_color(char *line)
{
	t_pixel	color;
	char	**array;
	int		i;

	array = NULL;
	array = ft_split(line, ',');
	color.r = ft_atoi(array[0]);
	color.g = ft_atoi(array[1]);
	color.b = ft_atoi(array[2]);
	color.a = 255;
	i = -1;
	while (++i < 4)
		free(array[i]);
	free(array);
	free(line);
	return (color);
}

t_status	checker(t_map **map, char **texture)
{
	*texture = ft_strtrim(*texture, " ");
	if (!ft_strncmp(*texture, "NO ", 3) || !ft_strncmp(*texture, "EA ", 3)
		|| !ft_strncmp(*texture, "SO ", 3) || !ft_strncmp(*texture, "WE ", 3))
	{	
		if (!ft_strncmp(*texture, "NO ", 3))
			(*map)->textures[0] = texture_breaker(*texture, "NO ");
		else if (!ft_strncmp(*texture, "EA ", 3))
			(*map)->textures[1] = texture_breaker(*texture, "EA ");
		else if (!ft_strncmp(*texture, "SO ", 3))
			(*map)->textures[2] = texture_breaker(*texture, "SO ");
		else if (!ft_strncmp(*texture, "WE ", 3))
			(*map)->textures[3] = texture_breaker(*texture, "WE ");
		return (On);
	}
	if (!ft_strncmp(*texture, "F ", 2) || !ft_strncmp(*texture, "C ", 2))
	{
		if (!ft_strncmp(*texture, "C ", 2))
			(*map)->color[1] = get_color(texture_breaker(*texture, "C "));
		else if (!ft_strncmp(*texture, "F ", 2))
			(*map)->color[0] = get_color(texture_breaker(*texture, "F "));
		return (On);
	}
	return (Off);
}

t_status	parameters_validate(t_map *map)
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

int	check_input(int argc, char **argv, t_map *map)
{
	int		len;

	if (argc != 2)
		return (printf("Invalid number of arguments\n"), 0);
	len = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", &argv[1][len], 4) != 0)
		return (printf("Invalid map file extension\n"), 0);
	if (!check_map(argv[1], map))
		return (0);
	return (1);
}
