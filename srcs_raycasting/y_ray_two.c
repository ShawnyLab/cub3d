/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_ray_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:36:24 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:21:51 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	y_ray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu)
{
	int		ret;
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
	if (y_ray_find_wall(mlx, angle, 0, 0) == 2)
		find_sprites(mlx, sprites_ptr_y_ray(mlx, angle, 0, 0), cam->x + xa, cam->y + ya, angle);	
	while ((ret = y_ray_find_wall(mlx, angle, x1, y1)) > 0)
	{
		if (ret == 2)
			find_sprites(mlx, sprites_ptr_y_ray(mlx, angle, x1,
					y1), cam->x + x1 + xa, cam->y + y1 + ya, angle);
		x1 += xa;
		y1 += ya;
	}
	textu->y_xa = x1;
	textu->y_ya = y1;
	return (ray_len(cam->x, cam->y, cam->x + x1, cam->y + y1));
}