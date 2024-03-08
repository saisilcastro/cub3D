/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/08 14:50:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_cub3d	*cub;

	if (check_input(argc, argv))
	{
		cub = cub_get();
		if (check_map(argv[1], cub_get()->level))
			cub_get()->gear->status = 0x1;
		cub_set(cub);
		cub_get()->init = user_init;
		cub_get()->update = user_update;
		cub_get()->draw = user_draw;
		cub_get()->run(cub_get(), NULL);
	}
	return (0);
}
