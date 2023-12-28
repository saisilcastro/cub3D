/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:29:03 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:13:44 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <math.h>

int	main(int argc, char **argv)
{
	t_cub	cub;

	cub_set(&cub, argv[1]);
	cub.init = user_init;
	cub.draw = user_draw;
	cub.update = user_update;
	cub.run(&cub, NULL);
	return (0);
}
