/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ray_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:37:31 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:18:44 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	x_ray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu)
{
	int		ret;
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
	if (x_ray_find_wall(mlx, angle, 0, 0) == 2)
		find_sprites(mlx, sprites_ptr_x_ray(mlx, angle, 0, 0), cam->x + xa, cam->y + ya, angle);
	while ((ret = x_ray_find_wall(mlx, angle, x1, y1)) > 0)
	{
		if (ret == 2)
			find_sprites(mlx, sprites_ptr_x_ray(mlx, angle, x1,
					y1), cam->x + x1 + xa, cam->y + y1 + ya, angle);
		x1 += xa;
		y1 += ya;
	}
	textu->x_xa = x1;
	textu->x_ya = y1;
	return (ray_len(cam->x, cam->y, cam->x + x1, cam->y + y1));
}
