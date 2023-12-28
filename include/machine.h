/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:40:10 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:33:56 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

# include <MLX42/MLX42.h>
# include <struct.h>
# include <math_of.h>
# include <mouse.h>
# include <pixel.h>
# include <primitive.h>
# include <object.h>
# include <mlx_plugin.h>
# include <stdio.h>

enum e_status
{
	Off,
	On
};

struct s_machine
{
	char		*title;
	t_vf2d		size[1];
	t_vf2d		pos[1];
	t_status	key[MLX_KEY_MENU];
	t_mouse		mouse[1];
	mlx_t		*plugin;
	t_image		*image;
	t_object	map[1];
	t_object	*object;
	t_status	(*start)(t_machine *set, t_status resize);
	void		(*pop)(t_machine *set);
};

extern void	machine_set(t_machine *gear, char *title, t_vf2d size, t_vf2d pos);

#endif