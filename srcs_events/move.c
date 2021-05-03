/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:20:36 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:53:22 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	move(t_rcast *cam, double len, char coordinate)
{
	double	tmp_len;
	double	tmp_sprite_len;

	tmp_len = (len > 0.0) ? len + 0.1 : len - 0.1;
	tmp_sprite_len = (len > 0.0) ? len + 0.5 : len - 0.5;
	if (coordinate == 'x')
	{
		if ((int)(cam->x + tmp_len) < 0 || (int)(cam->x + tmp_len) >= cam->nb_rows[(int)cam->y])
			return ;
		if (cam->map[(int)(cam->y)][(int)(cam->x + tmp_len)] >= 1 &&
				cam->map[(int)(cam->y)][(int)(cam->x + tmp_len)] <= 3)
			return ;
		cam->x += len;
	}
	else if (coordinate == 'y')
	{
		if ((int)(cam->y + tmp_len) < 0 || (int)(cam->y + tmp_len) >= cam->nb_lines)
			return ;
		if (cam->map[(int)(cam->y + tmp_len)][(int)(cam->x)] >= 1 &&
				cam->map[(int)(cam->y + tmp_len)][(int)(cam->x)] <= 3)
			return ;
		cam->y += len;
	}
}

void	move_up_in_map(t_mlx *mlx, double move_size)
{
	if (mlx->cam->angle >= 0.0 && mlx->cam->angle < 90.0)
	{
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 90.0 && mlx->cam->angle < 180.0)
	{
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 180.0 && mlx->cam->angle < 270.0)
	{
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else
	{
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
}

void	move_down_in_map(t_mlx *mlx, double move_size)
{
	if (mlx->cam->angle >= 0.0 && mlx->cam->angle < 90.0)
	{
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 90.0 && mlx->cam->angle < 180.0)
	{
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 180.0 && mlx->cam->angle < 270.0)
	{
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else
	{
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
}

void	move_left_in_map(t_mlx *mlx, double move_size)
{
	if (mlx->cam->angle >= 0.0 && mlx->cam->angle < 90.0)
	{
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 90.0 && mlx->cam->angle < 180.0)
	{
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 180.0 && mlx->cam->angle < 270.0)
	{
		move(mlx->cam, +sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, +cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else
	{
		move(mlx->cam, +sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
}

void	move_right_in_map(t_mlx *mlx, double move_size)
{
	if (mlx->cam->angle >= 0.0 && mlx->cam->angle < 90.0)
	{
		move(mlx->cam, sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 90.0 && mlx->cam->angle < 180.0)
	{
		move(mlx->cam, sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else if (mlx->cam->angle >= 180.0 && mlx->cam->angle < 270.0)
	{
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
	else
	{
		move(mlx->cam, -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'x');
		move(mlx->cam, cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * move_size, 'y');
	}
}
