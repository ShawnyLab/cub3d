/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:13:56 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:08:21 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_spr_beh_wall(t_sprites **spri, double ray_len)
{
	int		i;

	i = -1;
	if (!spri)
		return ;
	while (spri[++i])
		if (ray_len < spri[i]->ray_len)
			spri[i]->ray_len = -1.0;
}

double	ft_angle_rect(double angle)
{
	if (angle < 0.0)
	{
		while (angle < 0.0)
			angle += 360.0;
		return (ft_angle_rect(angle));
	}
	else if (angle > 360.0)
	{
		while (angle > 360.0)
			angle -= 360.0;
		return (ft_angle_rect(angle));
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

double	ft_pos_angle(double angle)
{
	while (angle < 0.0)
		angle += 360.0;
	while (angle >= 360.0)
		angle -= 360.0;
	return (angle);
}

double	ft_seg_len(double xa, double ya, double xb, double yb)
{
	return (sqrt(pow(xb - xa, 2.0) + pow(yb - ya, 2.0)));
}

double	ft_pix_wall(t_mlx *mlx, t_rcast *cam, t_texture *textu, double angle)
{
	double	h_wall; //화면에 보이는 벽 크기
	double	x_ray;  //벽을 만나면 멈추고 y격자를 지날 때 마다 체크
	double	y_ray;  // 벽을 만나면 멈추고 x격자를 지날 때 마다 체크

	textu->angle_raycast = angle;
	textu->side_wall = 0;
	textu->doors_x = 0;
	textu->doors_y = 0;
	x_ray = ft_xray_len(mlx, cam, angle, textu) * cos(fabs(cam->angle - angle) * TO_RAD);
	y_ray = ft_yray_len(mlx, cam, angle, textu) * cos(fabs(cam->angle - angle) * TO_RAD);

	if (y_ray != y_ray || x_ray <= y_ray)
	{
		ft_spr_beh_wall(mlx->spri, x_ray);
		textu->doors_x ? textu->side_wall = textu->doors_x : 0;
		textu->row_img = ft_img_row(cam, textu, textu->x_xa, textu->x_ya);
		h_wall = ft_obj_height(cam, x_ray);
	}
	else
	{
		ft_spr_beh_wall(mlx->spri, y_ray);
		textu->doors_y ? textu->side_wall = textu->doors_y : 0;
		textu->row_img = ft_img_row(cam, textu, textu->y_xa, textu->y_ya);
		h_wall = ft_obj_height(cam, y_ray);
	}
	return (h_wall);
}