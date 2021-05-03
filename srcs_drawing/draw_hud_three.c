/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:33:11 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:18:46 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	draw_lives(t_mlx *mlx, t_pars *par, t_info *info)
{
	mlx->eve.nb_life == 3 ? draw_one_heart(mlx, par, info, HEART1_SCREEN_R) : 0;
	mlx->eve.nb_life >= 2 ? draw_one_heart(mlx, par, info, HEART2_SCREEN_R) : 0;
	draw_one_heart(mlx, par, info, HEART3_SCREEN_R);
}

void	draw_hud_and_gun_anims(t_mlx *mlx, t_pars *par, t_info *info)
{
	int						num_sprite_gun;
	double					time;
	static struct timeval	end;

	num_sprite_gun = 0;
	gettimeofday(&end, NULL);
	if (mlx->eve.gun_shot)
	{
		time = (double)(end.tv_usec - mlx->eve.gun_time_start.tv_usec) / 1000000.0 +
        (double)(end.tv_sec - mlx->eve.gun_time_start.tv_sec);
		num_sprite_gun = 1 + (int)(time * 15.0);
		num_sprite_gun >= 5 ? mlx->eve.gun_shot = 0 : 0;
		num_sprite_gun >= 5 ? num_sprite_gun = 4 : 0;
	}
	draw_gun(mlx, par, info, num_sprite_gun);
	draw_hud(mlx, par, info);
	draw_lifebar(mlx, par, info);
	draw_lives(mlx, par, info);
	draw_all_hud_numbers(mlx, info);
}
