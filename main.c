/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 01:06:32 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(void)
{
	t_cub3d	*cub;

	cub = cub_get();
	cub_set(cub, NULL);
	cub->init = user_init;
	cub->update = user_update;
	cub->draw = user_draw;
	cub->run(cub, NULL);
	return (0);
}
