/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:05 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/05 17:44:43 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <fcntl.h>
#include <libft.h>

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
	map->width = ft_strlen(arr[i]);
	while (arr[++i])
	{
		arr[i] = ft_strtrim(arr[i], "\n");
		if (ft_strlen(arr[i]) > map->width)
			map->width = ft_strlen(arr[i]);
	}
	map->height = i - j;
	map->map = &arr[j];
}

static char	*texture_breaker(char *texture, char *direction)
{
	texture = ft_strtrim(ft_strtrim(texture, direction), " ");
	return (ft_strdup(texture));
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
	while (*(array + ++i))
		free(*(array + i));
	free(array);
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

static t_status	check_map(char *map_fd, t_map *map)
{
	int		fd;
	int		i;
	char	buffer[65535];
	char	**arr;

	fd = open(map_fd, O_RDONLY);
	if (fd == -1)
		return ((printf("Invalid path")), Off);
	i = -1;
	read(fd, buffer, 65535);
	close(fd);
	arr = ft_split(buffer, '\n');
	if (arr[0] && *arr[0] && *arr[0] == '\n')
		return (printf("Empty map"), Off);
	while (arr[++i] && *arr[i] && On)
	{
		if (!checker(&map, &arr[i]))
			break ;
		free(arr[i]);
	}
	if (!parameters_validate(map))
		return (printf("Invalid parameters"), 0);
	get_map_size(map, arr, i);
	return (On);
}

int	check_input(int argc, char **argv)
{
	int		len;
	t_cub3d	*cub;

	if (argc != 2)
		return (printf("Invalid number of arguments"), 0);
	len = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", &argv[1][len], 4) != 0)
		return (printf("Invalid map file extension"), 0);
	cub = cub_get();
	cub_set(cub, argv[1]);
	if (!check_map(argv[1], cub->level))
		return (0);
	return (1);
}
