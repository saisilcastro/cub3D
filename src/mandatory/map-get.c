/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:05 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/13 18:45:25 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

inline static t_status	get_map_size(t_map *level)
{
	int		i;
	char	*line;

	i = -1;
	while (level->map[++i])
	{
		line = ft_strtrim(level->map[i], "\n");
		if (ft_strlen(line) > level->size->x)
			level->size->x = ft_strlen(line);
		free(line);
		level->size->y++;
	}
	return (On);
}

inline static t_pixel	get_color(char *line)
{
	t_pixel	color;
	char	**array;
	int		i;

	array = NULL;
	array = ft_split(line, ',');
	i = -1;
	while (*(array + ++i))
	{
		if (i == 0)
			color.r = ft_atoi(array[i]);
		else if (i == 1)
			color.g = ft_atoi(array[i]);
		else if (i == 2)
			color.b = ft_atoi(array[i]);
		free(array[i]);
	}	
	color.a = 255;
	free(array);
	free(line);
	return (color);
}

inline static t_status	checker(t_map *map, char **texture)
{
	char		*line;
	t_status	ok;

	if (!map)
		return (Off);
	ok = Off;
	line = ft_strtrim(*texture, " ");
	if (is_character_of_map(line))
	{	
		if (!ft_strncmp(line, "NO ", 3))
			map->textures[0] = texture_breaker(line, "NO ");
		else if (!ft_strncmp(line, "EA ", 3))
			map->textures[1] = texture_breaker(line, "EA ");
		else if (!ft_strncmp(line, "SO ", 3))
			map->textures[2] = texture_breaker(line, "SO ");
		else if (!ft_strncmp(line, "WE ", 3))
			map->textures[3] = texture_breaker(line, "WE ");
		else if (!ft_strncmp(line, "C ", 2))
			map->color[1] = get_color(texture_breaker(*texture, "C "));
		else if (!ft_strncmp(*texture, "F ", 2))
			map->color[0] = get_color(texture_breaker(*texture, "F "));
		ok = On;
	}
	free(line);
	return (ok);
}

t_status	get_map(char *map_fd, t_map *level)
{
	int		fd;
	int		i;
	char	buffer[65535];
	char	**array;

	fd = open(map_fd, O_RDONLY);
	if (fd == -1)
		return ((printf("Invalid path\n")), Off);
	i = read(fd, buffer, 65535);
	close(fd);
	buffer[i] = '\0';
	level->map = ft_split(buffer, '\n');
	if (!level->map || !level->map[0] || !level->map[0][0])
		return (printf("Empty map\n"), Off);
	i = -1;
	while (level->map[++i] && *level->map[i] && On)
	{
		if (!checker(level, &level->map[i]))
			break ;
		free(level->map[i]);
	}
	array = &level->map[i];
	if (!map_validate(level, array) || !get_map_size(level))
		return (Off);
	return (On);
}

int	check_input(int argc, char **argv)
{
	int		len;

	if (argc != 2)
		return (printf("Invalid number of arguments\n"), 0);
	len = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", &argv[1][len], 4) != 0)
		return (printf("Invalid map file extension\n"), 0);
	if (access(argv[1], R_OK) == -1)
		return (printf("Access not granted\n"), 0);
	return (1);
}
