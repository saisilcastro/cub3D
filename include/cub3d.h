/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:05:45 by mister-code       #+#    #+#             */
/*   Updated: 2024/03/26 17:27:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42/MLX42.h>
# include <GLFW/glfw3.h>
# include <math.h>
# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game	t_game;

typedef enum e_status{
	Off,
	On
}t_status;

typedef struct s_pixel{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}t_pixel;

typedef struct s_vi2d{
	int	x;
	int	y;
}t_vi2d;

extern t_vi2d	vi2d_start(int x, int y);
extern int		vi2d_limit(t_vi2d *set, t_vi2d b, t_vi2d e);
extern void		vi2d_show(t_vi2d *set, char *x, char *y);

typedef struct s_vd2d	t_vd2d;
struct s_vd2d{
	double	x;
	double	y;
};

extern t_vd2d	vd2d_start(double x, double y);
extern void		vd2d_rotate(t_vd2d *pos, double rotation);
extern int		vd2d_limit(t_vd2d *set, t_vd2d b, t_vd2d e);
extern void		vd2d_show(t_vd2d *set, char *x, char *y);
extern t_vd2d	screen_size(void);

extern uint32_t	*pixel_set(void *buffer, t_vi2d i, int w, int bpp);
extern int		pixel_get(void *buffer, t_vi2d p, int w, int bpp);
extern void		pixel_divider(uint32_t *pixel);
extern int		pixel_to_int(t_pixel *set);
extern void		pixel_show(int color);

typedef struct s_map{
	uint32_t	**map;
	char		*textures[4];
	t_vi2d		size[1];
	t_vd2d		cell[1];
	t_pixel		color[2];
}	t_map;

extern t_status	get_map(char *map_fd, t_map *map);
extern int		check_input(int argc, char **argv);
extern void		array_pop(char **arr);
extern char		*texture_breaker(char *texture, char *direction);
extern t_status	map_validate(t_map *level, char **array);
extern t_vd2d	player_start_point(t_map *set);
extern t_status	is_character_of_map(char *line);
extern t_status	map_solid(int x, int y);
extern t_status	special_char(char c);
extern void		map_swap(t_map **lv);

extern float	deg_to_rad(float angle);

typedef struct s_image{
	int				id;
	mlx_image_t		*img;
	mlx_texture_t	*tex;
}t_image;

extern t_image	*image_push(int id, void *img, void *tex);
extern void		image_pop(void *data);

typedef struct s_object	t_object;
struct s_object{
	t_vd2d	pos[1];
	t_vd2d	dir[1];
	t_vd2d	plane[1];
	double	speed;
	double	angle;
};

extern void		object_rotate(t_object *obj, int clockwise);
extern void		object_forward(t_object *obj);
extern void		object_backward(t_object *obj);
extern void		object_left(t_object *obj);
extern void		object_right(t_object *obj);

typedef struct s_mouse{
	t_vd2d		pos[1];
	unsigned	button: 3;
	struct{
		int	left;
		int	top;
	}s_wheel[1];
	double		horiz;
}t_mouse;

typedef struct s_caster{
	t_vi2d	map[1];
	t_vi2d	step[1];
	t_vd2d	ray_dir[1];
	t_vd2d	side_dist[1];
	t_vd2d	delta_dist[1];
	double	per_wall_dist;
	int		line_height;
	struct{
		int	begin;
		int	end;
	}s_v_draw[1];
	int		pitch;
	enum{
		NO,
		EA,
		SO,
		WE
	}e_compass;
}t_caster;

extern void		ray_pos_dir_get(t_game *game, t_object *obj,
					t_caster *cast, int x);
extern void		delta_dist_get(t_caster *cast);
extern void		step_and_side_get(t_vd2d *player, t_caster *cast);
extern void		dda_get(t_caster *cast);
extern void		vertical_limit(t_vd2d *screen, t_caster	*cast);

enum{
	MACHINE_RUNNING,
	MACHINE_SHOW,
	MOUSE_MOVE,
	MINIMAP_SHOW
};

struct s_game{
	mlx_t		*mlx;
	t_map		level[1];
	t_image		screen[1];
	t_vd2d		size[1];
	t_object	player[1];
	t_image		*gf[4];
	t_mouse		mouse[1];
	unsigned	status:4;
};

// event function
extern void		event_start(t_game *game);
extern void		mouse_event_start(t_game *game);
extern int		mouse_move(t_game *game);
extern void		object_control(t_game *game, t_object *obj);

extern t_game	*cub_get(void);
extern void		game_start(t_game *set);
extern void		game_pop(t_game *set);

// draw function
extern void		draw_pixel(t_vd2d pos, int color, int len);
extern void		draw_line(t_vd2d b, t_vd2d e, int len, int color);
extern void		draw_rect_fill(t_vd2d b, t_vd2d e, int lenght, int color);
extern void		draw_image(t_image *graph, t_vd2d b);
extern void		draw_texture(t_image *graph, t_vd2d b);

// ray cast function
extern void		ray_cast_start(t_game *game, int x);

// minimap function
extern t_vd2d	cell_get(t_game *game);
extern void		minimap_run(t_game *game);

#endif