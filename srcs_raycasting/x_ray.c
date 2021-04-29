/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:13:11 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/26 17:52:50 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	ft_xray_y1(t_rcast *cam, double angle)  //레이케스팅 y의 시작 위치를 결정
{
	double	y1;
	double	y_r;

	y1 = cam->y;
	y_r = round(y1);
	if (y_r > y1)    // .5 이상
	{
		if (angle > 0.0 && angle < 180.0)   //위로
			y1 = -1.0 + (y_r - y1);
		else if (angle > 180.0 && angle < 360.0)    //아래로
			y1 = y_r - y1;
	}
	else if (y_r < y1)  // .5 이하
	{
		if (angle > 0.0 && angle < 180.0)
			y1 = y_r - y1;
		else if (angle > 180.0 && angle < 360.0)
			y1 = 1.0 - (y1- y_r);
	}
	else
		y1 = 0.0;
	return (y1);
}

double	ft_xray_x1(double angle, double y1)
{
	double	x1;

	if (y1 < 0.0)
		y1 *= -1.0;
	x1 = y1 / tan(ft_angle_rect(angle) * TO_RAD);
	if (angle > 90.0 && angle <= 270.0)
		x1 *= -1.0;
	return (x1);
}

double	ft_xray_ya(double angle)
{
	if (angle > 0 && angle < 180)
		return (-1.0);
	else if (angle > 180 && angle < 360)
		return (1.0);
	else
		return (0.0);
}

double	ft_xray_xa(double angle, double y1, double ya)
{
	double	xa;

	if (y1 < 0.0)
		y1 *= -1.0;
	if (ya < 0.0)
		ya *= -1.0;
	y1 += ya;
	xa = y1 / tan(ft_angle_rect(angle) * TO_RAD);
	if (angle > 90.0 && angle <= 270.0)
		xa *= -1.0;
	return (xa);
}

double	ft_xray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu)
{
	int		ret;
	double	y1;
	double	x1;
	double	ya;
	double	xa;

	if (angle <= 0.0 || angle >= 360.0 || angle == 180.0)
		return (NAN);
	y1 = ft_xray_y1(cam, angle);
	ya = ft_xray_ya(angle);
	x1 = ft_xray_x1(angle, y1);
	xa = ft_xray_xa(angle, y1, ya) - x1;
	if (ft_xray_wall(mlx, angle, 0, 0) == 2) //현재 위치 스프라이트가 있다면,
		ft_find_sprite(mlx, ft_xray_spr_ptr(mlx, angle, 0, 0), cam->x + xa, cam->y + ya, angle);
	while ((ret = ft_xray_wall(mlx, angle, x1, y1)) > 0)  //레이가 벽, 문, 맵의 끝을 찾을떄 까지 돌림
	{
		if (ret == 2)
			ft_find_sprite(mlx, ft_xray_spr_ptr(mlx, angle,
				x1, y1), cam->x + x1 + xa, cam->y + y1 + ya, angle);
		x1 += xa;
		y1 += ya;
	}
	textu->x_xa = x1;
	textu->x_ya = y1;
	return (ft_seg_len(cam->x, cam->y, cam->x + x1, cam->y + y1));  //벽에 닿았을 때의 길이.

		
}