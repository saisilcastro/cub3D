/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:24:43 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:23:19 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

# include <math_of.h>

extern t_vf2d	line_make(t_vf2d b, t_vf2d e);
extern t_vf2d	angle_normalize(float degree);

#endif