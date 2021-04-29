/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:17:20 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 22:00:02 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_check_end(t_pars *par, int *line)
{
	if (line[ft_len_map(line) - 1] != 1)
		ft_maperror("File .cub, map : each line of the map must be "
		"terminated by a wall\n", par, line);
}

void	ft_check_wall(t_pars *par, int *now, int *bef)
{
	long	i;

	i = 0;
	if (now[0] != 1 && now[0] != -1)
		ft_maperror("File .cub, map : must only be surrunded"
				" by walls ('1)\n", par, bef);
	ft_check_end(par, bef);
	ft_check_end(par, now);
	i = ft_len_map(now) - ft_len_map(bef);
	if (i < 0)
		ft_check_bef(par, i, bef);
	else
		ft_check_now(par, i , now, bef);
	i = -1;
	while (now[++i] != -2)
		if (now[i] == -1)
			ft_now_spaces(par, i, now, bef);
	i = -1;
	while (bef[++i] != -2)
		if (bef[i] == -1)
			ft_bef_spaces(par, i , now, bef);
}

int		ft_check_blocked(t_pars *par, int *line)
{
	int		i;
	int		wall;

	i = -1;
	wall = 0;
	while (line[++i] != -2)
	{
		if (line[i] != 1 && line[i] != -1)
			return (0);
		if (line[i] == 1)
			wall = 1;
	}
	if (!wall)
		ft_maperror("File .cub, map : First line and last line"
		" must contains at least one wall\n", par, line);
	return (1);
}

int		ft_player_pos(int *line_map)
{
	int		i;
	int		pos;

	i = -1;
	pos = 0;
	while (line_map[++i] != -2)
	{
		if (line_map[i] == NORTH || line_map[i] == SOUTH || 
			line_map[i] == EAST || line_map[i] == WEST)
			pos++;
	}
	return (pos);
}

int		ft_check_map(t_pars *par)
{
	long	i;
	int		pos;

	i = 0;
	pos = 0;
	while (par->map[i])
	{
		pos += ft_player_pos(par->map[i++]);
		pos > 1 ? ft_maperror("File .cub, map : several player positions\n", par , par->map[i - 1]) : 0;
	}
	!pos ? ft_maperror("File .cub, map : no player position\n", par, NULL) : 0;
	if (!ft_check_blocked(par, par->map[0]))
		ft_maperror("File .cub, map : first line must be only '1' and/or spaces\n", par, par->map[0]);
	if (!ft_check_blocked(par, par->map[i - 1]))
		ft_maperror("File .cub, map : last line must be only '1' and/or spaces\n", par, par->map[i - 1]);
	while (--i > 0)
		ft_check_wall(par, par->map[i], par->map[i - 1]);
	
}