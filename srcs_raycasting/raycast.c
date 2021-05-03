/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:13:56 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:11:07 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	positive_angle(double angle)
{
	while (angle < 0.0)
		angle += 360.0;
	while (angle >= 360.0)
		angle -= 360.0;
	return (angle);
}

double	angle_tri_rect(double angle)
{
	if (angle < 0.0)
	{
		while (angle < 0.0)
			angle += 360.0;
		return (angle_tri_rect(angle));
	}
	else if (angle > 360.0)
	{
		while (angle > 360.0)
			angle -= 360.0;
		return (angle_tri_rect(angle));
	}
	else if (angle >= 0.0 && angle <= 90.0)
		return (angle);
	else if (angle > 90.0 && angle <= 180.0)
		return (180.0 - angle);
	else if (angle > 180.0 && angle <= 270.0)
		return (angle - 180.0);
	else
		return (360.0 - angle);
}

double	ray_len(double xa, double ya, double xb, double yb)
{
	return (sqrt(pow(xb - xa, 2.0) + pow(yb - ya, 2.0)));
}

double	height_object(t_rcast *cam, double ray_len)
{
	double	h_object;
	double	dist_cam_obj_ing;

	dist_cam_obj_ing = ray_len * (double)WALL_SIZE;
	h_object = ((double)WALL_SIZE / dist_cam_obj_ing) * (cam->dist_screen);
	return (h_object);
}

int		nb_image_row(t_rcast *cam, t_texture *textu, double xa, double ya)
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
