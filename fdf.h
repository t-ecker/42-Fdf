#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./Libft/libft.h"
# include <math.h>

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
	int	**map_color;

}			t_color;
typedef struct s_points
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}			t_point;

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
	int				**z;
	int				max_z;
	int				min_z;
}			t_map;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				offset_x;
	int				offset_y;
	int				zoom;
	t_map			map;
	t_point			point;
	t_color			color;
}			t_data;

// control.c
int		handle_mouse_scroll(int button, int x, int y, t_data *data);
int		key_press(int key, t_data *data);

// other_utils.c
int		get_size(char **array);
void	freedoublearray(char **array);
void	freedoublearray_int(int **array, t_data *data);
int		handle_close(t_data *data);
void	print_error_exit(char *str, t_data *data);
int		ft_abs(int n);
int		ft_is_format(char *str, char *format);
int		ft_is_readable(char *file);
int		ft_xtoi(char *str, t_data *data);

// initialize.c
void	find_min_max_z(t_data *data);
void	init_values(t_data *data);
void	set_offset(t_data *data);
int		read_z_and_color(t_data *data, char *str, int j, int i);
void	allocate_map_rows(t_data *data, char *line, int i);
void	read_map(t_data *data, char **argv);
void	process_map(t_data *data, char **argv);
void	init_data(t_data *data, char **argv);

// color.c
int		calc_color(t_data *data, float t);
int		calc_perc_color(t_data *data, int current_z, int neighbor_z, int b);
int		get_color(t_data *data, int x, int y, int b);

// draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_background(t_data *data);
void	draw_line(t_data *data, int color);
void	isometric(int *x, int *y, int z, t_data *data);
void	draw_map_operations(int x, int y, t_data *data);
void	draw_map(t_data *data);
void	draw(t_data *data);

#endif