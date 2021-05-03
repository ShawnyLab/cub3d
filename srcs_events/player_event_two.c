/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_event_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:53:33 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:59:07 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		shoot_angle(t_mlx *mlx, t_rcast *cam, double angle_shooting)
{
	double	x_ray;
	double	y_ray;
	double	max_r;

	x_ray = x_ray_len_wall(mlx, cam, positive_angle(cam->angle + angle_shooting));
	y_ray = y_ray_len_wall(mlx, cam, positive_angle(cam->angle + angle_shooting));
	max_r = (y_ray != y_ray || x_ray <= y_ray) ? x_ray : y_ray;
	if (x_ray_shooting(mlx, cam, positive_angle(cam->angle + angle_shooting), max_r) == 1)
		return (1);
	if (y_ray_shooting(mlx, cam, positive_angle(cam->angle + angle_shooting), max_r) == 1)
		return (1);
	return (0);
}

void	shoot_anim(t_mlx *mlx, t_rcast *cam)
{
	double	angle_shooting;

	mlx->eve.gun_shot = 1;
	(mlx->eve.ammo)--;
	angle_shooting = 0.0;
	while (angle_shooting < 5.0)
	{
		if (shoot_angle(mlx, cam, angle_shooting))
			break ;
		if (shoot_angle(mlx, cam, -angle_shooting))
			break ;
		angle_shooting += 0.1;
	}
	gettimeofday(&mlx->eve.gun_time_start, NULL);
}
