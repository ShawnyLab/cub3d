/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_real.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:24:44 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/24 22:11:06 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_reso(t_pars *par, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (par->reso[0] != -1 || par->reso[1] != -1)
		ft_str_error("File .cub, resolution : multiple keys 'R'\n", par, line);
	if (!(tmp = ft_split(line, ' ')))
		return (-1);
	while (tmp[i])
		i++;
	if (i != 3 || !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]))
	{
		free_split(tmp);
		ft_str_error("File .cub, resolution : 3 arguments are waited\n"
		"The key (R), reso X and Y (those last two only in numbers)\n", par, line);
	}
	if (ft_strlen(tmp[1]) > (size_t)5)
		par->reso[0] = RESO_MAX_X;
	else
		par->reso[0] = (i = ft_atoi(tmp[1])) > RESO_MAX_X ? RESO_MAX_X : i;
	if (ft_strlen(tmp[2]) > (size_t)5)
		par->reso[1] = RESO_MAX_Y;
	else
		par->reso[1] = (i = ft_atoi(tmp[2])) > RESO_MAX_Y ? RESO_MAX_Y : i;
	free_split(tmp);
	return (1);
}

int		ft_parse_path(t_pars *par, char **path, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*path)
		ft_str_error("File .cub, path : multiple same keys\n", par, line);
	if (!(tmp = ft_split(line, ' ')))
		return (-1);
	while (tmp[i])
		i++;
	if (i != 2)
	{
		free_split(tmp);
		ft_str_error("File .cub, path : two arguments are waited\n"
		"The key, and then the path\n", par, line);
	}
	*path = tmp[1];
	free(tmp[0]);
	free(tmp);
	return (1);
}

int		ft_check_rgb(char *line)
{
	int	i;
	i = 1;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i++]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',' || !ft_isdigit(line[i++]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',' || !ft_isdigit(line[i++]))
		return (0);
	return (1);
}

int		ft_parse_rgb(t_pars *par, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (par->flo_rgb != -1)
		ft_str_error("File .cub, colors : multiple keys 'F'\n", par, line);
	if (!ft_check_rgb(line))
		ft_str_error("File .cub, colors : (F) RGB couple should respect format 'nb,nb,nb'\n", par, line);
	ft_replace_char(line, ' ' , ',');
	if (!(tmp = ft_split(line, ' ')))
		return (-1);
	while (tmp[i])
		i++;
	if (i != 4 || !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]) || !ft_strisdigit(tmp[3])
		|| ft_strlen(tmp[1]) > (size_t)3 || ft_strlen(tmp[2]) > (size_t)3
		|| ft_strlen(tmp[3]) > (size_t)3 || ((i = ft_atoi(tmp[1])) > 255)
		|| ((i = ft_atoi(tmp[2])) > 255) || ((i = ft_atoi(tmp[3])) > 255))
	{
		free_split(tmp);
		ft_str_error("File .cub, colors : 4 arguments are waited for the floor\n"
		"The key (F), R, G and B values (those last three between 000 and 255)\n", par, line);	
	}
	*((unsigned char *)(&par->flo_rgb)) = (unsigned char)ft_atoi(tmp[1]); //stocking each RGB color in an int, byte per byte
	*((unsigned char *)(&par->flo_rgb) + 1) = (unsigned char)ft_atoi(tmp[2]);
	*((unsigned char *)(&par->flo_rgb) + 2) = (unsigned char)ft_atoi(tmp[3]);
	*((unsigned char *)(&par->flo_rgb) + 3) = (unsigned char)0;
	free_split(tmp);
	return (1);
}

int		ft_parse_sky_rgb(t_pars *par, char *line)
{
	int	i;
	char **tmp;

	i = 0;
	if (par->sky_rgb != -1)
		ft_str_error("File .cub, colors : multiple keys 'C'.\n", par, line);
	if (!ft_check_rgb(line))
		ft_str_error("File .cub, colors : (C) RGB couple should respect format 'nb,nb,nb'\n", par, line);
	ft_replace_char(line, ' ' , ',');
	if (!(tmp = ft_split(line, ' ')))
		return (-1);
	while (tmp[i])
		i++;
		if (i != 4 || !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]) || !ft_strisdigit(tmp[3])
		|| ft_strlen(tmp[1]) > (size_t)3 || ft_strlen(tmp[2]) > (size_t)3
		|| ft_strlen(tmp[3]) > (size_t)3 || ((i = ft_atoi(tmp[1])) > 255)
		|| ((i = ft_atoi(tmp[2])) > 255) || ((i = ft_atoi(tmp[3])) > 255))
	{
		free_split(tmp);
		ft_str_error("File .cub, colors : 4 arguments are waited for the sky\n"
		"The key (C), R, G and B values (those last three between 000 and 255)\n", par, line);
	}
	*((unsigned char *)(&par->sky_rgb)) = (unsigned char)ft_atoi(tmp[1]); //stocking each RGB color in an int, byte per byte
	*((unsigned char *)(&par->sky_rgb) + 1) = (unsigned char)ft_atoi(tmp[2]);
	*((unsigned char *)(&par->sky_rgb) + 2) = (unsigned char)ft_atoi(tmp[3]);
	*((unsigned char *)(&par->sky_rgb) + 3) = (unsigned char)0;
	free_split(tmp);
	return (1);
}