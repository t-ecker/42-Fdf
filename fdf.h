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

typedef struct s_points
{
	int x0;
	int y0;
	int x1;
	int y1;
}			t_point;

typedef struct s_line
{
	int dx;
    int dy;
    int steps;
	float x_inc;
	float y_inc;
	float x;
	float y;
}			t_line;

typedef struct s_map
{
	int				x;
	int				y;
	int				**z;
	int				max_z;
	int 			min_z;
}			t_map;

typedef struct s_data
{
	void 			*mlx;
	void 			*mlx_win;
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
}			t_data;

#endif