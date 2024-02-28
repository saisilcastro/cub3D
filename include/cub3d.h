/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:03:37 by lde-cast          #+#    #+#             */
/*   Updated: 2024/02/28 01:27:11 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
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

extern t_chained	*chained_push(void *data);
extern t_status		chained_next_first(t_chained **head, t_chained *set);
extern t_status		chained_next_last(t_chained **head, t_chained *set);
extern void			chained_pop(t_chained **head, void (*pop)(void *data));

extern float		degree_to_rad(float angle);

typedef struct s_vi2d		t_vi2d;
struct s_vi2d
{
	int	x;
	int	y;
};

extern t_vi2d		vi2d_start(int x, int y);

typedef struct s_vf2d		t_vf2d;
struct s_vf2d
{
	float	x;
	float	y;
};

extern t_vf2d		vf2d_start(float x, float y);

enum e_mouse_status
{
	MOUSE_LEFT,
	MOUSE_MIDDLE,
	MOUSE_RIGHT
};

typedef struct s_image		t_image;
struct s_image
{
	int		id;
	void	*buffer;
};

extern t_image	*image_push(int id, void *buffer);

enum e_object{
	OBJECT_PUSH,
	OBJECT_VISIBLE
};

typedef struct s_object		t_object;
struct s_object
{
	int				id;
	char			*name;
	t_vf2d			pos[1];
	t_vf2d			vel[1];
	t_vf2d			zoom[1];
	float			angle;
	t_image			*image;
	unsigned char	status:2;
};

extern t_object		object_start(int id, char *name, t_vf2d pos, t_image *i);
extern t_object		*object_push(int id, char *name, t_vf2d pos, t_image *i);
extern void			object_pop(void *set);

typedef struct s_mouse		t_mouse;
struct s_mouse{
	unsigned char	button:3;
	t_vi2d			pos[1];
	struct{
		unsigned char	top: 1;
		unsigned char	left: 1;
	}s_wheel[1];
};

typedef struct s_machine	t_machine;
struct s_machine
{
	t_vi2d		pos[1];
	t_vf2d		size[1];
	char		*title;
	t_mouse		mouse[1];
	t_status	key[255];
	t_object	map[1];
	t_chained	*image;
	t_chained	*object;
	void		*plugin;
	char		(*start)(t_machine *set, t_status resize);
	void		(*pop)(t_machine *set);
};

extern void			machine_set(t_machine *set, char *t, t_vi2d p, t_vf2d s);

typedef struct s_cub3d		t_cub3d;
struct s_cub3d
{
	t_machine	gear[1];
	void		(*init)(t_cub3d *set, void *data);
	t_chained	*(*image_create)(int id, t_vf2d size);
	t_image		*(*image_search)(int id);
	char		(*image_next_first)(t_chained *set);
	char		(*image_next_last)(t_chained *set);
	void		(*map_set)(int id);
	t_vi2d		*(*mouse_pos)();
	void		(*update)(void *set);
	void		(*draw)(t_cub3d *set);
	void		(*show)(void *set);
	void		(*run)(t_cub3d *set, void *data);
	void		(*pop)(t_cub3d *set);
};

extern t_cub3d		*cub_get(void);
extern void			cub_set(t_cub3d *set, char *level);
extern void			cub_run(t_cub3d *set, void *data);
extern void			cub_pop(t_cub3d *set);

// plugin function
extern void			mlx_event_start(t_machine *set);
extern void			draw_pixel(t_image *img, int x, int y, int color);
extern void			mlx_image_clear(t_image *set, int color);
extern void			mlx_draw_line(t_chained *set, t_vf2d b, t_vf2d e, int color);
extern void			mlx_draw_rect(t_chained *set, t_vf2d b, t_vf2d e, int color);
extern void			mlx_draw_fill_rect(t_chained *set, t_vf2d b, t_vf2d size, int color);

extern void			ray_cast(t_object *obj, t_chained *img, t_vf2d size, char *map);

// user function
extern void			user_init(t_cub3d *set, void *data);
extern void			user_update(void *data);
extern void			user_draw(t_cub3d *set);

#endif