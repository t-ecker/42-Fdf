/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:19:54 by tecker            #+#    #+#             */
/*   Updated: 2025/04/03 17:25:08 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	change_color(t_data *data)
{
	if (data->start_color == 0x00E9F0FF)
	{
		data->start_color = 0xFF45A2FF;
		data->end_color = 0xF5E717FF;
	}
	else
	{
		data->start_color = 0x00E9F0FF;
		data->end_color = 0xFF45A2FF;
	}
}

void change_rotation(t_data *data)
{
    if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_RIGHT))
        data->rotation_angle -= 0.05;
    else
        data->rotation_angle += 0.05;
    if (data->rotation_angle < 0)
        data->rotation_angle += 2 * M_PI;
    if (data->rotation_angle >= 2 * M_PI)
        data->rotation_angle -= 2 * M_PI;
}

void	change_perspective(t_data *data)
{
	if (data->perspective == 1)
		data->perspective++;
	else
	{
		data->perspective--;
		data->rotation_angle = 0;
	}
}

void	change_z(t_data *data)
{
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_LEFT_SHIFT) && data->height > -6.0)
		data->height -= (0.15);
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_SPACE) && data->height < 6.0)
		data->height += (0.15);
}

void	movement(t_data *data)
{
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_D))
		data->offset_x += 25;
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_A))
		data->offset_x -= 25;
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_W))
		data->offset_y -= 25;
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_S))
		data->offset_y += 25;
}

void reset(t_data *data)
{
	data->zoom = 50;
	data->offset_x = 0;
	data->offset_y = 0;
	data->perspective = 2;
	data->height = 1.0;
	data->rotation_angle = 0;
	data->is_clicked = 1;
	data->is_hovered = 0;
	data->mlx.active = data->mlx.img[0];
	while (!all_points_visible(data) && data->zoom > 1)
		data->zoom--;
}

void key_press_multi(void *param)
{
    t_data *data;

    data = param;
    
    if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_A) || 
        mlx_is_key_down(data->mlx.mlx, MLX_KEY_S) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_D))
        movement(data);
    if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_UP) && data->zoom < 200)
		data->zoom += 1;
    if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_DOWN) && data->zoom > 1)
		data->zoom -= 1;
    if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_LEFT_SHIFT) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_SPACE))
        change_z(data);
    if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_RIGHT))
        change_rotation(data);
}

void	key_press_single(struct mlx_key_data key, void *param)
{
	t_data	*data;

	data = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(data->mlx.mlx);
	if (key.key == MLX_KEY_C && key.action == MLX_PRESS)
		change_color(data);
}

void	handle_mouse_scroll(double xdelta, double ydelta, void *param)
{
	(void)xdelta;
	t_data *data;

	data = (t_data *)param;
	if (ydelta > 0 && data->zoom > 5)
		data->zoom -= 5;
	else if (ydelta < 0 && data->zoom < 200)
		data->zoom += 5;
}

void	draw_hover_line(t_data *data, double x1, double x2, int y1)
{
	int x;
	int y;

	y = y1 - 3;
	while (y < y1)
	{
		x = x1 - 1;
		while (x < x2)
		{
			my_put_pixel(data->mlx.hover_overlay, x, y, 0xff8334FF);
			x++;
		}
		y++;
	}
}

void check_hover_state(t_data *data, int x, int y)
{
	mlx_get_mouse_pos(data->mlx.mlx, &x, &y);
	if (data->start && (x >= 761.5 && x <= 884.5) && (y >= 863.0 && y <= 897.0))
	{
		data->is_hovered = 4;
		draw_hover_line(data, 845.5, 985.5, 928);
	}
	else if (!data->start && (x >= 14.5 && x <= 175.5) && (y >= 220.5 && y <= 270.0))
	{
		data->is_hovered = 1;
		draw_hover_line(data, 15.0, 194.0, 272);
	}
	else if (!data->start && (x >= 185.0 && x <= 350.0) && (y >= 220.5 && y <= 270))
	{
		data->is_hovered = 2;
		draw_hover_line(data, 208.0, 387.0, 272);
	}
	else if (!data->start && (x >= 100.0 && x <= 260.0) && (y >= 867.0 && y <= 917))
	{
		data->is_hovered = 3;
		draw_hover_line(data, 112.0, 289.0, 941);
	}
	else
		data->is_hovered = 0;
}

void cursor_hook(double xpos, double ypos, void* param)
{
	t_data *data;
	int y;
	int x;
	(void) xpos;
	(void) ypos;

	data = (t_data *)param;
	x = 0;
	y = 0;
	check_hover_state(data, x, y);
}

void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_data *data;

	(void)mods;
	data = (t_data *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_RELEASE && data->is_hovered != 0)
		{
			data->is_clicked = data->is_hovered;
			if (data->is_clicked == 4)
				return (draw_start(data));
			if (data->is_clicked == 3)
				return (reset(data));
			if (data->is_clicked == 2)
				data->perspective = 1;
			else
				data->perspective = 0;
			data->mlx.active = data->mlx.img[data->is_clicked - 1];
		}
	}
}
