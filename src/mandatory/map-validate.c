/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:34:54 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/29 14:46:05 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

inline static t_status	character_validade(t_map *level, char
	**map, int count_player)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[j])
	{
		while (map[j][++i])
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'N'
				&& map[j][i] != 'S' && map[j][i] != 'E' && map[j][i] != 'W'
					&& map[j][i] != ' ')
				return (printf("Invalid character\n"), Off);
		i = -1;
		j++;
	}
	if (count_player != 1)
		return (printf("Invalid number of players\n"), Off);
	return (On);
}

inline static t_status	parameters_validate(t_map *map)
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

inline static t_status	has_invalid_walls(char **map)
{
	int	l_index;
	int	c_index;

	l_index = 0;
	while (map[l_index])
	{
		c_index = 0;
		while (map[l_index][c_index])
		{
			if ((map[l_index][c_index] == '0'
				|| ft_strchr("NSEW", map[l_index][c_index]))
			&& ((l_index == 0 || !map[l_index + 1] || c_index == 0)
			|| !map[l_index][c_index + 1]
			|| map[l_index][c_index + 1] == ' '
			|| !map[l_index - 1][c_index]
			|| map[l_index - 1][c_index] == ' '
			|| !map[l_index][c_index - 1]
			|| map[l_index][c_index - 1] == ' '
			|| !map[l_index + 1][c_index] || map[l_index + 1][c_index] == ' '))
				return (printf("No closed map\n"), Off);
			c_index++;
		}
		l_index++;
	}
	return (On);
}

inline static int	swap_char(t_game *game, char *swap, int j)
{
	int		i;

	i = -1;
	while (swap[++i])
	{
		if (swap[i] == 'N' || swap[i] == 'S'
			|| swap[i] == 'E' || swap[i] == 'W')
		{
			if (swap[i] == 'N')
				game->player->angle = deg_to_rad(90);
			else if (swap[i] == 'S')
				game->player->angle = deg_to_rad(270);
			else if (swap[i] == 'E')
				game->player->angle = deg_to_rad(0);
			else if (swap[i] == 'W')
				game->player->angle = deg_to_rad(180);
			*(game->player->pos) = vd2d_start(i, j);
			swap[i] = '0';
			return (1);
		}
	}
	return (0);
}

t_status	map_validate(t_map *lv, char **array)
{
	int	i;
	int	j;
	int	count_player;

	j = -1;
	count_player = 0;
	lv->map = ft_calloc(lv->size->y + 1, sizeof(uint32_t *));
	while (array[++j])
	{
		lv->map[j] = ft_calloc(lv->size->x, sizeof(uint32_t));
		ft_memset(lv->map[j], -1, lv->size->x * sizeof(uint32_t));
		i = -1;
		while (array[j][++i])
		{
			if (special_char(array[j][i]))
					count_player += swap_char(cub_get(), array[j], j);
			if (ft_isdigit(array[j][i]))
				lv->map[j][lv->size->x - i - 1] = array[j][i] - 0x30;
		}
	}
	lv->map[j] = NULL;
	if (!parameters_validate(lv) || !character_validade(lv, array, count_player)
		|| !has_invalid_walls(array) || !image_validate(lv))
		return (Off);
	return (On);
}
