/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:40:11 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:15:29 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	 find_sprites(t_mlx *mlx, t_sprites *spri, double xd, double yd, double angle)
{
	t_point c;
	t_point	p;
	t_point vec_i;
	t_point vec_j;
	double	k;
	double	m;

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
	if (m > 0.0 && m < 1.0 && k > 0.0 && k < 1.0)
	{
		p.x = spri->a.x + k * vec_i.x;
		p.y = spri->a.y + k * vec_i.y;
		spri->ray_len = ray_len(c.x, c.y, p.x, p.y);
		spri->ray_len *= cos(fabs(mlx->cam->angle - angle) * TO_RAD);
		spri->row_percent = ray_len(spri->a.x, spri->a.y, p.x, p.y);
	}
}