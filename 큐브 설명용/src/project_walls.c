/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:27 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/17 21:14:05 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
벽의 길이를 계산해줌. dist_proj_plane 과 Tilesize를 이용해서 비율을 구한 다음 측정.
*/
static void	calculate_wall(int i, t_wall_strip *w, t_cub *cub)
{
	w->perp_dist = cub->rays[i].dist * cos(cub->rays[i].ray_angle -    //perp_dist 벽의 직선상 거리
			cub->map.player.rotation_angle);
	w->proj_height = (TILE_SIZE / w->perp_dist) * cub->dist_proj_plane;  //화면 끝까지의 거리를 벽까지의 거리로 나눠서 실제 벽의 비율을 구함.
	w->strip_height = w->proj_height;    //벽 조각의 높이
	w->top_pix = (cub->height / 2) - (w->strip_height / 2);    //맨 위 점 픽셀의 좌표.   (y좌표는 위에서 아래이기 때문)
	w->top_pix = w->top_pix < 0 ? 0 : w->top_pix;    //음수이면 0을 넣어줌  (벽이 화면보다 높을 경우)
	w->bot_pix = (cub->height / 2) + (w->strip_height / 2);    //맨 아래 점 픽셀의 좌표
	w->bot_pix = w->bot_pix > cub->height ? cub->height : w->bot_pix;  //마찬가지
}
/*
넣을 텍스쳐 이미지의 x 좌표 구하기
*/
static void	calculate_tex_off_x(int i, t_wall_strip *w, t_cub *cub)
{
	if (cub->rays[i].was_hit_vert)
	{
		w->tex_off_x = (int)cub->rays[i].wall_hit_y % TILE_SIZE;     //히트 된 좌표를 타일사이즈로 나눈 나머지를 구함
		w->tex_off_x = w->tex_off_x * cub->texture[w->side].width / TILE_SIZE;  //넓이를 타일사이즈로 나눈 후 곱함 (픽셀 화)
	}
	else
	{
		w->tex_off_x = (int)cub->rays[i].wall_hit_x % TILE_SIZE;
		w->tex_off_x = w->tex_off_x * cub->texture[w->side].width / TILE_SIZE;
	}
}
/*
텍스쳐 계산 좌표를 이용해 벽에 그림 넣기
*/
static void	draw_wall(int i, t_wall_strip *w, t_cub *cub)
{
	int y;

	y = w->top_pix;
	while (y < w->bot_pix)
	{
		w->top_dist = y + (w->strip_height / 2) - (cub->height / 2);
		w->tex_off_y = w->top_dist * (cub->texture[w->side].height /
														(float)w->strip_height);   //텍스쳐 y좌표
		w->color = pixel_get(&cub->texture[w->side].image,
													w->tex_off_x, w->tex_off_y);
		pixel_put(&cub->image, i, y, w->color);
		y++;
	}
}

void		project_walls(t_cub *cub)
{
	int				i;
	t_wall_strip	w;

	i = 0;
	while (i < cub->width)
	{
		calculate_wall(i, &w, cub);    //벽 높이 계산
		draw_ceiling(i, &w, cub);   //천장그리기
		w.side = wall_side(&cub->rays[i]);
		calculate_tex_off_x(i, &w, cub);  //x 좌표 구하기
		draw_wall(i, &w, cub);    //벽 그리기
		draw_floor(i, &w, cub);   //바닥 그리기
		i++;
	}
}
