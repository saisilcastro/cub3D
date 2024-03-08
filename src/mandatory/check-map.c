/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:05 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/08 15:20:12 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <fcntl.h>
#include <libft.h>

static void	get_map_size(t_map *level)
{
	int		i;
	char	*line;

	i = -1;
	while (level->map[++i])
	{
		line = ft_strtrim(level->map[i], "\n");
		if (ft_strlen(line) > level->width)
			level->width = ft_strlen(line);
		free(line);
		level->height++;
	}
}

static char	*texture_breaker(char *texture, char *direction)
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

static t_pixel	get_color(char *line)
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

static inline t_status	checker(t_map *map, char **texture)
{
	char		*line;
	t_status	ok;

	if (!map)
		return (Off);
	ok = Off;
	line = ft_strtrim(*texture, " ");
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3))
	{	
		if (!ft_strncmp(line, "NO ", 3))
			map->textures[0] = texture_breaker(line, "NO ");
		else if (!ft_strncmp(line, "EA ", 3))
			map->textures[1] = texture_breaker(line, "EA ");
		else if (!ft_strncmp(line, "SO ", 3))
			map->textures[2] = texture_breaker(line, "SO ");
		else if (!ft_strncmp(line, "WE ", 3))
			map->textures[3] = texture_breaker(line, "WE ");
		ok = On;
	}
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
	{
		if (!ft_strncmp(line, "C ", 2))
			map->color[1] = get_color(texture_breaker(*texture, "C "));
		else if (!ft_strncmp(*texture, "F ", 2))
			map->color[0] = get_color(texture_breaker(*texture, "F "));
		ok = On;
	}
	free(line);
	return (ok);
}

static t_status	parameters_validate(t_map *map)
{
	if (map->textures[0] == NULL || map->textures[1] == NULL
		|| map->textures[2] == NULL || map->textures[3] == NULL
		|| map->color[0].a == 0 || map->color[1].a == 0)
		return (Off);
	return (On);
}

// static t_status	character_validade(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = 0;
// 	while (map[j][i--])
// 	{
// 		while (map[j][++i])
// 			if (map[j][i] != '0' && map[j][i] != '1'
// 				&& map[j][i] != 'N' && map[j][i] != 'S'
// 					&& map[j][i] != 'E' && map[j][i] != 'W' && map[j][i] != ' ')
// 				return (printf("Invalid character\n"), Off);
// 		i = 0;
// 		j++;
// 	}
// 	return (On);
// }

t_status	check_map(char *map_fd, t_map *level)
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
	i = -1;
	while (array[++i])
		level->map[i] = array[i];
	level->map[i] = NULL;
	if (!parameters_validate(level))
		return (printf("Invalid parameters\n"), 0);
	get_map_size(level);
	//character_validade(level->map);
	return (On);
}

int	check_input(int argc, char **argv)
{
	int		len;

	if (argc != 2)
		return (printf("Invalid number of arguments"), 0);
	len = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", &argv[1][len], 4) != 0)
		return (printf("Invalid map file extension"), 0);
	if (access(argv[1], R_OK) == -1)
		return (printf("Access not granted\n"), 0);
	return (1);
}
