/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:02:13 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 21:09:06 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_check_sp(t_pars *par, char *line, int key)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i && line[i - 1] == ' ')
	{
		key == RESO ? ft_str_error("File .cub, resolution : Spaces"
				" at the end of 'R' line are not allowed\n", par, line) : 0;
		key == P_NORTH ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'NO' line are not allowed\n", par, line) : 0;
		key == P_SOUTH ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'SO' line are not allowed\n", par, line) : 0;
		key == P_EAST ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'EA' line are not allowed\n", par, line) : 0;
		key == P_WEST ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'WE' line are not allowed\n", par, line) : 0;
		key == P_SPRIT ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'S' line are not allowed\n", par, line) : 0;
		key == P_B_FLOOR ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'FB' line are not allowed\n", par, line) : 0;
		key == P_B_SKY ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'CB' line are not allowed\n", par, line) : 0;
		key == P_B_DOOR ? ft_str_error("File .cub, path : Spaces"
				" at the end of 'DB' line are not allowed\n", par, line) : 0;
		key == FLO_RGB ? ft_str_error("File .cub, colors : Spaces"
				" at the end of 'F' line are not allowed\n", par, line) : 0;
		key == SKY_RGB ? ft_str_error("File .cub, colors : Spaces"
				" at the end of 'C' line are not allowed\n", par, line) : 0;
	}
}

int		ft_parse_func(t_pars *par, char *line, int key)
{
	int 	ret;

	ret = 1;
	if (key == RESO)
		ret = ft_reso(par, line);
	else if (key == P_NORTH)
		ret = ft_parse_path(par, &(par->path_no), line);
	else if (key == P_SOUTH)
		ret = ft_parse_path(par, &(par->path_so), line);
	else if (key == P_EAST)
		ret = ft_parse_path(par, &(par->path_ea), line);
	else if (key == P_WEST)
		ret = ft_parse_path(par, &(par->path_we), line);
	else if (key == P_SPRIT)
		ret = ft_parse_path(par, &(par->path_sp), line);
	else if (key == P_B_FLOOR)
		ret = ft_parse_path(par, &(par->path_b_fl), line);
	else if (key == P_B_SKY)
		ret = ft_parse_path(par, &(par->path_b_sk), line);
	else if (key == P_B_DOOR)
		ret = ft_parse_path(par, &(par->path_b_do), line);
	else if (key == FLO_RGB)
		ret = ft_parse_rgb(par, line);
	else if (key == SKY_RGB)
		ret = ft_parse_sky_rgb(par, line);
	return (ret);
}


int		ft_parse(t_pars *par)
{
	char	*line;
	int		ret;
	int		key;

	line = NULL;
	ret = 1;
	while (ret > 0 && key != MAP_LINE)
	{
		ret = get_next_line(par->fd, &line);
		key = ft_keytype(line, par);
		ft_check_sp(par, line, key);
		if (ft_parse_func(par, line, key) == -1)
			ft_str_error("Malloc failed\n", par, line);
		if (key == MAP_LINE)
			ft_parse_map(par, line);
		free(line);
	}
	while (ret > 0 && key == MAP_LINE)
	{
		ret = get_next_line(par->fd, &line);
		key = ft_keytype(line, par);
		key == MAP_LINE ? ft_parse_map(par, line) : 0;
		free(line);
	}
	if (!key)
		ft_str_error("File .cub, map : must end the file and be followed by nothing\n", par, NULL);
	else if (key && key != MAP_LINE)
		ft_str_error("File .cub, map : must only contains ' 0123456789NSWE' characters\n", par, NULL);
	ft_check_key(par);
	ft_check_map(par);
	return (1);
}