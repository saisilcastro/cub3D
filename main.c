/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:36:39 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/25 12:36:52 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vi2d	line_v(t_game *game, double wall_dist, int pitch)
{
	int		line_height;
	t_vi2d	line;

	line_height = game->size->y / wall_dist;
	line.x = ((game->size->y - line_height) * 0.5) + pitch;
	line.y = line.x + line_height;
	if (line.x < 0)
		line.x = 0;
	if (line.y >= game->size->y)
		line.y = game->size->y - 1;
	return (line);
}

int	main(int argc, char **argv)
{
	t_game	*cub;

	if (check_input(argc, argv))
	{
		cub = cub_get();
		if (get_map(argv[1], cub->level))
			cub->status |= 1 << MACHINE_RUNNING;
		game_start(cub);
		game_pop(cub);
	}
	return (0);
}
