/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:01:09 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/18 14:08:10 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
스프라이트와 플레이어의 상대각도 , 거리를 구해서 
시작  x y 좌표 를 구함.
*/
static void	calculate_sprites(t_cub *cub)
{
	int			i;
	float		dx;
	float		dy;
	t_sprite	*sprite;
	t_player	*player;

	i = -1;
	player = &cub->map.player;
	while (++i < cub->map.sprites)
	{
		sprite = &cub->sprites[i];
		dy = sprite->y - player->y;
		dx = sprite->x - player->x;
		sprite->direction = atan2(dy, dx);    //atan2 : 두 점의 상대좌표를 받아서, -파이 ~~ 파이 의 라디안으로 변환 , 즉 스프라이트와 플레이어의 각도를 리턴
		while (sprite->direction - player->rotation_angle > PI)
			sprite->direction -= TWO_PI;
		while (sprite->direction - player->rotation_angle < -PI)
			sprite->direction += TWO_PI;
		sprite->player_dist = points_dist(player->x,
				sprite->x, player->y, sprite->y);     //플레이어와 스프라이트의 거리 계산
		sprite->size = cub->width / sprite->player_dist * TILE_SIZE;    //비율계산을 통해 스프라이트의 사이즈 계산 (너비로 계산했지만 높이도 해당됌.)
		sprite->y_off = (cub->height / 2) - (sprite->size / 2);        //시작 y 좌표
		sprite->x_off = (sprite->direction - player->rotation_angle) *
			cub->width / cub->fov_angle + (cub->width / 2) - (sprite->size / 2);   //시작 x 좌표
	}
}
/*
**버블정렬로 거리 순으로 스프라이트 정렬
*/
static void	sort_sprites(t_cub *cub)
{
	int			i;
	int			len;
	int			swap;
	t_sprite	temp;

	swap = -1;
	len = cub->map.sprites;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i + 1 < len)
		{
			if (cub->sprites[i].player_dist < cub->sprites[i + 1].player_dist)
			{
				temp = cub->sprites[i];
				cub->sprites[i] = cub->sprites[i + 1];
				cub->sprites[i + 1] = temp;
				swap++;
			}
			i++;
		}
	}
}

static void	draw_sprite(t_cub *cub, int i, int tex_id)
{
	int			y;
	int			x;
	int			c;
	t_sprite	*s;

	y = -1;
	s = &cub->sprites[i];
	while (++y < s->size)
	{
		if (s->y_off + y >= 0 && s->y_off + y < cub->height && (x = -1))
		{
			while (++x < s->size)
			{
				if ((s->x_off + x >= 0 && s->x_off + x < cub->width) &&
					(cub->rays[s->x_off + x].dist > s->player_dist))
				{
					c = pixel_get(&cub->texture[tex_id].image,
							x * cub->texture[tex_id].height / s->size,
							y * cub->texture[tex_id].width / s->size);
					if (c & 0xffffff)  //비트연산  AND 연산으로 검정색인지 아닌지를 판별. 검정색이면 칠할 필요가 없기 때문.
						pixel_put(&cub->image, s->x_off + x, s->y_off + y, c);
				}
			}
		}
	}
}

void		draw_sprites(t_cub *cub)
{
	int	i;

	calculate_sprites(cub);
	sort_sprites(cub);
	i = 0;
	while (i < cub->map.sprites)
	{
		draw_sprite(cub, i, cub->sprites[i].tex_id);
		i++;
	}
}
