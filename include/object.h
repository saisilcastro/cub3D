/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:27:31 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:23:02 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <math_of.h>
# include <image_of.h>

struct s_object
{
	int			id;
	char		*name;
	t_vf2d		pos[1];
	t_vf2d		dest[1];
	t_vf2d		vel[1];
	float		angle;
	t_image		*image;
	t_object	*next;
};

extern t_object	object_start(int id, char *name, t_vf2d pos, t_image *image);
extern t_object	*object_push(int id, char *name, t_vf2d pos, t_image *image);
extern void		object_next_last(t_object **head, t_object *set);
extern void		object_angle_limit(t_object *set, t_vf2d size);
extern t_vf2d	object_angle_end(t_object *obj, t_vf2d begin, t_vf2d size);
extern void		object_pop(t_object **head);

#endif