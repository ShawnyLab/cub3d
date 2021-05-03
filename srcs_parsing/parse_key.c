/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:06:17 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:00:27 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		key_map_line(t_pars *par, char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr("0123456789NSWE ", line[i]) && !par->map)
			return (0);
		else if (!ft_strchr("0123456789NSWE ", line[i]) && par->map)
			error_msg("File .cub, map : must only contains ' 01234567NSWE' characters\n", par, line);
	}
	return (1);
}

int		key_type(char *line, t_pars *par)
{
	int		key;

	key = 0;
	line[0] == 'R' && line[1] == ' ' ? key = RESO : 0;
	line[0] == 'N' && line[1] == 'O' && line[2] == ' ' ? key = P_NORTH : 0;
	line[0] == 'S' && line[1] == 'O' && line[2] == ' ' ? key = P_SOUTH : 0;
	line[0] == 'E' && line[1] == 'A' && line[2] == ' ' ? key = P_EAST : 0;
	line[0] == 'W' && line[1] == 'E' && line[2] == ' ' ? key = P_WEST : 0;
	line[0] == 'S' && line[1] == ' ' ? key = P_SPRIT : 0;
	line[0] == 'F' && line[1] == ' ' ? key = FLO_RGB : 0;
	line[0] == 'F' && line[1] == 'B' && line[2] == ' ' ? key = P_B_FLOOR : 0;
	line[0] == 'C' && line[1] == ' ' ? key = SKY_RGB : 0;
	line[0] == 'C' && line[1] == 'B' && line[2] == ' ' ? key = P_B_SKY : 0;
	line[0] == 'D' && line[1] == 'B' && line[2] == ' ' ? key = P_B_DOOR : 0;
	if (key)
		return (key);
	else if (line[0] == '\0')
	{
		if (par->reso[0] == -1 && !par->path_no && !par->path_so && !par->path_ea
			&& !par->path_we && !par->path_sp && par->flo_rgb == -1
			&& par->sky_rgb == -1 && !par->map)
			error_msg("File .cub : must begin by one element\n", par, line);
		return (0);
	}
	else if (key_map_line(par, line))
		return (MAP_LINE);
	else
		error_msg("File .cub, keys : wrong key, or some lines between keys aren't empty\n"
		"Expected keys : 'R', 'NO', 'SO', 'EA', 'WE', 'S', 'F', 'FB', 'C', 'CB', 'DB' followed by\n"
		"at least one space and first line of the map containing only ' 012NSWE' characters\n", par, line);
	return (-1); 
}

int		numbers_key_missing(t_pars *par)
{
	int i;

	i = 0;
	par->reso[0] == -1 ? i++ : 0;
	!par->path_no ? i++ : 0;
	!par->path_so ? i++ : 0;
	!par->path_ea ? i++ : 0;
	!par->path_we ? i++ : 0;
	!par->path_sp ? i++ : 0;
	!par->path_b_fl ? i++ : 0;
	!par->path_b_sk ? i++ : 0;
	!par->path_b_do ? i++ : 0;
	par->flo_rgb == -1 ? i++ : 0;
	par->sky_rgb == -1 ? i++ : 0;
	!par->map ? i++ : 0;
	return (i);
}

void	key_check(t_pars *par)
{
	if (numbers_key_missing(par) > 1)
		error_msg("File .cub, keys : several keys are missing. Expected keys :\n"
		"'R ', 'NO ', 'SO ', 'EA ', 'WE ', 'S ', 'F ', 'C ', 'FB ', 'CB ', 'DB ',\n"
		"and first line of the map containing only ' 012NSWE' characters\n", par, NULL);
	else if (par->reso[0] == -1)
		error_msg("File .cub, resolution : 'R ' key is missing\n", par, NULL);
	else if (!par->path_no)
		error_msg("File .cub, path : 'NO ' key is missing\n", par, NULL);
	else if (!par->path_so)
		error_msg("File .cub, path : 'SO ' key is missing\n", par, NULL);
	else if (!par->path_ea)
		error_msg("File .cub, path : 'EA ' key is missing\n", par, NULL);
	else if (!par->path_we)
		error_msg("File .cub, path : 'WE ' key is missing\n", par, NULL);
	else if (!par->path_sp)
		error_msg("File .cub, path : 'S ' key is missing\n", par, NULL);
	else if (!par->path_b_fl)
		error_msg("File .cub, path : 'FB ' key is missing\n", par, NULL);
	else if (!par->path_b_sk)
		error_msg("File .cub, path : 'CB ' key is missing\n", par, NULL);
	else if (!par->path_b_do)
		error_msg("File .cub, path : 'DB ' key is missing\n", par, NULL);
	else if (par->flo_rgb == -1)
		error_msg("File .cub, colors : 'F ' key is missing\n", par, NULL);
	else if (par->sky_rgb == -1)
		error_msg("File .cub, colors : 'C ' key is missing\n", par, NULL);
	else if (!par->map)
		error_msg("File .cub, map : Map is missing\n", par, NULL);
}
