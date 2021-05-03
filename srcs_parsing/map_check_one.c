/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:17:20 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 13:56:38 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		pos_player_check(int *line_map)
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

int		first_last_line_check(t_pars *par, int *line)
{
	int 	i;
	int		wall_present;

	i = -1;
	wall_present = 0;
	while (line[++i] != -2)
	{
		if (line[i] != 1 && line[i] != -1)
			return (0);
		if (line[i] == 1)
			wall_present = 1;
	}
	if (!wall_present)
		error_msg_map("File .cub, map : First line and last line"
		" must contains at least one wall\n", par, line);
	return (1);
}

int		len_line_map(int *line)
{
	int		i;

	i = 0;
	while (line[i] != -2)
		i++;
	return (i);
}

void	line_is_ended_by_wall(t_pars *par, int *line)
{
	if (line[len_line_map(line) - 1] != 1)
		error_msg_map("File .cub, map : each line of the map must be "
		"terminated by a wall\n", par, line);
}

void	walls_check_previous(t_pars *par, int i, int *previous)
{
	long	j;

	j = len_line_map(previous) - 1;
	i--;
	while (++i <= 0)
		if (previous[j + i] != 1 && previous[j + i] != -1)
			error_msg_map("File .cub, map : must only be"
			" surrunded by walls ('1')\n", par, previous);
}
