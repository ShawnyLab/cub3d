/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:04:31 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:06:40 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		ft_calc_coor(double angle, t_sprites *spri, char c)
{
	double	x_len;
	double	y_len;
	double	ratio;
	double	tmp_angle;

	tmp_angle = ft_angle_rect(angle);
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

void		ft_spr_ori(t_sprites **spri, double angle)
{
	int		i;

	i = -1;
	if (!spri)
		return ;
	while (spri[++i])
	{
		ft_calc_coor(ft_pos_angle(angle + 90.0), spri[i], 'A');
		ft_calc_coor(ft_pos_angle(angle - 90.0), spri[i], 'B');
	}
}

void		ft_reset_ray_spr(t_sprites **spri)
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

/*
스프라이트 평면과, ray가 교차되는지 체크. 교차한다면 ray 의 길이 재고, 스프라이트에 얼마나 닿는지 체크 (그래야 부분만 보여짐)
*/
void		ft_find_sprite(t_mlx *mlx, t_sprites *spri, double xd, double yd, double angle)
{
	t_point	c;
	t_point	p;	//접점
	t_point	vec_i;	//스프라이트 평면
	t_point	vec_j;	//ray 평면
	double	k;	//sprite 와  ray 가 만날 때  sprite 선분의 길이
	double	m;	// ray 선분의 길이

	if (!spri || spri->ray_len != -1.0)
		return ;
	c.x = mlx->cam->x;
	c.y = mlx->cam->y;
	vec_i.x = spri->b.x - spri->a.x;
	vec_i.y = spri->b.y - spri->a.y;
	vec_j.x = xd - c.x;
	vec_j.y = yd - c.y;
	m = -(-vec_i.x * spri->a.y + vec_i.x * c.y + vec_i.y * spri->a.x - vec_i.y * c.x) 
			/ (vec_i.x * vec_j.y - vec_i.y * vec_j.x);
	k = -(spri->a.x * vec_j.y - c.x * vec_j.y - vec_j.x * spri->a.y + vec_j.x * c.y)
			/ (vec_i.x * vec_j.y - vec_i.y * vec_j.x);
	if (m > 0.0 && m < 1.0 && k > 0.0 && k < 1.0)     //서로의 벡터가 교차한다면,
	{
		p.x = spri->a.x + k * vec_i.x;
		p.y = spri->a.y + k * vec_i.y;
		spri->ray_len = ft_seg_len(c.x, c.y, p.x, p.y);
		spri->ray_len *= cos(fabs(mlx->cam->angle - angle) * TO_RAD);
		spri->row_percent = ft_seg_len(spri->a.x, spri->a.y, p.x, p.y);
	}
}

t_sprites	*ft_xray_spr_ptr(t_mlx *mlx, double angle, double x1, double y1)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if ((x1 || y1) && (angle > 0.0 && angle < 180.0))
		y1 - (double)((int)(y1)) - 1.0;
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