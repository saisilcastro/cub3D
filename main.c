/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/05 17:45:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	if (check_input(argc, argv))
	{
		char	**map;
		map = cub_get()->level->map;
		while (*map)
		{
			printf("%s\n", *map);
			map++;
		}
		//cub_get()->init = user_init;
		//cub_get()->update = user_update;
		//cub_get()->draw = user_draw;
		cub_get()->run(cub_get(), NULL);
	}
	return (0);
}
