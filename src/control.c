#include "../fdf.h"

int	key_press(int key, t_data *data)
{
	if (key == 53)
		handle_close(data);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		if (key == 123)
			data->offset_x += 50;
		else if (key == 124)
			data->offset_x -= 50;
		else if (key == 125)
			data->offset_y -= 50;
		else if (key == 126)
			data->offset_y += 50;
	}
	else if (key == 24 && data->zoom < 200)
		data->zoom += 1;
	else if (key == 27 && data->zoom > 2)
		data->zoom -= 1;
	draw(data);
	return (0);
}

int	handle_mouse_scroll(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4 && data->zoom > 2)
		data->zoom -= 1;
	else if (button == 5 && data->zoom < 200)
		data->zoom += 1;
	draw(data);
	return (0);
}
