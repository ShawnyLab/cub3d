/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:09 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 14:04:24 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
/*
cub에 텍스쳐 (동서남북, 스프라이트) 저장. 플래그 설정
*/
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
	else
		return (save_texture(flags, SPRITE_TEX, SPRITE, cub));
}
