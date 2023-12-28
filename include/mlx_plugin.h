/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plugin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:11:00 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 20:25:22 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PLUGIN_H
# define MLX_PLUGIN_H

# include <machine.h>

extern void	mlx_event_start(t_machine *set);
extern void	draw_pixel(t_image *img, int x, int y, int color);
extern void	mlx_image_clear(t_image *set, int color);
extern void	mlx_draw_line(t_image *set, t_vf2d b, t_vf2d e, int color);
extern void	mlx_draw_rect(t_image *set, t_vf2d b, t_vf2d e, int color);
extern void	mlx_draw_fill_rect(t_image *set, t_vf2d b, t_vf2d size, int color);

extern void	ray_cast(t_object *obj, t_image *img, t_vf2d size, char *map);

#endif