/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:01:05 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 21:37:36 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
공백 을 모두 2로 채우고 나머지는 문자를 숫자로 바꿈
*/
static int	save_row(char *row, int y, t_cub *cub)
{
	int	x;
	int	**grid;
	int	*grid_row;

	if ((grid_row = malloc(sizeof(int) * cub->map.width)) == NULL)
		return (-1);
	grid = cub->map.grid;
	grid[y] = grid_row;
	x = 0;
	while (row[x])
	{
		if (row[x] == ' ')
			grid[y][x] = 2;
		else
			grid[y][x] = row[x] - '0';
		x++;
	}
	while (x < cub->map.width)
	{
		grid[y][x] = 2;
		x++;
	}
	return (0);
}
/*
맵을 한줄한줄 cub.map 의 int** grid 에 저장함
*/
static int	save_grid(t_list *trav, t_cub *cub)
{
	int	y;

	cub->map.grid = malloc(sizeof(int *) * cub->map.height);
	if (cub->map.grid == NULL)
		return (-1);
	y = 0;
	while (trav)
	{
		cub->row = trav->content;
		if (save_row(cub->row, y, cub) == -1)
		{
			ft_free_int_matrix(cub->map.grid, y);
			cub->map.grid = NULL;
			return (-1);
		}
		y++;
		trav = trav->next;
	}
	return (0);
}

static void	set_sprite(int x, int y, int i, t_cub *cub)
{
	cub->sprites[i].map_x = x;
	cub->sprites[i].map_y = y;
	cub->sprites[i].tex_id = SPRITE;
	cub->row[x] = '0';
}
/*
스프라이트의 위치 정보를 저장.  저장했으면 2에서 0으로 바꿔줌.
*/
static int	save_sprite_positions(t_list *trav, t_cub *cub)
{
	int		y;
	int		x;
	int		i;

	if ((cub->sprites = malloc(sizeof(t_sprite) * cub->map.sprites)) == NULL)
		return (-1);
	y = 0;
	i = 0;
	while (trav)
	{
		cub->row = trav->content;
		x = 0;
		while (cub->row[x])
		{
			if (cub->row[x] == '2')
			{
				set_sprite(x, y, i, cub);
				i++;
			}
			x++;
		}
		y++;
		trav = trav->next;
	}
	return (0);
}
/*
save_grid를 통해 맵에있는 모든 문자를 **int grid에 넣음.  내 위치 (NSWE) , 스프라이트는
위치를 저장한 후에 0으로 바꿔줌.
*/
int			save_map(t_list *trav, t_cub *cub)
{
	if (cub->map.sprites != 0)
		if (save_sprite_positions(trav, cub) == -1)
			return (-1);
	if (save_grid(trav, cub) == -1)
		return (-1);
	return (0);
}
