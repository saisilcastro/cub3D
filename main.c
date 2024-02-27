/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:00:12 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/27 17:28:51 by lde-cast         ###   ########.fr       */
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
