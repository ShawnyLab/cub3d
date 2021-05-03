/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:43:54 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:42:48 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	find_angle(t_rcast *cam, t_sprites *spri)
{
	double	x_len;
	double	y_len;
	double	angle;

	x_len = fabs(spri->x - cam->x);
	y_len = fabs(spri->y - cam->y);
	angle = atan(y_len / x_len) * TO_DEG;
	if (spri->x <= cam->x && spri->y <= cam->y)
		angle = 180.0 - angle;
	else if (spri->x <= cam->x && spri->y >= cam->y)
		angle = 180.0 + angle;
	else if (spri->x >= cam->x && spri->y > cam->y)
		angle = 360.0 - angle;
	return (angle);
}

int		x_ray_find_len_wall(t_mlx *mlx, double angle, double x_len, double y_len)
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
	if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == SP_GUARD)
		return (2);
	if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == 1 ||
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == DOOR ||
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == SECRETDOOR)
		return (0);
	return (1);
}

int		y_ray_find_len_wall(t_mlx *mlx, double angle, double x_len, double y_len)
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
	if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == SP_GUARD)
		return (2);
	if (mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == 1 ||
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == DOOR ||
			mlx->cam->map[(int)(mlx->cam->y + y_len)][(int)(mlx->cam->x + x_len)] == SECRETDOOR)
		return (0);
	return (1);
}

double	x_ray_len_wall(t_mlx *mlx, t_rcast *cam, double angle)
{
	double	y1;
	double	x1;
	double	ya;
	double	xa;
	
	if (angle <= 0.0 || angle >= 360.0 || angle == 180.0)
		return (NAN);
	y1 = x_ray_y1_value(cam, angle);
	ya = x_ray_ya_value(angle); 
	x1 = x_ray_x1_value(angle, y1);
	xa = x_ray_xa_value(angle, y1, ya) - x1;
	while (x_ray_find_len_wall(mlx, angle, x1, y1) > 0)
	{
		x1 += xa;
		y1 += ya;
	}
	return (ray_len(cam->x, cam->y, cam->x + x1, cam->y + y1));
}

double	y_ray_len_wall(t_mlx *mlx, t_rcast *cam, double angle)
{
	double	x1;
	double	y1;
	double	xa;
	double	ya;

	if (angle == 90.0 || angle == 270.0)
		return (NAN);
	x1 = y_ray_x1_value(cam, angle);
	xa = y_ray_xa_value(angle);
	y1 = y_ray_y1_value(angle, x1);
	ya = y_ray_ya_value(angle, x1, xa) - y1;
	while (y_ray_find_len_wall(mlx, angle, x1, y1) > 0)
	{
		x1 += xa;
		y1 += ya;
	}
	return (ray_len(cam->x, cam->y, cam->x + x1, cam->y + y1));
}
