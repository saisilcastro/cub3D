/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:33 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/07 17:22:36 by lumedeir         ###   ########.fr       */
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

t_status	check_map(char *map_fd, t_map *map)
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
		return (Off);
	get_map_size(map, arr, i);
	if (!character_validade(map->map))
		return (Off);
	return (On);
}
