/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:51:53 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 13:59:20 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		map_check(t_pars *par)
{
	long	i;
	int		pos;

	i = 0;
	pos = 0;
	while (par->map[i])
	{
		pos += pos_player_check(par->map[i++]);
		pos > 1 ? error_msg_map("File .cub, map : several player positions\n", par , par->map[i - 1]) : 0;
	}
	!pos ? error_msg("File .cub, map : no player position\n", par, NULL) : 0;
	if (!first_last_line_check(par, par->map[0]))
		error_msg_map("File .cub, map : first line must be only '1' and/or spaces\n", par, par->map[0]);
	if (!first_last_line_check(par, par->map[i - 1]))
		error_msg_map("File .cub, map : last line must be only '1' and/or spaces\n", par, par->map[i - 1]);
	while (--i > 0)
		walls_check(par, par->map[i], par->map[i - 1]);
	while (par->map[++i + 1])
		doors_check(par, par->map[i + 1], par->map[i], par->map[i - 1]);
	return (1);
}