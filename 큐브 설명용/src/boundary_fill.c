/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:06 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 22:11:56 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
cub.map.grid 에서 그 좌표의 정보를 가져옴
*/
static int	get_element(int x, int y, t_cub *cub)
{
	return (cub->map.grid[y][x]);
}
/*
좌표에 색을 설정해줌.
*/
static void	set_element(int x, int y, int color, t_cub *cub)
{
	cub->map.grid[y][x] = color;
}
/*
cub.map.grid 모든 좌표의 FILL을 EMPTY 로 바꿔줌  3 -> 0
*/
void		rev_boundary_fill(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (cub->map.grid[y][x] == FILL)
				cub->map.grid[y][x] = EMPTY;
			x++;
		}
		y++;
	}
}
/*
x , y : 현재 플레이어의  좌표 를 기준으로 상하좌우를 검색하여 맵이 오픈되어있는지를 판단함.
오픈된 맵이면 리턴을 해주고 , open = TRUE
잘 닫힌 맵이면 플레이어 위치 기준 상하좌우를 FILL로 바꿔줌.
*/
void		boundary_fill(int x, int y, int *open, t_cub *cub)
{
	if (x < 0 || y < 0 || x >= cub->map.width ||
			y >= cub->map.height || get_element(x, y, cub) == SPACE)    //에러 SPACE 이면 맵 바깥임.
	{
		*open = TRUE;    //맵이 오픈되어있음.
		return ;
	}
	if (get_element(x, y, cub) != WALL &&
			get_element(x, y, cub) != FILL)
	{
		set_element(x, y, FILL, cub);    //위치를 FILL 3 으로 바꿈
		boundary_fill(x + 1, y, open, cub);     //모든 맵을 체크하며, 공백을 기준으로 열린 맵인지를 체크.
		boundary_fill(x, y + 1, open, cub);
		boundary_fill(x - 1, y, open, cub);
		boundary_fill(x, y - 1, open, cub);
	}
}
