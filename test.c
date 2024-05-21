#include "fdf.h"

int handle_close(t_data *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
}

int handle_input(int key_pressed, t_data *data)
{
	if (key_pressed == 53)
		handle_close(data);
	else
		printf("key %d pressed\n", key_pressed);
	return (0);
}
void print_error_exit(char *str)
{
	perror(str);
    exit(1);
}

int ft_abs(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}


int	get_size(char **array)
{
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}
void freeDoubleArray(char **array)
{
    int i = 0;
	int size = get_size(array);
    while (i < size)
	{
        free(array[i]);
        i++;
    }
    free(array);
}

void find_min_max_z(t_data *data)
{
    data->map.min_z = data->map.z[0][0];
    data->map.max_z = data->map.z[0][0];

    int y = 0;
    while (y < data->map.y)
	{
        int x = 0;
        while (x < data->map.x)
		{
            if (data->map.z[y][x] < data->map.min_z) 
                data->map.min_z = data->map.z[y][x];
            if (data->map.z[y][x] > data->map.max_z)
                data->map.max_z = data->map.z[y][x];
            x++;
        }
        y++;
    }
}

void init_values(t_data *data)
{
	data->zoom = 20;
	data->color.start_color = 0x00E9F0;
	data->color.end_color = 0xFF45A2;
}
void print_background(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(data, j, i, 0x424242);
			j++;
		}
		i++;
	}

}

void set_offset(t_data *data)
{
	int content_width;
	int content_height;
	int screen_center_x;
	int screen_center_y;
	
	content_height = data->map.y * data->zoom;
	content_width = data->map.x * data->zoom;

	screen_center_x = WIDTH / 2;
	screen_center_y = HEIGHT / 2;

	data->offset_x = screen_center_x - content_width / 2;
	data->offset_y = screen_center_y - content_height / 2;
}


void init_z(t_data *data, char **argv)
{
	int fd;
	int i;
	int j;
	char *line;
	char **split;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
		print_error_exit("Error opening file");

    i = 0;
	line = get_next_line(fd);
    while (line != NULL)
	{
        split = ft_split(line, ' ');
        data->map.x = get_size(split);

        data->map.z[i] = (int *)malloc(data->map.x * sizeof(int));
        if (!data->map.z[i])
			print_error_exit("Error allocating memory for map.z row");

        j = 0;
        while (j < data->map.x)
		{
            data->map.z[i][j] = ft_atoi(split[j]);
            j++;
        }

        free(line);
        freeDoubleArray(split);
        i++;
		line = get_next_line(fd);
    }
    close(fd);
}

void process_map(t_data *data, char **argv)
{
    char *line;
    char **split;
    int fd;
    int i;
    int j;

    data->map.x = 0;
    data->map.y = 0;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
		print_error_exit("Error opening file");
    while ((line = get_next_line(fd)) != NULL)
	{
        data->map.y++;
        free(line);
    }
    close(fd);
    data->map.z = (int **)malloc(data->map.y * sizeof(int *));
    if (!data->map.z)
		print_error_exit("Error allocating memory for map.z");
	init_z(data, argv);
}

void draw_line(t_data *data, int color)
{
	t_line line;
	int i;

	i = 0;
	
	
	line.dy = data->point.y1 - data->point.y0;
	line.dx = data->point.x1 - data->point.x0;
    if (ft_abs(line.dx) > ft_abs(line.dy))
        line.steps = ft_abs(line.dx);
    else
        line.steps = ft_abs(line.dy);
    
    line.x_inc = (float)line.dx / line.steps;
    line.y_inc = (float)line.dy / line.steps;

    line.x = (float)data->point.x0;
    line.y = (float)data->point.y0;

    while (i <= line.steps)
	{
        my_mlx_pixel_put(data, round(line.x), round(line.y), color);
        line.x += line.x_inc;
        line.y += line.y_inc;
		i++;
    }
}


void isometric(int *x, int *y, int z, t_data *data)
{
    int prev_x;
    int prev_y;

	prev_x = *x;
	prev_y = *y;
    *x = (prev_x - prev_y) * cos(0.523599) + data->offset_x; // 0.523599 radians = 30 degrees
    *y = (prev_x + prev_y) * sin(0.523599) - z + data->offset_y;
}

int calc_color(t_data *data, float t)
{
    int r;
    int g;
    int b;

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

int calc_perc_color(t_data *data, int current_z, int neighbor_z, int b)
{

    int range;
    float t;
	int z;

	if(b == 1)
		z = (current_z + neighbor_z) / 2;
	else
		z = current_z;
	
	range = data->map.max_z - data->map.min_z;
	t = (float)(z - data->map.min_z) / range;

    return (calc_color(data, t));
}

int get_color(t_data *data, int x, int y, int b)
{
    int current_z;
    int neighbor_z;

	current_z = data->map.z[y][x];
    if (b == 1)
        neighbor_z = data->map.z[y][x + 1];
    else
        neighbor_z = data->map.z[y + 1][x];

    if (current_z == data->map.min_z && neighbor_z == current_z)
        return(0xdfdfde);
    else if (current_z != neighbor_z)
		return calc_perc_color(data, current_z, neighbor_z, 1);
    else
        return calc_perc_color(data, current_z, neighbor_z, 0);
}


void draw_map(t_data *data)
{
    int x;
    int y;
    int color;

    y = 0;
    while (y < data->map.y)
    {
        x = 0;
        while (x < data->map.x)
        {
            data->point.x0 = x * data->zoom;
            data->point.y0 = y * data->zoom;
            isometric(&data->point.x0, &data->point.y0, data->map.z[y][x], data);

            if (x < data->map.x - 1)
            {
				color = get_color(data, x, y, 1);
                data->point.x1 = (x + 1) * data->zoom;
                data->point.y1 = y * data->zoom;
                isometric(&data->point.x1, &data->point.y1, data->map.z[y][x + 1], data);
                draw_line(data, color);
            }
            if (y < data->map.y - 1)
            {
				color = get_color(data, x, y, 0);
                data->point.x1 = x * data->zoom;
                data->point.y1 = (y + 1) * data->zoom;
                isometric(&data->point.x1, &data->point.y1, data->map.z[y + 1][x], data);
                draw_line(data, color);
            }
            x++;
        }
        y++;
    }
}

int handle_mouse_scroll(int button, int x, int y, t_data *data)
{
    if (button == 4 && data->zoom > 5)
    {
        data->zoom -= 1;
    }
    else if (button == 5 && data->zoom < 200)
    {
        data->zoom += 1;
    }
	// printf("%i\n", data->zoom);
    mlx_clear_window(data->mlx, data->mlx_win);
    print_background(data);
    draw_map(data);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

    return (0);
}


int main(int argc, char *argv[])
{
    t_data data;

    if (argc != 2)
		print_error_exit("wrong arguments");

    data.mlx = mlx_init();
    if (data.mlx == NULL)
        print_error_exit("mlx_init failed");

    data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf_window");
    if (data.mlx_win == NULL)
	{
        free(data.mlx_win);
        return (1);
    }

    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (data.mlx == NULL)
		print_error_exit("mlx_new_window failed");
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    process_map(&data, argv);
   
	init_values(&data);

	find_min_max_z(&data);
	set_offset(&data);

	print_background(&data);
    draw_map(&data);

    mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);

    mlx_key_hook(data.mlx_win, &handle_input, &data);
	mlx_hook(data.mlx_win, 17, 0, &handle_close, &data);
	mlx_hook(data.mlx_win, 4, 0, handle_mouse_scroll, &data);
    mlx_hook(data.mlx_win, 5, 0, handle_mouse_scroll, &data);
    mlx_loop(data.mlx);

    return (0);
}