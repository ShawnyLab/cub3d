/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:04 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 12:00:05 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parse_resolution(int *flags, t_cub *cub)
{
	char	**info;
	int		len_width;
	int		len_height;

	info = cub->info;
	if (*flags & RESOLUTION || ft_strarrlen(info) != 3 ||
			(len_width = strlen_isdigit(info[1])) < 1 ||
			(len_height = strlen_isdigit(info[2])) < 1 ||
			*info[1] == '0' || *info[2] == '0')
		return (-1);
	else
	{
		cub->width = len_width < 10 ? ft_atoi(info[1]) : INT_MAX;
		cub->height = len_height < 10 ? ft_atoi(info[2]) : INT_MAX;
	}
	ft_free_strarr(info);
	*flags |= RESOLUTION;
	return (0);
}
