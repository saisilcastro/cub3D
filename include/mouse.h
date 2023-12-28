/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:40:16 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:24:28 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <math_of.h>

struct s_mouse
{
	unsigned	button: 3;
	t_vi2d	pos[1];
	struct
	{
		unsigned	left: 1;
		unsigned	top: 1;
	}s_wheel[1];
};

#endif