/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/03 16:06:53 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_cub3d	*cub;

	if (argc == 2)
	{
		cub = cub_get();
		cub_set(cub, argv[1]);
		cub->init = user_init;
		cub->update = user_update;
		cub->draw = user_draw;
		cub->run(cub, NULL);
	}
	return (0);
}
