/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 03:54:08 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 20:23:24 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# include <machine.h>

struct s_level
{
	char	*texture[4];	
	t_pixel	color[2];
	char	*data;
};

extern t_status	level_load(t_level *set, char *file);

#endif