/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:48:44 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/26 15:51:34 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math_of.h>
#include <math.h>

t_vi2d	vi2d_local(int x, int y)
{
	return ((t_vi2d){.x = x, .y = y});
}

t_vf2d	vf2d_local(float x, float y)
{
	return ((t_vf2d){.x = x, .y = y});
}
