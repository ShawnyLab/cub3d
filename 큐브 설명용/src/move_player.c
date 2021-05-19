/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:46 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/18 14:21:32 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_collision(t_cub *cub, float x, float y)
{
	int	**grid;

	if (x - 2 < 0 || y - 2 < 0 ||
		x + 2 >= cub->map.width * TILE_SIZE ||
		y + 2 >= cub->map.height * TILE_SIZE)     //player의 사이즈를 4 * 4 로 두고 계산. 벽에 너무 가까이 붙었을때의 부자연스러움을 해결하기 위함.
		return (1);
	grid = cub->map.grid;
	if (grid[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == 0 &&
		grid[(int)((y - 2) / TILE_SIZE)][(int)(x / TILE_SIZE)] == 0 &&
		grid[(int)(y / TILE_SIZE)][(int)((x - 2) / TILE_SIZE)] == 0 &&
		grid[(int)((y - 2) / TILE_SIZE)][(int)((x - 2) / TILE_SIZE)] == 0 &&
		grid[(int)((y + 2) / TILE_SIZE)][(int)(x / TILE_SIZE)] == 0 &&
		grid[(int)(y / TILE_SIZE)][(int)((x + 2) / TILE_SIZE)] == 0 &&
		grid[(int)((y + 2) / TILE_SIZE)][(int)((x + 2) / TILE_SIZE)] == 0)
		return (0);
	return (1);
}
/*
이동한 플레이어의 x, y  좌표 계산 후 맵의 위치 확인.
*/
void		move_player(t_player *player, t_cub *cub)
{
	float	move_step;
	float	new_x;
	float	new_y;
	float	strafe_angle;
	float	strafe_step;

	player->rotation_angle += player->turn_direction * player->turn_speed;  //player.angle 설정
	player->rotation_angle = normalize_angle(player->rotation_angle);  //각도 일반화.
	strafe_step = player->strafe_direction * player->walk_speed;      //옆으로 간 길이. ( A , D 키를 통해 )
	strafe_angle = 0.5 * PI * (player->strafe_direction != 0);       //옆으로 간 각도 설정   현재 방향에 90도
	move_step = player->walk_direction * player->walk_speed;        //전방으로 간 거리
	new_x = player->x + cos(player->rotation_angle) * move_step +    //x 좌표 계산.  전방으로 간 rotation_angle  cos X 
		cos(player->rotation_angle + strafe_angle) * strafe_step;    // + 옆으로 간 strafe_angle cos X 더하기
	new_y = player->y + sin(player->rotation_angle) * move_step +   //y 도 마찬가지
		sin(player->rotation_angle + strafe_angle) * strafe_step;
	if (check_collision(cub, new_x, new_y) == 0)
	{
		player->x = new_x;
		player->y = new_y;
	}
}
