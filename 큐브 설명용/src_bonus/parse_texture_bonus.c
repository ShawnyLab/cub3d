/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:02:43 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 12:02:44 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

static int	save_texture(int *flags, int flag, int tex_id, t_cub *cub)
{
	if (*flags & flag || ft_strarrlen(cub->info) != 2)
		return (-1);
	cub->map.paths[tex_id] = cub->info[1];
	free(cub->info[0]);
	free(cub->info);
	*flags |= flag;
	return (0);
}

int			parse_texture(int *flags, t_cub *cub)
{
	char	**info;

	info = cub->info;
	if (!ft_strcmp(*info, "NO"))
		return (save_texture(flags, NORTH_TEX, NORTH, cub));
	else if (!ft_strcmp(*info, "SO"))
		return (save_texture(flags, SOUTH_TEX, SOUTH, cub));
	else if (!ft_strcmp(*info, "WE"))
		return (save_texture(flags, WEST_TEX, WEST, cub));
	else if (!ft_strcmp(*info, "EA"))
		return (save_texture(flags, EAST_TEX, EAST, cub));
	else if (!ft_strcmp(*info, "S"))
		return (save_texture(flags, SPRITE_TEX, SPRITE, cub));
	else
		return (save_texture(flags, SSPRITE_TEX, SSPRITE, cub));
}
