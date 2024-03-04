/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:05 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/04 17:31:56 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_map_size(t_map *map, char **arr, int i)
{
	char	*copy;
	int		j;

	while (On)
	{
		copy = ft_strdup(arr[i]);
		copy = ft_strtrim(copy, " ");
		if (*copy != '\n')
			break ;
		free(arr[i++]);
	}
	j = i;
	map->map_width = ft_strlen(arr[i]);
	while (arr[++i])
	{
		arr[i] = ft_strtrim(arr[i], "\n");
		if (ft_strlen(arr[i]) > map->map_width)
			map->map_width = ft_strlen(arr[i]);
	}
	map->map_height = i - j;
	map->map = arr;
}

static char	*texture_breaker(char *texture, char *direction)
{
	return (ft_strdup(ft_strtrim(ft_strtrim(texture, direction), " ")));
}

static t_pixel	get_color(char *line)
{
	t_pixel	color;
	char	**array;

	array = NULL;
	array = ft_split(line, ',');
	color.r = ft_atoi(array[0]);
	color.g = ft_atoi(array[1]);
	color.b = ft_atoi(array[2]);
	color.a = 255;
	free(array);
	return (color);
}

static inline t_status	checker(t_map *map, char *texture)
{
	texture = ft_strtrim(texture, " ");
	if (texture && *texture && (!ft_strncmp(texture, "NO ", 3)
			|| !ft_strncmp(texture, "EA ", 3)
			|| !ft_strncmp(texture, "SO ", 3) || !ft_strncmp(texture, "WE ", 3)))
	{	
		if (!ft_strncmp(texture, "NO ", 3))
			map->textures[0] = texture_breaker(texture, "NO ");
		if (!ft_strncmp(texture, "EA ", 3))
			map->textures[1] = texture_breaker(texture, "EA ");
		if (!ft_strncmp(texture, "SO ", 3))
			map->textures[2] = texture_breaker(texture, "SO ");
		if (texture && *texture && !ft_strncmp(texture, "WE ", 3))
			map->textures[3] = texture_breaker(texture, "WE ");
		return (On);
	}
	if (texture && *texture && (!ft_strncmp(texture, "F ", 3)
			|| !ft_strncmp(texture, "C ", 3)))
	{
		if (!ft_strncmp(texture, "C ", 3))
			map->color[1] = get_color(texture_breaker(texture, "C "));
		if (!ft_strncmp(texture, "F ", 3))
			map->color[0] = get_color(texture_breaker(texture, "F "));
		return (On);
	}
	return (Off);
}

static t_status	parameters_validate(t_map *map)
{
	printf("%s\n", map->textures[0]);
	printf("%s\n", map->textures[1]);
	printf("%s\n", map->textures[2]);
	printf("%s\n", map->textures[3]);
	printf("%i\n", map->color[0].a);
	printf("%i\n", map->color[1].a);
	if (map->textures[0] == NULL || map->textures[1] == NULL
		|| map->textures[2] == NULL || map->textures[3] == NULL
		|| map->color[0].a == 0 || map->color[1].a == 0)
		return (Off);
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
		return ((perror("Invalid path")), 0);
	i = 0;
	read(fd, buffer, 65535);
	close(fd);
	arr = ft_split(buffer, '\n');
	while (On)
	{
		if (arr[i] && *arr[i] && *arr[i] != '\n' && !checker(map, arr[i]))
			break ;
		free(arr[i++]);
	}	
	if (!parameters_validate(map))
		return (perror("Invalid parameters"), 0);
	get_map_size(map, arr, i);
	return (On);
}

int	check_input(int argc, char **argv, t_map *map)
{
	int		len;

	if (argc != 2)
		return (perror("Invalid number of arguments"), 0);
	len = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", &argv[1][len], 4) != 0)
		return (perror("Invalid map file extension"), 0);
	if (!check_map(argv[1], map))
		return (0);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	static t_map	map;

// 	if (!check_input(argc, argv, &map))
// 		return (0);
// 	int i = 0;
// 	while (map.map[i])
// 		printf("%s\n", map.map[i++]);
// }