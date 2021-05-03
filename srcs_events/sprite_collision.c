/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:48:57 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:58:50 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_sprites	*sprite_ptr(t_mlx *mlx, int x, int y)
{
	int			i;

	i = 0;
	while (mlx->spri && mlx->spri[i] && ((int)mlx->spri[i]->y != y || (int)mlx->spri[i]->x != x))
		i++;
	if (!mlx->spri)
		return (NULL);
	return (mlx->spri[i]);
}

int			find_inter_rays(t_mlx *mlx, t_sprites *spri, double xc, double yc)
{
	t_point d;
	t_point vec_i;
	t_point vec_j;
	double	k;
	double	m;
	double	seg_len;

	d.x = mlx->cam->x;
	d.y = mlx->cam->y;
	vec_j.x = d.x - xc;
	vec_j.y = d.y - yc;
	seg_len = ray_len(d.x, d.y, xc, yc);
	seg_len = 0.5 / seg_len;
	d.x += vec_j.x * seg_len;
	d.y += vec_j.y * seg_len;
	vec_i.x = spri->b_sized.x - spri->a_sized.x;
	vec_i.y = spri->b_sized.y - spri->a_sized.y;
	vec_j.x = d.x - xc;
	vec_j.y = d.y - yc;
	m = -(-vec_i.x * spri->a_sized.y + vec_i.x * yc + vec_i.y * spri->a_sized.x - vec_i.y * xc) 
			/ (vec_i.x * vec_j.y - vec_i.y * vec_j.x);
	k = -(spri->a_sized.x * vec_j.y - xc * vec_j.y - vec_j.x * spri->a_sized.y + vec_j.x * yc)
			/ (vec_i.x * vec_j.y - vec_i.y * vec_j.x);
	if (m > 0.0 && m < 1.0 && k > 0.0 && k < 1.0)
		return (1);
	return (0);
}

int			collision_or_event(t_mlx *mlx, t_sprites *square, int x, int y)
{
	int		i;

	i = 0;
	if (square->type == SP_HEALTH || square->type == SP_AMMO)
	{
		square->type == SP_HEALTH ? mlx->eve.lifebar += GAIN_HEALTH : 0;
		square->type == SP_HEALTH && mlx->eve.lifebar > FULL_LIFE ? mlx->eve.lifebar = FULL_LIFE : 0;
		square->type == SP_AMMO ? mlx->eve.ammo += GAIN_AMMO : 0;
		square->type == SP_AMMO && mlx->eve.ammo > FULL_AMMO ? mlx->eve.ammo = FULL_AMMO : 0;
		mlx->cam->map[y][x] = 0;
		square->ray_len = -2.0;
		sort_sprites_tab(mlx->spri);
		while (mlx->spri[i])
			i++;
		free(mlx->spri[i - 1]);
		mlx->spri[i - 1] = NULL;
		return (0);
	}
	else if (square->type == SP_GUARD && square->guard.status == DEAD)
		return (0);
	return (1);
}

int			sprite_collision(t_mlx *mlx, t_rcast *cam, double xc, double yc)
{
	t_sprites	*square1;
	t_sprites	*square2;

	square1 = sprite_ptr(mlx, (int)cam->x, (int)cam->y);
	if ((int)cam->x == (int)xc && (int)cam->y == yc)
		square2 = NULL;
	else
		square2 = sprite_ptr(mlx, (int)xc, (int)yc);
	if (square1 && find_inter_rays(mlx, square1, xc, yc))
		return (collision_or_event(mlx, square1, (int)cam->x, (int)cam->y));
	if (square2 && find_inter_rays(mlx, square2, xc, yc))
		return (collision_or_event(mlx, square2, (int)xc, (int)yc));
	return (0);
}
