/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:04:31 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:14:36 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	calc_coordinates(double angle, t_sprites *spri, char c)
{
	double	x_len;
	double	y_len;
	double	ratio;
	double	tmp_angle;

	tmp_angle = angle_tri_rect(angle);
	x_len = 0.5 * cos(tmp_angle * TO_RAD);
	y_len = 0.5 * sin(tmp_angle * TO_RAD);
	ratio = (double)spri->size / (double)WALL_SIZE;
	if (angle > 0.0 && angle < 180.0)
		y_len *= -1.0;
	if (angle > 90.0 && angle < 270.0)
		x_len *= -1.0;
	if (c == 'A')
	{
		spri->a.x = (double)spri->x + x_len;
		spri->a.y = (double)spri->y + y_len;
		spri->a_sized.x = (double)spri->x + x_len * ratio;
		spri->a_sized.y = (double)spri->y + y_len * ratio;
	}
	else
	{
		spri->b.x = (double)spri->x + x_len;
		spri->b.y = (double)spri->y + y_len;
		spri->b_sized.x = (double)spri->x + x_len * ratio;
		spri->b_sized.y = (double)spri->y + y_len * ratio;
	}
}

void	calc_sprites_orientation(t_sprites **spri, double angle)
{
	int		i;

	i = -1;
	if (!spri)
		return ;
	while (spri[++i])
	{
		calc_coordinates(positive_angle(angle + 90.0), spri[i], 'A');
		calc_coordinates(positive_angle(angle - 90.0), spri[i], 'B');
	}
}

void	reset_ray_len_sprites(t_sprites **spri)
{
	int		i;

	i = -1;
	if (!spri)
		return ;
	while (spri[++i])
	{
		spri[i]->ray_len = -1.0;
		spri[i]->nb_pix = -1.0;
		spri[i]->row_percent = -1.0;
		spri[i]->freq_pixel = -1.0;
		spri[i]->start_line_img = -1;
	}
}

t_sprites	*sprites_ptr_x_ray(t_mlx *mlx, double angle, double x1, double y1)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if ((x1 || y1) && (angle > 0.0 && angle < 180.0))
		y1 = (double)((int)(y1)) - 1.0;
	else if (mlx->cam->y + y1 - (double)((int)(mlx->cam->y + y1)) > 0.99)
		y1 = (double)((int)(y1)) + 1.0;
	x = (int)(mlx->cam->x + x1);
	y = (int)(mlx->cam->y + y1);
	while (mlx->spri && mlx->spri[i] && ((int)mlx->spri[i]->y != y || (int)mlx->spri[i]->x != x))
		i++;
	if (!mlx->spri)
		return (NULL);
	return (mlx->spri[i]);
}

t_sprites	*sprites_ptr_y_ray(t_mlx *mlx, double angle, double x1, double y1)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if ((x1 || y1) && (angle > 90.0 && angle < 270.0))
		x1 = (double)((int)(x1)) - 1.0;
	else if (mlx->cam->x + x1 - (double)((int)(mlx->cam->x + x1)) > 0.99)
		x1 = (double)((int)(x1)) + 1.0;
	x = (int)(mlx->cam->x + x1);
	y = (int)(mlx->cam->y + y1);
	while (mlx->spri && mlx->spri[i] && ((int)mlx->spri[i]->y != y || (int)mlx->spri[i]->x != x))
		i++;
	if (!mlx->spri)
		return (NULL);
	return (mlx->spri[i]);
}