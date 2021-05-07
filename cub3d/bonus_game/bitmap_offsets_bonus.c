/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_offsets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:31:01 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 11:31:02 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

int		bitmap_offset_floor(t_adata *a, double *x, double *y)
{
	while (*x >= 1)
		(*x)--;
	while (*y >= 1)
		(*y)--;
	if (*x >= 0)
		*x = *x * a->sotext.imgt.width;
	if (*y >= 0)
		*y = *y * a->sotext.imgt.height;
	return (0);
}

int		bitmap_offset_sp(t_item *item, int col_id)
{
	double	remainder;
	double	offset;

	remainder = (double)(((double)col_id - item->xstart) / item->sprite_w);
	offset = item->imgsp.width * remainder;
	return (offset);
}

int		bitmap_offset(t_ray *ray, t_adata *a)
{
	double	ray_x;
	double	ray_y;
	double	remainder;
	int		offset;

	ray_x = ray->wall_hit_x / a->map.tile_size;
	ray_y = ray->wall_hit_y / a->map.tile_size;
	if (ray->hit_vertical)
	{
		remainder = ray_y - floor(ray_y);
		offset = a->notext.imgt.width * remainder;
	}
	else
	{
		remainder = ray_x - floor(ray_x);
		offset = a->notext.imgt.width * remainder;
	}
	return (offset);
}
