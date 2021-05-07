/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:06 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 11:59:12 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_element(int x, int y, t_cub *cub)
{
	return (cub->map.grid[y][x]);
}

static void	set_element(int x, int y, int color, t_cub *cub)
{
	cub->map.grid[y][x] = color;
}

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

void		boundary_fill(int x, int y, int *open, t_cub *cub)
{
	if (x < 0 || y < 0 || x >= cub->map.width ||
			y >= cub->map.height || get_element(x, y, cub) == SPACE)
	{
		*open = TRUE;
		return ;
	}
	if (get_element(x, y, cub) != WALL &&
			get_element(x, y, cub) != FILL)
	{
		set_element(x, y, FILL, cub);
		boundary_fill(x + 1, y, open, cub);
		boundary_fill(x, y + 1, open, cub);
		boundary_fill(x - 1, y, open, cub);
		boundary_fill(x, y - 1, open, cub);
	}
}
