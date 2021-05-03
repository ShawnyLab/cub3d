/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:28:06 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:20:18 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	y_ray_x1_value(t_rcast *cam, double angle)
{
	double x1;
	double x_round;

	x1 = cam->x;
	x_round = round(x1);
	if (x_round > x1)
	{
		if ((angle >= 0.0 && angle < 90.0) ||
			(angle > 270.0 && angle < 360.0))
			x1 = x_round - x1;
		else if (angle > 90 && angle < 270)
			x1 = -1.0 + (x_round - x1);
	}
	else if (x_round < x1)
	{
		if ((angle >= 0.0 && angle < 90.0) ||
			(angle > 270.0 && angle < 360.0))
			x1 = 1.0 - (x1 - x_round);
		else if (angle > 90 && angle < 270)
			x1 = x_round - x1;
	}
	else
		x1 = 0.0;
	return (x1);
}

double	y_ray_xa_value(double angle)
{
	if ((angle >= 0.0 && angle < 90.0) ||
		(angle > 270.0 && angle < 360.0))
		return (1.0);
	else if (angle > 90 && angle < 270)
		return (-1.0);
	else
		return (0.0);
}

double	y_ray_y1_value(double angle, double x1)
{
	double	y1;

	if (x1 < 0.0)
		x1 *= -1.0;
	y1 = x1 * tan(angle_tri_rect(angle) * TO_RAD);
	if (angle >= 0.0 && angle < 180.0)
		y1 *= -1.0;
	return (y1);
}

double	y_ray_ya_value(double angle, double x1, double xa)
{
	double ya;

	if (x1 < 0.0)
		x1 *= -1.0;
	if (xa < 0.0)
		xa *= -1.0;
	x1 += xa;
	ya = x1 * tan(angle_tri_rect(angle) * TO_RAD);
	if (angle >= 0.0 && angle < 180.0)
		ya *= -1.0;
	return (ya);
}

int		y_ray_find_wall(t_mlx *mlx, double angle, double x_len, double y_len)
{
	if ((x_len || y_len) && (angle > 90.0 && angle < 270.0))
		x_len = (double)((int)(x_len)) - 1.0;
	else if (mlx->cam->x + x_len - (double)((int)(mlx->cam->x + x_len)) > 0.99)
		x_len = (double)((int)(x_len)) + 1.0;
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
	else if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == 2)
		mlx->textu->doors_y = DOOR;
	return (0);
}
