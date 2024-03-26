/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-bonus-validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:19:23 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/26 14:09:03 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

inline static t_status	char_ok(t_map *level,
	char **map, int count_player)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (count_player != 1)
		return (printf("Invalid number of players\n"), Off);
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
	return (On);
}

inline static t_status	param_ok(t_map *map)
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

inline static t_status	invalid_walls(char **map)
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

t_status	map_validate(t_map *lv, char **arr)
{
	t_vi2d	p;
	int		cp;

	p.y = -1;
	cp = 0;
	lv->map = ft_calloc(lv->size->y + 1, sizeof(uint32_t *));
	while (arr[++p.y])
	{
		lv->map[p.y] = ft_calloc(lv->size->x, sizeof(uint32_t));
		p.x = -1;
		while (++p.x < lv->size->x)
			lv->map[p.y][p.x] = -1;
		p.x = -1;
		while (arr[p.y][++p.x])
		{
			if (special_char(arr[p.y][p.x]))
					cp += swap_char(cub_get(), arr[p.y], p.y);
			if (ft_isdigit(arr[p.y][p.x]))
				lv->map[p.y][p.x] = arr[p.y][p.x] - 0x30;
		}
	}
	lv->map[p.y] = NULL;
	if (!param_ok(lv) || !char_ok(lv, arr, cp) || !invalid_walls(arr))
		return (Off);
	return (On);
}
