/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:11:10 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:09:43 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		draw_skybox(t_mlx *mlx, double height, double rcast_angle)
{
	int		row;
	int		line;
	int		color;

	height = mlx->par->reso[1] - height;
	line = (int)((height / (mlx->par->reso[1] / 2.0)) //reso / 2 because sky could be at max half of the screen
			* (double)(mlx->info.t_sk[HEIGHT] - 1));
	row = (int)(rcast_angle / 360.0 * (double)mlx->info.t_sk[WIDTH]);
	color = mlx->addr.t_sk[row + line * mlx->info.t_sk[SIZE_LINE]];
	return (color);
}

int		find_color_square_floor(t_mlx *mlx, t_point i)
{
	int		color;
	int		line;
	int		row;

	i.x = fabs(i.x - ((double)(int)i.x));
	i.y = fabs(i.y - ((double)(int)i.y));
	row = (int)(i.x * (double)WALL_SIZE);
	line = (int)(i.y * (double)WALL_SIZE);
	color = mlx->addr.t_fl[row + T_FLOOR_R + line * mlx->info.t_fl[SIZE_LINE]
			+ T_FLOOR_L * mlx->info.t_fl[SIZE_LINE]];
	return (color);
}

int		floor_raycasting(t_mlx *mlx, double height, double rcast_angle)
{
	double	angle;
	double	flo_ray_len;
	t_point	i;

	angle = atan(height / mlx->cam->dist_screen) * TO_DEG;
	angle = 90.0 - angle;
	flo_ray_len = (tan(angle * TO_RAD) * ((double)WALL_SIZE / 2.0))
				/ (double)WALL_SIZE;
	flo_ray_len /= cos(fabs(mlx->cam->angle - rcast_angle) * TO_RAD);
	angle = angle_tri_rect(rcast_angle);
	i.x = flo_ray_len * cos(angle * TO_RAD);
	i.y = flo_ray_len * sin(angle * TO_RAD);
	if (rcast_angle > 0.0 && rcast_angle < 180.0)
		i.y *= -1.0;
	if (rcast_angle > 90.0 && rcast_angle < 270.0)
		i.x *= -1.0;
	i.x += mlx->cam->x;
	i.y += mlx->cam->y;
	return (find_color_square_floor(mlx, i));
}
