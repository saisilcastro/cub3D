/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:03:37 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/15 00:07:49 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

typedef enum e_status{
	Off,
	On
}t_status;

typedef struct s_pixel{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_pixel;

extern int			pixel_to_int(t_pixel *set);
extern uint32_t		texture_to_int(mlx_texture_t *a, int x, int y);
extern t_pixel		int_to_pixel(unsigned int color);

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

extern float		deg_to_rad(float angle);

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

typedef struct s_delta_f	t_delta_f;
struct s_delta_f{
	t_vf2d	b[1];
	t_vf2d	e[1];
};

typedef struct s_delta_i	t_detal_i;
struct s_delta_i{
	t_vi2d	b[1];
	t_vi2d	e[1];
};

typedef struct s_map{
	char	**map;
	char	*textures[4];
	float	fov;
	t_vi2d	size[1];
	t_vf2d	block[1];
	t_pixel	color[2];
}	t_map;

extern t_status		get_map(char *map_fd, t_map *map);
extern int			check_input(int argc, char **argv);
extern t_status		is_character_of_map(char *line);
extern void			check_player(t_map *level, int count_player, char c);
extern char			*texture_breaker(char *texture, char *direction);
extern t_status		map_validate(t_map *level, char **array);
extern t_vf2d		player_vector_pos(t_map *set);

typedef enum e_mouse_status
{
	MOUSE_LEFT,
	MOUSE_MIDDLE,
	MOUSE_RIGHT
}t_mouse_status;

typedef struct s_image		t_image;
struct s_image
{
	int		id;
	void	*image;
	void	*texture;
};

extern t_image		*image_push(int id, void *image, void *texture);

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
	t_vf2d			route[1];
	t_vf2d			vel[1];
	t_vf2d			size[1];
	t_vf2d			zoom[1];
	float			angle;
	t_image			*a;
	unsigned char	status:2;
};

extern t_object		object_start(int id, char *name, t_vf2d pos, t_image *i);
extern t_object		*object_push(int id, char *name, t_vf2d pos, t_image *i);
extern void			object_angle_limit(t_object *set, t_vf2d size);
extern t_vf2d		object_angle_end(t_object *obj, t_vf2d begin, t_vf2d size);
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

typedef enum s_machine_status{
	MACHINE_RUNNING
}t_machine_status;

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
	unsigned	status:1;
	char		(*start)(t_machine *set, t_status resize);
	void		(*pop)(t_machine *set);
};

extern void			machine_set(t_machine *set, char *t, t_vi2d p, t_vf2d s);

typedef struct s_cub3d		t_cub3d;
struct s_cub3d
{
	t_machine	gear[1];
	t_map		level[1];
	t_status	map_show;
	void		(*init)(t_cub3d *set, void *data);
	t_vi2d		*(*mouse_pos)();
	char		(*mouse_press)(t_mouse_status button);
	t_chained	*(*image_create)(int id, t_vf2d size);
	t_chained	*(*image_load)(int id, char *path);
	t_image		*(*image_search)(int id);
	char		(*image_next_first)(t_chained *set);
	char		(*image_next_last)(t_chained *set);
	t_vi2d		(*image_size)(t_image *set);
	void		(*map_set)(int id);
	t_chained	*(*object_push)(int id, char *name, t_vf2d pos, t_image *img);
	t_object	*(*object_search)(int id);
	char		(*object_next_first)(t_chained *set);
	char		(*object_next_last)(t_chained *set);
	void		(*update)(void *set);
	void		(*draw)(t_cub3d *set);
	void		(*show)(void *set);
	void		(*run)(t_cub3d *set, void *data);
	void		(*pop)(t_cub3d *set);
};

extern t_cub3d		*cub_get(void);
extern void			cub_set(t_cub3d *set);
extern void			cub_run(t_cub3d *set, void *data);
extern void			cub_pop(t_cub3d *set);

// math
extern float	limit(int begin, int size, float edge);
extern t_vf2d	vector_pos(t_vf2d *pos);
extern float	pythag(t_vf2d *set);

// angle function
extern t_vf2d		inc_get(t_vf2d b, t_vf2d e, int *step);
extern t_vf2d		line_angle_end(t_vf2d begin, t_vf2d vel);
extern t_vf2d		line_angle_get(float *angle, t_vf2d size);
extern float		angle_limit(float angle);

// plugin function
extern void			mlx_event_start(t_machine *set);
extern void			draw_pixel(t_image *img, int x, int y, int color);
extern void			mlx_image_clear(t_image *s, int color);
extern void			mlx_texture_draw(t_image *s, t_vi2d pos, t_vf2d	zoom);
extern void			mlx_draw_line(t_image *s, t_vf2d b, t_vf2d e, int color);
extern void			mlx_draw_rect(t_image *s, t_vf2d b, t_vf2d e, int color);
extern void			mlx_draw_fill_rect(t_image *s, t_vf2d b, t_vf2d sz, int c);
extern void			ray_cast(t_object *o, t_image *i);
extern t_vf2d		ray_vertical(t_object *obj, t_vf2d *dest, float angle);
extern t_vf2d		ray_horizontal(t_object *obj, t_vf2d *dist, float angle);

// user function
extern void			user_init(t_cub3d *set, void *data);
extern void			user_update(void *data);
extern void			map_draw(t_cub3d *set);
extern void			user_draw(t_cub3d *set);

#endif