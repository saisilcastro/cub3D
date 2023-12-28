/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:17:10 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:29:31 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_OF_H
# define IMAGE_OF_H

# include <MLX42/MLX42.h>
# include <struct.h>

struct s_image
{
	void		*data;
	t_image		*next;
};

extern t_image	*image_push(void *data);
extern void		image_next_last(t_image **head, t_image *set);
extern void		image_pop(void *plugin, t_image **head);

#endif