/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:52:41 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:06:43 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int			ft_img_row(t_rcast *cam, t_texture *textu, double xa, double ya)
{
	int		row_img;
	double	x_len;
	double	y_len;

	x_len = cam->x + xa - (double)((int)(cam->x + xa));
	y_len = cam->y + ya - (double)((int)(cam->y + ya));
	if ((x_len > y_len && x_len < 0.9999999) || y_len > 0.999)
	{
		row_img = (int)(x_len * (double)WALL_SIZE);
		if (textu->side_wall == DOOR)
			return (row_img);
		textu->side_wall = (textu->angle_raycast >= 0.0 && textu->angle_raycast < 180.0) ? NORTH : SOUTH;
	}
	else
	{
		row_img = (int)(y_len * (double)WALL_SIZE);
		if (textu->side_wall == DOOR)
			return (row_img);
		textu->side_wall = (textu->angle_raycast >= 90.0 && textu->angle_raycast < 270.0) ? EAST : WEST;
	}
	return (row_img);
}

double		ft_obj_height(t_rcast *cam, double ray_len)
{
	double	h_obj;
	double	dist_cam_obj;
	dist_cam_obj = ray_len * (double)WALL_SIZE;
	h_obj = ((double)WALL_SIZE / dist_cam_obj) * (cam->dist_screen);
	return (h_obj);
}