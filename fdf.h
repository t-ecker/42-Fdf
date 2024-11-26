/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:41 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 02:16:10 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <limits.h>

# define WIDTH			1920
# define HEIGHT 		1080

typedef struct s_color
{
	int	start_color;
	int	end_color;
	int	r_s;
	int	r_e;
	int	g_s;
	int	g_e;
	int	b_s;
	int	b_e;
	int	a_s;
	int	a_e;
}			t_color;

typedef struct s_borders
{
	int	max_x;
	int	max_y;
	int	min_x;
	int	min_y;
}			t_borders;

typedef struct s_points
{
	int x;
	int y;
	int z;
	int color;
}			t_point;

typedef struct s_two_points
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}			t_two_points;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
}			t_line;

typedef struct s_map
{
	int				x;
	int				y;
	t_point			**points;
	int color;
	int				max_z;
	int				min_z;
}			t_map;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*bg;
	mlx_image_t	*main;
}			t_mlx;

typedef struct s_data
{
	// void			*mlx;
	// void			*mlx_win;
	// void			*img;
	// char			*addr;
	// int				bits_per_pixel;
	// int				line_length;
	// int				endian;
	int				offset_x;
	int				offset_y;
	int				zoom;
	int				perspective;
	float			rotation;
	int				height;
	t_map			map;
	t_two_points	p;
	t_color			color;
	t_borders		borders;
	t_mlx			mlx;
}			t_data;

// control
// void	handle_mouse_scroll(double xdelta, double ydelta, void *param);
void	key_press_single(struct mlx_key_data key, void *param);
void	key_press_multi(void *param);
void	change_color(t_data *data);
void	change_perspective(t_data *data);

// utils
void	remove_newline(char *str);
int		get_size(char **array);
void	freedoublearray(char **array);
int		handle_close(t_data *data);
void	print_error_exit(char *str, t_data *data);
int		ft_abs(int n);
int		ft_is_format(char *str, char *format);
int		ft_is_readable(char *file);
int		ft_xtoi(char *str);
char 	*join_color(char *str);
void	freedoublearray_point(t_point **array, int len);

// initialize
void	find_min_max_z(t_data *data);
void	init_values(t_data *data);
void	read_map(t_data *data, char **argv);
void	process_map(t_data *data, char **argv);
void	init_data(t_data *data, char **argv);

// color
int		calc_color(t_data *data, float t);
int		calc_perc_color(t_data *data, int current_z, int neighbor_z, int b);
int		get_color(t_data *data, int x, int y, int b);

// draw
void	my_put_pixel(mlx_image_t *img, int x, int y, int color);
void	print_background(t_data *data);
void	draw_line(t_data *data, int color);
void	isometric(int *x, int *y, int z, t_data *data);
void	draw_map_operations(int x, int y, t_data *data);
void	draw_map(t_data *data);
void	draw(void *param);
void	draw_start(t_data *data);

//center
void	add_offset(int *x, int *y, t_data *data);
void	get_borders(t_data *data);
int		all_points_visible(t_data *data);
void	set_offset(t_data *data);

void print_debug_map(t_data *data);


#endif