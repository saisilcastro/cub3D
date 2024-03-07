/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:00:59 by lumedeir          #+#    #+#             */
/*   Updated: 2024/03/05 13:59:50 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef enum e_status{
	Off,
	On
}t_status;

typedef struct s_chained	t_chained;
struct s_chained{
	void		*data;
	t_chained	*prev;
	t_chained	*next;
};

typedef struct s_pixel{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_pixel;

typedef struct s_map{
	char	**map;
	char	*textures[4];
	t_pixel	color[2];
	int		map_height;
	int		map_width;
}	t_map;

int	check_input(int argc, char **argv, t_map *map);

#endif