/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:40:11 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 19:40:42 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_sprites	*ft_yray_spr_ptr(t_mlx *mlx, double angle, double x1, double y1)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if ((x1 || y1) && (angle > 90.0 && angle < 270.0)) //!x1 && !y1 when player is standing on a sprite' square
		x1 = (double)((int)(x1)) - 1.0; //at the intersection with y axe, checking if sprite at our left
	else if (mlx->cam->x + x1 - (double)((int)(mlx->cam->x + x1)) > 0.99)
		x1 = (double)((int)(x1)) + 1.0; //for an exception due to round error
	x = (int)(mlx->cam->x + x1);
	y = (int)(mlx->cam->y + y1);
	while (mlx->spri && mlx->spri[i] && ((int)mlx->spri[i]->y != y || (int)mlx->spri[i]->x != x))
		i++;									//looking for sprite of x and y coordinates
	if (!mlx->spri)	//in case of no sprites in the map
		return (NULL);
	return (mlx->spri[i]);
}