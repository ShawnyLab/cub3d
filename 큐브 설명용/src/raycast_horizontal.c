/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:36 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/08 15:39:12 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
벽에 닿으면 그 좌표를 설정해줌.
*/
static void	find_horz_wall(t_raycast *horz, t_map *map, t_ray *ray)
{
	while (horz->next_touch_x >= 0 &&
			horz->next_touch_x < TILE_SIZE * map->width &&
			horz->next_touch_y >= 0 &&
			horz->next_touch_y < TILE_SIZE * map->height)        //좌표가 화면 안에 존재하면 ,
	{
		horz->x_to_check = horz->next_touch_x;
		horz->y_to_check = horz->next_touch_y +
											(ray->is_ray_facing_up ? -1 : 1);   //위냐 아래냐에 따라 y값 +1, -1 벽 체크를 위해
		if (is_wall(horz->x_to_check, horz->y_to_check, map)) //벽이라면, 
		{
			horz->wall_hit_x = horz->next_touch_x;
			horz->wall_hit_y = horz->next_touch_y;      //horz 의 wall_hit 좌표를 정해줌
			horz->wall_hit = TRUE;
			break ;
		}
		else
		{
			horz->next_touch_x += horz->xstep;
			horz->next_touch_y += horz->ystep;
		}
	}
}
/*
y를 타일 1칸씩 늘리면서 레이캐스팅
*/
void		cast_ray_horz(t_raycast *horz, t_map *map, t_ray *ray)
{
	horz->wall_hit = FALSE;
	horz->wall_hit_x = 0;
	horz->wall_hit_y = 0;
	horz->yintercept = (int)(map->player.y / TILE_SIZE) * TILE_SIZE;      //반올림 
	horz->yintercept += ray->is_ray_facing_down ? TILE_SIZE : 0;         //아래방향이면 + 1
	horz->xintercept = map->player.x + (horz->yintercept - map->player.y) /
															tan(ray->ray_angle);   //각도에 따른 x좌표 (첫번째 y축에 닿는 x 좌표)
	horz->ystep = TILE_SIZE;  // y를 타일 1칸씩 땡겨줌
	horz->ystep *= ray->is_ray_facing_up ? -1 : 1;
	horz->xstep = horz->ystep / tan(ray->ray_angle);    //각도에 따른 x 한 좌표
	horz->xstep *= (ray->is_ray_facing_left && horz->xstep > 0) ? -1 : 1;
	horz->xstep *= (ray->is_ray_facing_right && horz->xstep < 0) ? -1 : 1;
	horz->next_touch_x = horz->xintercept;
	horz->next_touch_y = horz->yintercept;
	find_horz_wall(horz, map, ray);
}
