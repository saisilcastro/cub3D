/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_of.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:42:19 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:20:21 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_OF_H
# define MATH_OF_H

# include <struct.h>

struct s_vi2d
{
	int	x;
	int	y;
};

extern t_vi2d	vi2d_local(int x, int y);

struct s_vf2d
{
	float	x;
	float	y;
};

extern t_vf2d	vf2d_local(float x, float y);
extern t_vf2d	line_angle_get(float *angle, t_vf2d size);
extern t_vf2d	line_angle_end(t_vf2d begin, t_vf2d vel);

extern float	degree_to_rad(float angle);
extern float	angle_limit(float angle);

#endif