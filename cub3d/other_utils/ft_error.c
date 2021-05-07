/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:38:31 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 11:38:32 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error_pt3(int errornbr)
{
	if (errornbr == NOT_CUB_ERROR)
		printf("please cub");
	if (errornbr == INVALID_FILE)
		printf("invalid file");
	return (0);
}

int		ft_error_pt2(int errornbr)
{
	if (errornbr == BADSPRITE)
		printf("can't open sprite textures");
	if (errornbr == MULTIFLOOR)
		printf("multiple floor colors");
	if (errornbr == BADFLOOR)
		printf("invalid floor colors");
	if (errornbr == MULTICEIL)
		printf("multiple ceiling colors");
	if (errornbr == BADCEIL)
		printf("invalid ceiling colors");
	if (errornbr == INVALIDMAP)
		printf("invalid map");
	if (errornbr == INVALIDCHAR)
		printf("invalid character in cub text");
	if (errornbr == MISSINGPARAMS)
		printf("missing at least one parameter");
	if (errornbr == PARSING_ERROR)
		printf("there was an error while parsing");
	return (0);
}

int		ft_error_pt1(int errornbr)
{
	if (errornbr == MULTIRES)
		printf("multiple resolutions");
	if (errornbr == BADSCREEN)
		printf("invalid screensize!");
	if (errornbr == MULTINO)
		printf("multiple north textures");
	if (errornbr == BADNO)
		printf("can't open north textures");
	if (errornbr == MULTISO)
		printf("multiple south textures");
	if (errornbr == BADSO)
		printf("can't open south textures");
	if (errornbr == MULTIWE)
		printf("multiple west textures");
	if (errornbr == BADWE)
		printf("can't open west textures");
	if (errornbr == MULTIEA)
		printf("multiple east textures");
	if (errornbr == BADEA)
		printf("can't open east textures");
	if (errornbr == MULTISPRITE)
		printf("multiple sprite textures");
	return (0);
}

int		ft_error(int errornbr)
{
	ft_error_pt1(errornbr);
	ft_error_pt2(errornbr);
	ft_error_pt3(errornbr);
	return (0);
}
