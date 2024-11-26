/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:19:54 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 23:34:56 by tomecker         ###   ########.fr       */
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

void	change_perspective(t_data *data)
{
	if (data->perspective == 1)
		data->perspective++;
	else
		data->perspective--;
}

void	change_z(t_data *data)
{
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_LEFT_SHIFT) && data->height > -6.0)
		data->height -= (0.15);
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_SPACE) && data->height < 6.0)
		data->height += (0.15);
}

void	movement(t_data *data)
{
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_D))
		data->offset_x += 50;
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_A))
		data->offset_x -= 50;
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_W))
		data->offset_y -= 50;
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_S))
		data->offset_y += 50;
}


void	key_press_multi(void *param)
{
	t_data	*data;

	data = param;
	
	if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_A) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_S) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_D))
		movement(data);
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_UP) && data->zoom < 200)
		data->zoom += 1;
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_DOWN) && data->zoom > 1)
		data->zoom -= 1;
	else if (mlx_is_key_down(data->mlx.mlx, MLX_KEY_LEFT_SHIFT) || mlx_is_key_down(data->mlx.mlx, MLX_KEY_SPACE))
		change_z(data);
}

void	key_press_single(struct mlx_key_data key, void *param)
{
	t_data	*data;

	data = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(data->mlx.mlx);
	else if (key.key == MLX_KEY_C && key.action == MLX_PRESS)
		change_color(data);
	else if (key.key == MLX_KEY_P && key.action == MLX_PRESS)
		change_perspective(data);
}


// void	handle_mouse_scroll(double xdelta, double ydelta, void *param)
// {
// 	(void)xdelta;
// 	t_data *data;

// 	data = (t_data *)param;
// 	if (ydelta > 0 && data->zoom > 1)
// 		data->zoom -= 1;
// 	else if (ydelta < 0 && data->zoom < 200)
// 		data->zoom += 1;
// }
