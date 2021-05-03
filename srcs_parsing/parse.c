/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:02:13 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:08:25 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	check_spaces_end_of_line(t_pars *par, char *line, int key)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	if (i && line[i - 1] == ' ')
	{
		key == RESO ? error_msg("File .cub, resolution : Spaces"
				" at the end of 'R' line are not allowed\n", par, line) : 0;
		key == P_NORTH ? error_msg("File .cub, path : Spaces"
				" at the end of 'NO' line are not allowed\n", par, line) : 0;
		key == P_SOUTH ? error_msg("File .cub, path : Spaces"
				" at the end of 'SO' line are not allowed\n", par, line) : 0;
		key == P_EAST ? error_msg("File .cub, path : Spaces"
				" at the end of 'EA' line are not allowed\n", par, line) : 0;
		key == P_WEST ? error_msg("File .cub, path : Spaces"
				" at the end of 'WE' line are not allowed\n", par, line) : 0;
		key == P_SPRIT ? error_msg("File .cub, path : Spaces"
				" at the end of 'S' line are not allowed\n", par, line) : 0;
		key == P_B_FLOOR ? error_msg("File .cub, path : Spaces"
				" at the end of 'FB' line are not allowed\n", par, line) : 0;
		key == P_B_SKY ? error_msg("File .cub, path : Spaces"
				" at the end of 'CB' line are not allowed\n", par, line) : 0;
		key == P_B_DOOR ? error_msg("File .cub, path : Spaces"
				" at the end of 'DB' line are not allowed\n", par, line) : 0;
		key == FLO_RGB ? error_msg("File .cub, colors : Spaces"
				" at the end of 'F' line are not allowed\n", par, line) : 0;
		key == SKY_RGB ? error_msg("File .cub, colors : Spaces"
				" at the end of 'C' line are not allowed\n", par, line) : 0;
	}
}

int		parse_func(t_pars *par, char *line, int key)
{
	int		ret;

	ret = 1;
	if (key == RESO)
		ret = parse_reso(par, line);
	else if (key == P_NORTH)
		ret = parse_path(par, &(par->path_no), line);
	else if (key == P_SOUTH)
		ret = parse_path(par, &(par->path_so), line);
	else if (key == P_EAST)
		ret = parse_path(par, &(par->path_ea), line);
	else if (key == P_WEST)
		ret = parse_path(par, &(par->path_we), line);
	else if (key == P_SPRIT)
		ret = parse_path(par, &(par->path_sp), line);
	else if (key == P_B_FLOOR)
		ret = parse_path(par, &(par->path_b_fl), line);
	else if (key == P_B_SKY)
		ret = parse_path(par, &(par->path_b_sk), line);
	else if (key == P_B_DOOR)
		ret = parse_path(par, &(par->path_b_do), line);
	else if (key == FLO_RGB)
		ret = parse_flo_rgb(par, line);
	else if (key == SKY_RGB)
		ret = parse_sky_rgb(par, line);
	return (ret);
}

int		parsing(t_pars *par)
{
	char	*line;
	int		ret;
	int		key;

	line = NULL;
	ret = 1;
	while (ret > 0 && key != MAP_LINE)
	{
		ret = get_next_line(par->fd, &line);
		key = key_type(line, par);
		check_spaces_end_of_line(par, line, key);
		if (parse_func(par, line, key) == -1)
			error_msg("Malloc failed\n", par, line);
		if (key == MAP_LINE)
			parse_map(par, line);
		free(line);
	}
	while (ret > 0 && key == MAP_LINE)
	{
		ret = get_next_line(par->fd, &line);
		key = key_type(line, par);
		key == MAP_LINE ? parse_map(par, line) : 0;
		free(line);
	}
	if (!key)
		error_msg("File .cub, map : must end the file and be followed by nothing\n", par, NULL);
	else if (key && key != MAP_LINE)
		error_msg("File .cub, map : must only contains ' 0123456789NSWE' characters\n", par, NULL);
	key_check(par);
	map_check(par);
	return (1);
}
