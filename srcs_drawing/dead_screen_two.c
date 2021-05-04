/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_screen_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 19:01:06 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 22:17:19 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_death_screen(t_mlx *mlx)
{
	int				i;
	struct timeval	end;
	double			time;

	i = 0;
	gettimeofday(&end, NULL);
	time = (double)(end.tv_usec - mlx->eve.time_player_death.tv_usec)
			/ 1000000.0 + (double)(end.tv_sec -
			mlx->eve.time_player_death.tv_sec);
	if (time < 0.01)
		draw_hud_and_gun_anims(mlx, mlx->par, &mlx->info);
	if (mlx->eve.nb_life > 1 && time < 3.0)
		draw_colored_screen(mlx, (int)((2.0 - time) * 10.0), 0x0);
	else if (mlx->eve.nb_life > 1)
	{
		mlx->eve.nb_life--;
		mlx->eve.lifebar = FULL_LIFE;
		mlx->cam->x = mlx->eve.start_pos_x;
		mlx->cam->y = mlx->eve.start_pos_y;
		mlx->cam->angle = mlx->eve.start_angle;
	}
	else
		draw_colored_screen(mlx, (int)((2.0 - time) * 10.0), 0x0);
}
