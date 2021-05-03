/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:52:41 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:12:30 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		erase_sprites_behing_walls(t_sprites **spri, double ray_len)
{
	int		i;

	i = -1;
	if (!spri)
		return ;
	while (spri[++i])
		if (ray_len < spri[i]->ray_len)
			spri[i]->ray_len = -1.0;
}

double		nb_pixel_wall(t_mlx *mlx, t_rcast *cam, t_texture *textu, double angle)
{
	double	h_wall;
	double	x_ray;
	double	y_ray;

	textu->angle_raycast = angle;
	textu->side_wall = 0;
	textu->doors_x = 0;
	textu->doors_y = 0;
	x_ray = x_ray_len(mlx, cam, angle, textu) * cos(fabs(cam->angle - angle) * TO_RAD);
	y_ray = y_ray_len(mlx, cam, angle, textu) * cos(fabs(cam->angle - angle) * TO_RAD);
	if (y_ray != y_ray || x_ray <= y_ray)
	{
		erase_sprites_behing_walls(mlx->spri, x_ray);
		textu->doors_x ? textu->side_wall = textu->doors_x : 0;
		textu->row_img = nb_image_row(cam, textu, textu->x_xa, textu->x_ya);
		h_wall = height_object(cam, x_ray);
	}
	else
	{										
		erase_sprites_behing_walls(mlx->spri, y_ray);
		textu->doors_y ? textu->side_wall = textu->doors_y : 0;
		textu->row_img = nb_image_row(cam, textu, textu->y_xa, textu->y_ya);
		h_wall = height_object(cam, y_ray);
	}
	return (h_wall);
}
