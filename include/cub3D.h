/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:29:23 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 04:27:30 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <level.h>
# include <machine.h>

typedef struct s_cub	t_cub;
struct s_cub
{
	t_level		area[1];
	t_machine	gear[1];
	void		(*init)(t_cub *set, void *data);
	t_vi2d		(*mouse_pos)(t_cub * set);
	void		(*update)(void *set);
	void		(*draw)(t_cub *set);
	void		(*show)(void *set);
	void		(*run)(t_cub *set, void *data);
	void		(*pop)(t_cub *set);
};

extern void	cub_set(t_cub *set, char *level);
extern void	user_init(t_cub *set, void *data);
extern void	user_draw(t_cub *set);
extern void	user_update(void *set);
extern void	cub_run(t_cub *set, void *data);
extern void	cub_pop(t_cub *set);

#endif