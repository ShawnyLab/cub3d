/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:59:25 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:57:26 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	add_len_to_ray(t_mlx *mlx, t_point *square, double size_len)
{
	if (mlx->cam->angle >= 0.0 && mlx->cam->angle < 90.0)
	{
		square->x += cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
		square->y += -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
	}
	else if (mlx->cam->angle >= 90.0 && mlx->cam->angle < 180.0)
	{
		square->x += -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
		square->y += -sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
	}
	else if (mlx->cam->angle >= 180.0 && mlx->cam->angle < 270.0)
	{
		square->x += -cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
		square->y += sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
	}
	else
	{
		square->x += cos(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
		square->y += sin(angle_tri_rect(mlx->cam->angle) * TO_RAD) * size_len;
	}
}

void	open_door(t_mlx *mlx)
{
	int		i;
	t_point	square;

	i = -1;
	square.x = mlx->cam->x;
	square.y = mlx->cam->y;
	while (++i < 10)
	{
		add_len_to_ray(mlx, &square, 0.1);
		if (mlx->cam->map[(int)square.y][(int)square.x] == DOOR ||
				mlx->cam->map[(int)square.y][(int)square.x] == SECRETDOOR)
		{
			mlx->cam->map[(int)square.y][(int)square.x] +=10; 
			return ;
		}
		else if ((mlx->cam->map[(int)square.y][(int)square.x] == DOOR + 10
				|| mlx->cam->map[(int)square.y][(int)square.x] == SECRETDOOR + 10)
				&& mlx->cam->map[(int)mlx->cam->y][(int)mlx->cam->x] !=
				mlx->cam->map[(int)square.y][(int)square.x])
		{
			mlx->cam->map[(int)square.y][(int)square.x] -=10;
			return ;
		}
	}
}

int		set_ennemy_to_death_value(t_sprites *spri)
{
	if (spri->guard.status >= DYING)
		return (0);
	spri->guard.status = DYING;
	gettimeofday(&spri->guard.time_death, NULL);
	return (1);
}

int		x_ray_shooting(t_mlx *mlx, t_rcast *cam, double angle, double ray_max_len)
{
	int		ret;
	double	y1;
	double	x1;
	double	ya;
	double	xa;
	
	if (angle <= 0.0 || angle >= 360.0 || angle == 180.0)
		return (-1);
	y1 = x_ray_y1_value(cam, angle);
	ya = x_ray_ya_value(angle); 
	x1 = x_ray_x1_value(angle, y1);
	xa = x_ray_xa_value(angle, y1, ya) - x1;
	if (x_ray_find_len_wall(mlx, angle, 0, 0) == 2 &&
			set_ennemy_to_death_value(sprites_ptr_x_ray(mlx, angle, 0, 0)))
		return (1);
	while ((ret = x_ray_find_len_wall(mlx, angle, x1, y1)) > 0 &&
			ray_len(cam->x, cam->y, cam->x + x1, cam->y + y1) < ray_max_len)
	{
		if (ret == 2 && set_ennemy_to_death_value(sprites_ptr_x_ray(mlx, angle, x1, y1)))
			return (1);
		x1 += xa;
		y1 += ya;
	}
	return (0);
}

int		y_ray_shooting(t_mlx *mlx, t_rcast *cam, double angle, double ray_max_len)
{
	int		ret;
	double	x1;
	double	y1;
	double	xa;
	double	ya;

	if (angle == 90.0 || angle == 270.0)
		return (-1);
	x1 = y_ray_x1_value(cam, angle);
	xa = y_ray_xa_value(angle);
	y1 = y_ray_y1_value(angle, x1);
	ya = y_ray_ya_value(angle, x1, xa) - y1;
	if (y_ray_find_len_wall(mlx, angle, 0, 0) == 2 &&
			set_ennemy_to_death_value(sprites_ptr_y_ray(mlx, angle, 0, 0)))
			return (1);
	while ((ret = y_ray_find_len_wall(mlx, angle, x1, y1)) > 0 &&
			ray_len(cam->x, cam->y, cam->x + x1, cam->y + y1) < ray_max_len)
	{
		if (ret == 2 && set_ennemy_to_death_value(sprites_ptr_y_ray(mlx, angle, x1, y1)))
			return (1);
		x1 += xa;
		y1 += ya;
	}
	return (0);
}