/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:13:12 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/07 16:38:18 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_map_size(t_map *map, char **arr, int i)
{
	int		j;

	j = i;
	map->map_width = ft_strlen(arr[i]);
	while (arr[++i])
	{
		arr[i] = ft_strtrim(arr[i], "\n");
		if (ft_strlen(arr[i]) > map->map_width)
			map->map_width = ft_strlen(arr[i]);
	}
	map->map_height = i - j;
	map->map = &arr[j];
}

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

static inline t_status	checker(t_map **map, char **texture)
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

static t_status	parameters_validate(t_map *map)
{
	if (map->textures[0] == NULL || map->textures[1] == NULL
		|| map->textures[2] == NULL || map->textures[3] == NULL
		|| map->color[0].a == 0 || map->color[1].a == 0)
		return (Off);
	return (On);
}

static t_status	character_validade(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1'
				&& map[j][i] != 'N' && map[j][i] != 'S'
					&& map[j][i] != 'E' && map[j][i] != 'W' && map[j][i] != ' ')
				return (printf("Invalid character\n"), Off);
			i++;
		}
		i = 0;
		j++;
	}
	return (On);
}

static t_status	check_map(char *map_fd, t_map *map)
{
	int		fd;
	int		i;
	char	buffer[65535];
	char	**arr;

	fd = open(map_fd, O_RDONLY);
	if (fd == -1)
		return ((printf("Invalid path\n")), Off);
	i = read(fd, buffer, 65535);
	close(fd);
	buffer[i] = '\0';
	i = -1;
	arr = ft_split(buffer, '\n');
	if (arr[0] && *arr[0] && *arr[0] == '\n')
		return (printf("Empty map\n"), Off);
	while (arr[++i] && *arr[i] && On)
		if (!checker(&map, &arr[i]))
			break ;
	if (!parameters_validate(map))
		return (printf("Invalid parameters\n"), 0);
	get_map_size(map, arr, i);
	character_validade(map->map);
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
