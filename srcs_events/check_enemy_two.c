/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:17:48 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:46:13 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	check_guard_detect_player(t_mlx *mlx, t_rcast *cam, t_sprites *spri)
{
	double	angle;
	double	x_ray;
	double	y_ray;
	int		wasnt_seeing;

	if (spri->guard.status >= DYING)
		return ;
	wasnt_seeing = spri->guard.status;
	spri->guard.status = NOT_SEEING;
	angle = find_angle(cam, spri);
	x_ray = x_ray_len_wall(mlx, cam, angle);
	y_ray = y_ray_len_wall(mlx, cam, angle);
	if (y_ray != y_ray || x_ray <= y_ray)
		ray_len(cam->x, cam->y, spri->x, spri->y) < x_ray ? spri->guard.status = DETECTING_PLAYER : 0;
	else if (ray_len(cam->x, cam->y, spri->x, spri->y) < y_ray)
		spri->guard.status = DETECTING_PLAYER;
	if (!wasnt_seeing && spri->guard.status == DETECTING_PLAYER)
		gettimeofday(&spri->guard.time_detect, NULL);
}