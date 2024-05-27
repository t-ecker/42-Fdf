#include "../fdf.h"

int	calc_color(t_data *data, float t)
{
	int	r;
	int	g;
	int	b;

	data->color.r_s = (data->color.start_color >> 16) & 0xFF;
	data->color.g_s = (data->color.start_color >> 8) & 0xFF;
	data->color.b_s = data->color.start_color & 0xFF;
	data->color.r_e = (data->color.end_color >> 16) & 0xFF;
	data->color.g_e = (data->color.end_color >> 8) & 0xFF;
	data->color.b_e = data->color.end_color & 0xFF;
	r = data->color.r_s + t * (data->color.r_e - data->color.r_s);
	g = data->color.g_s + t * (data->color.g_e - data->color.g_s);
	b = data->color.b_s + t * (data->color.b_e - data->color.b_s);
	return ((r << 16) | (g << 8) | b);
}

int	calc_perc_color(t_data *data, int current_z, int neighbor_z, int b)
{
	int		range;
	float	t;
	int		z;

	if (b == 1)
		z = (current_z + neighbor_z) / 2;
	else
		z = current_z;
	range = data->map.max_z - data->map.min_z;
	t = (float)(z - data->map.min_z) / range;
	return (calc_color(data, t));
}

int	get_color(t_data *data, int x, int y, int b)
{
	int	current_z;
	int	current_col;
	int	neighbor_z;
	int	neighbor_col;

	current_z = data->map.z[y][x];
	current_col = data->color.map_color[y][x];
	if (b == 1)
	{
		neighbor_z = data->map.z[y][x + 1];
		neighbor_col = data->color.map_color[y][x + 1];
	}
	else
	{
		neighbor_z = data->map.z[y + 1][x];
		neighbor_col = data->color.map_color[y + 1][x];
	}
	if (current_z != neighbor_z && (current_col == 0))
		return (calc_perc_color(data, current_z, neighbor_z, 1));
	else if (current_col != 0 && neighbor_col != 0)
		return (current_col);
	else
		return (calc_perc_color(data, current_z, neighbor_z, 0));
}
