/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:28:06 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 19:43:31 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	ft_yray_x1(t_rcast *cam, double angle)
{
	double	x1;
	double	x_r;

	x1 = cam->x;
	x_r = round(x1);
	if (x_r > x1)
	{
		if ((angle >= 0.0 && angle < 90.0) ||
			(angle > 270.0 && angle < 360.0))
			x1 = x_r - x1;
		else if (angle > 90 && angle < 270)
			x1 = -1.0 + (x_r - x1);
	}
	else if (x_r < x1)
	{
		if ((angle >= 0.0 && angle < 90.0) ||
			(angle > 270.0 && angle < 360.0))
			x1 = 1.0 - (x1 - x_r);
		else if (angle > 90 && angle < 270)
			x1 = x_r - x1;
	}
	else
		x1 = 0.0;
	return (x1);
}

double	ft_yray_xa(double angle)
{
	if ((angle >= 0.0 && angle < 90.0) || //we're going rigth in the tab so xa is positive
		(angle > 270.0 && angle < 360.0))
		return (1.0);
	else if (angle > 90 && angle < 270) //we're going left in the tab so ya is negative
		return (-1.0);
	else //vertical ray will never cross 'x axe'
		return (0.0);
}

double	ft_yray_y1(double angle, double x1)
{
	double	y1;

	if (x1 < 0.0) //we need pos values for trigo calculation
		x1 *= -1.0;
	y1 = x1 * tan(angle_tri_rect(angle) * TO_RAD);
	if (angle >= 0.0 && angle < 180.0)
		y1 *= -1.0;
	return (y1);
}

double	ft_yray_ya(double angle, double x1, double xa)
{
	double ya;

	if (x1 < 0.0) //we need pos values for trigo calculation
		x1 *= -1.0;
	if (xa < 0.0)
		xa *= -1.0;
	x1 += xa;
	ya = x1 * tan(angle_tri_rect(angle) * TO_RAD);
	if (angle >= 0.0 && angle < 180.0)
		ya *= -1.0;
	return (ya);
}

double	ft_yray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu)
{
	int		ret;
	double	x1;
	double	y1;
	double	xa;
	double	ya;

	if (angle == 90.0 || angle == 270.0)
		return (NAN);
	x1 = ft_yray_x1(cam, angle);
	xa = ft_yray_xa(angle);
	y1 = ft_yray_y1(angle, x1);
	ya = ft_yray_ya(angle, x1, xa) - y1;
	if (ft_yray_wall(mlx, angle, 0, 0) == 2)
		ft_find_sprite(mlx, ft_yray_spr_ptr(mlx, angle, 0, 0), cam->x + xa, cam->y + ya, angle);
	while ((ret = ft_yray_wall(mlx, angle, x1, y1)) > 0)
	{
		if (ret == 2)
			ft_find_sprite(mlx, ft_yray_spr_ptr(mlx, angle, x1,
				y1), cam->x + x1 + xa, cam->y + y1 + ya, angle);
		x1 += xa;
		y1 += ya;
	}
	textu->y_xa = x1;
	textu->y_ya = y1;
	return (ft_seg_len(cam->x, cam->y, cam->x + x1, cam->y + y1));
}