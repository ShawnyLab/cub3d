/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:06:17 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:51:36 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

//.cub 파일에 0123456789NSWE만 포함하는지 체크
int 	ft_map_line(t_pars *par, char *line)
{
	int	i;
	
	i = -1;
	while (line[++i])
	{
		if (!ft_strchr("0123456789NSWE ", line[i]) && !par->map)
			return (0);
		else if (!ft_strchr("0123456789NSWE ", line[i]) && par->map)
			ft_str_error("File .cub, map : must only contains ' 01234567NSWE' characters\n", par, line);
	}
	return (1);
}

int		ft_keytype(char *line, t_pars *par)
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
			ft_str_error("File .cub : must begin by one element\n", par, line);
		return (0);
	}
	else if (ft_map_line(par, line))
		return (MAP_LINE);
	else 
		ft_str_error("File .cub, keys : wrong key, or some lines between keys aren't empty\n"
		"Expected keys : 'R', 'NO', 'SO', 'EA', 'WE', 'S', 'F', 'FB', 'C', 'CB', 'DB' followed by\n"
		"at least one space and first line of the map containing only ' 012NSWE' characters\n", par, line);
	return (-1);
}

int		ft_cnt_keymiss(t_pars *par)
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

void	ft_check_key(t_pars *par)
{
	if (ft_cnt_keymiss(par) > 1)
		ft_str_error("File .cub, keys : several keys are missing. Expected keys :\n"
		"'R ', 'NO ', 'SO ', 'EA ', 'WE ', 'S ', 'F ', 'C ', 'FB ', 'CB ', 'DB ',\n"
		"and first line of the map containing only ' 012NSWE' characters\n", par, NULL);
	else if (par->reso[0] == -1)
		ft_str_error("File .cub, resolution : 'R ' key is missing\n", par, NULL);
	else if (!par->path_no)
		ft_str_error("File .cub, path : 'NO ' key is missing\n", par, NULL);
	else if (!par->path_so)
		ft_str_error("File .cub, path : 'SO ' key is missing\n", par, NULL);
	else if (!par->path_ea)
		ft_str_error("File .cub, path : 'EA ' key is missing\n", par, NULL);
	else if (!par->path_we)
		ft_str_error("File .cub, path : 'WE ' key is missing\n", par, NULL);
	else if (!par->path_sp)
		ft_str_error("File .cub, path : 'S ' key is missing\n", par, NULL);
	else if (!par->path_b_fl)
		ft_str_error("File .cub, path : 'FB ' key is missing\n", par, NULL);
	else if (!par->path_b_sk)
		ft_str_error("File .cub, path : 'CB ' key is missing\n", par, NULL);
	else if (!par->path_b_do)
		ft_str_error("File .cub, path : 'DB ' key is missing\n", par, NULL);
	else if (par->flo_rgb == -1)
		ft_str_error("File .cub, colors : 'F ' key is missing\n", par, NULL);
	else if (par->sky_rgb == -1)
		ft_str_error("File .cub, colors : 'C ' key is missing\n", par, NULL);
	else if (!par->map)
		ft_str_error("File .cub, map : Map is missing\n", par, NULL);
}