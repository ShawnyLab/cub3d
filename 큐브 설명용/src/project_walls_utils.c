/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_walls_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:23 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/19 23:48:17 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
벽의 동, 서, 남, 북 정해주기
*/
int		wall_side(t_ray *ray)
{
	int	side;

	if (ray->was_hit_vert)
	{
		if (ray->is_ray_facing_right)
			side = EAST;
		else
			side = WEST;
	}
	else
	{
		if (ray->is_ray_facing_up)
			side = SOUTH;
		else
			side = NORTH;
	}
	return (side);
}
/*
top_pix 을 이용해서 천장에 ceiling_color 색 넣어주기
*/
void	draw_ceiling(int x, t_wall_strip *wall, t_cub *cub)
{
	int	y;

	y = 0;
	while (y < wall->top_pix)
	{
		pixel_put(&cub->image, x, y, cub->map.ceil_color);
		y++;
	}
}
/*
바닥에 floor_color 색 넣어주기
*/
void	draw_floor(int x, t_wall_strip *wall, t_cub *cub)
{
	int	y;

	y = wall->bot_pix;
	while (y < cub->height)
	{
		pixel_put(&cub->image, x, y, cub->map.floor_color);
		y++;
	}
}
