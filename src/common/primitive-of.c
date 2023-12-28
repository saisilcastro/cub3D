/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive-of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:23:23 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 21:55:47 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <primitive.h>
#include <math.h>

t_vf2d	line_make(t_vf2d b, t_vf2d e)
{
	static double	step;
	static t_vf2d	way;

	step += 0.001;
	way.x = (1.0 - step) * b.x + step * e.x;
	way.y = (1.0 - step) * b.y + step * e.y;
	if (step > 1.0)
		step = 0.0;
	return (way);
}

t_vf2d	angle_normalize(float degree)
{
	t_vf2d	angle;

	angle = vf2d_local(1, 0);
	if (degree > 0 && degree < 90)
	{
		angle.x = 1 - (degree) / 90;
		angle.y = (1 - angle.x);
	}
	else if (degree >= 90 && degree < 180)
	{
		angle.x = ((90 - degree)) / 90;
		angle.y = (1 + angle.x);
	}
	else if (degree >= 180 && degree < 270)
	{
		angle.x = ((degree - 270)) / 90;
		angle.y = -(angle.x + 1);
	}
	else if (degree >= 270 && degree <= 360)
	{
		angle.x = ((degree - 270)) / 90;
		angle.y = ((1 - angle.x) * -1);
	}
	return (angle);
}
