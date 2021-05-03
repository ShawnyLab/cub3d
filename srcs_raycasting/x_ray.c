/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:13:11 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:17:25 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	x_ray_y1_value(t_rcast *cam, double angle)
{
	double	y1;
	double	y_round;

	y1 = cam->y;
	y_round = round(y1);
	if (y_round > y1)
	{
		if (angle > 0.0 && angle < 180.0)
			y1 = -1.0 + (y_round - y1);
		else if (angle > 180.0 && angle < 360.0)
			y1 = y_round - y1;
	}
	else if (y_round < y1)
	{
		if (angle > 0.0 && angle < 180.0)
			y1 = y_round - y1;
		else if (angle > 180.0 && angle < 360.0)
			y1 = 1.0 - (y1 - y_round);
	}
	else
		y1 = 0.0;
	return (y1);
}

double	x_ray_ya_value(double angle)
{
	if (angle > 0 && angle < 180)
		return (-1.0);
	else if (angle > 180 && angle < 360)
		return (1.0);
	else
		return (0.0);
}

double	x_ray_x1_value(double angle, double y1)
{
	double x1;

	if (y1 < 0.0)
		y1 *= -1.0;
	x1 = y1 / tan(angle_tri_rect(angle) * TO_RAD);
	if (angle > 90.0 && angle <= 270.0)
		x1 *= -1.0;
	return (x1);
}

double	x_ray_xa_value(double angle, double y1, double ya)
{
	double xa;

	if (y1 < 0.0)
		y1 *= -1.0;
	if (ya < 0.0)
		ya *= -1.0;
	y1 += ya;
	xa = y1 / tan(angle_tri_rect(angle) * TO_RAD);
	if (angle > 90.0 && angle <= 270.0)
		xa *= -1.0;
	return (xa);
}

int		x_ray_find_wall(t_mlx *mlx, double angle, double x_len, double y_len)
{
	if ((x_len || y_len) && (angle > 0.0 && angle < 180.0))
		y_len = (double)((int)(y_len)) - 1.0;
	else if (mlx->cam->y + y_len - (double)((int)(mlx->cam->y + y_len)) > 0.99)
		y_len = (double)((int)(y_len)) + 1.0;
	if ((int)(mlx->cam->y + y_len) < 0 || (int)(mlx->cam->y + y_len) >= mlx->cam->nb_lines)
		return (-1);
	if ((int)(mlx->cam->x + x_len) < 0 || (int)(mlx->cam->x + x_len) >= 
			mlx->cam->nb_rows[(int)(mlx->cam->y + y_len)])
		return (-1);
	if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] > 3 &&
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] < 10)
		return (2);
	else if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == 0 ||
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == DOOR + 10 ||
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == SECRETDOOR + 10)
		return (1);
	else if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == DOOR)
		mlx->textu->doors_x = DOOR;
	return (0);
}