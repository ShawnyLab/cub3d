/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:42:28 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 13:58:16 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	walls_check_actual(t_pars *par, int i, int *actual, int *previous)
{
	long	j;

	j = len_line_map(previous) - 1;
	i++;
	while (--i >= 0)
		if (actual[j + i] != 1 && actual[j + i] != -1)
			error_msg_map("File .cub, map : must only be"
			" surrunded by walls ('1')\n", par, actual);
}

void	check_spaces_actual(t_pars *par, int i, int *actual, int *previous)
{
	int		bad_charac;
	int		j;

	bad_charac = 0;
	j = len_line_map(previous) - 1;
	if (i != 0)
		bad_charac += (actual[i - 1] != -1 && actual[i - 1] != 1) ? 1 : 0;
	if (actual[i + 1] != -2)
		bad_charac += (actual[i + 1] != -1 && actual[i + 1] != 1) ? 1 : 0;
	if (i != 0 && i - 1 <= j)		
		bad_charac += (previous[i - 1] != -1 && previous[i - 1] != 1) ? 1 : 0;
	if (i <= j)
		bad_charac += (previous[i] != -1 && previous[i] != 1) ? 1 : 0;
	if (i + 1 <= j)
		bad_charac += (previous[i + 1] != -1 && previous[i + 1] != 1) ? 1 : 0;
	if (bad_charac)
		error_msg_map("File .cub, map : must only be surrunded"
				" by walls ('1)\n", par, previous);
}

void	check_spaces_previous(t_pars *par, int i, int *actual, int *previous)
{
	int		bad_charac;
	int		j;

	bad_charac = 0;
	j = len_line_map(actual) - 1;
	if (i != 0)
		bad_charac += (previous[i - 1] != -1 && previous[i - 1] != 1) ? 1 : 0;
	if (previous[i + 1] != -2)
		bad_charac += (previous[i + 1] != -1 && previous[i + 1] != 1) ? 1 : 0;
	if (i != 0 && i - 1 <= j)
		bad_charac += (actual[i - 1] != -1 && actual[i - 1] != 1) ? 1 : 0;
	if (i <= j)
		bad_charac += (actual[i] != -1 && actual[i] != 1) ? 1 : 0;
	if (i + 1 <= j)
		bad_charac += (actual[i + 1] != -1 && actual[i + 1] != 1) ? 1 : 0;
	if (bad_charac)
		error_msg_map("File .cub, map : must only be surrunded"
				" by walls ('1)\n", par, previous);
}

void	walls_check(t_pars *par, int *actual, int *previous)
{
	long	i;

	i = 0;
	if (actual[0] != 1 && actual[0] != -1)
		error_msg_map("File .cub, map : must only be surrunded"
				" by walls ('1)\n", par, previous);
	line_is_ended_by_wall(par, previous);
	line_is_ended_by_wall(par, actual);
	i = len_line_map(actual) - len_line_map(previous);
	if (i < 0)
		walls_check_previous(par, i, previous);
	else
		walls_check_actual(par, i, actual, previous);
	i = -1;
	while (actual[++i] != -2)
		if (actual[i] == -1)
			check_spaces_actual(par, i, actual, previous);
	i = -1;
	while (previous[++i] != -2)
		if (previous[i] == -1)
			check_spaces_previous(par, i, actual, previous);
}

void	doors_check(t_pars *par, int *next, int *actual, int *previous)
{
	int		i;

	i = -1;
	while (actual[++i] != -2)
	{
		if ((actual[i] == 2 || actual[i] == 3) && !((actual[i - 1] == 1 &&
				actual[i + 1] == 1 && previous[i] != 1 && next[i] != 1) ||
				(actual[i - 1] != 1 && actual[i + 1] != 1 && previous[i]
				== 1 && next[i] == 1)))
			error_msg_map("File .cub, map : doors must be surrunded by 2 walls\n", par, actual);
	}
}
