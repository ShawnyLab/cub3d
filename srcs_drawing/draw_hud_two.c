/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:08:34 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:14:29 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		number_color(t_mlx *mlx, int num, int row, int line)
{
	int		color;
	
	color = mlx->addr.num[row + NUMBER_IMG_R + num * (NUMBER_PIX_W + 1)
			+ line * mlx->info.num[SIZE_LINE] + NUMBER_IMG_L * mlx->info.num[SIZE_LINE]];
	return (color);
}

void	draw_number(t_mlx *mlx, t_info *info, int num, double row_screen)
{
	double	resize_w;
	double	resize_h;
	double	row;
	double	line;

	resize_h = (mlx->par->reso[1] / (double)NUMBER_PIX_H) * (NUMBER_SIZE_H);
	resize_w = (mlx->par->reso[0] / (double)NUMBER_PIX_W) * (NUMBER_SIZE_W);
	line = 0.0;
	row = 0.0;
	while ((int)(line / resize_h) < NUMBER_PIX_H)
	{
		row = 0.0;
		while ((int)(row / resize_w) < NUMBER_PIX_W)
		{
			if (number_color(mlx, num, (int)(row / resize_w), (int)(line / resize_h)) != INV_COLOR)
				mlx->addr.screen[(int)row + (int)(row_screen * mlx->par->reso[0]) + (int)(mlx->par->reso[1]
						* NUMBER_SCREEN_L) * info->screen[SIZE_LINE] + (int)line * info->screen[SIZE_LINE]]
						= number_color(mlx, num, (int)(row / resize_w), (int)(line / resize_h));
			row += 1.0;
		}
		line += 1.0;
	}
}

void	draw_all_hud_numbers(t_mlx *mlx, t_info *info)
{
	if (mlx->eve.lifebar == 100)
	{
		draw_number(mlx, info, 1, N_LIFE1_SCREEN_R);
		draw_number(mlx, info, 0, N_LIFE2_SCREEN_R);
	}
	else
		mlx->eve.lifebar / 10 > 0 ? draw_number(mlx, info, mlx->eve.lifebar / 10, N_LIFE2_SCREEN_R) : 0;
	draw_number(mlx, info, mlx->eve.lifebar % 10, N_LIFE3_SCREEN_R);
	mlx->eve.ammo >= 10 ? draw_number(mlx, info, mlx->eve.ammo / 10, N_AMMO1_SCREEN_R) : 0;
	draw_number(mlx, info, mlx->eve.ammo % 10, N_AMMO2_SCREEN_R);
	draw_number(mlx, info, mlx->eve.level, N_LEVEL_SCREEN_R);
}

int		heart_color(t_mlx *mlx, int row, int line)
{
	int		color;
	
	color = mlx->addr.life[row + HEART_IMG_R + line * mlx->info.life[SIZE_LINE]
			+ HEART_IMG_L * mlx->info.life[SIZE_LINE]];
	return (color);
}

void	draw_one_heart(t_mlx *mlx, t_pars *par, t_info *info, double row_screen)
{
	double	resize_w;
	double	resize_h;
	double	row;
	double	line;
	
	resize_h = (par->reso[1] / (double)HEART_PIX_H) * (HEART_SIZE_H);
	resize_w = (par->reso[0] / (double)HEART_PIX_W) * (HEART_SIZE_W);
	line = 0.0;
	row = 0.0;
	while ((int)(line / resize_h) < HEART_PIX_H)
	{
		row = 0.0;
		while ((int)(row / resize_w) < HEART_PIX_W)
		{
			if (heart_color(mlx, (int)(row / resize_w), (int)(line / resize_h)) != INV_COLOR)
				mlx->addr.screen[(int)row + (int)(row_screen * mlx->par->reso[0]) + (int)(mlx->par->reso[1]
						* HEART_SCREEN_L) * info->screen[SIZE_LINE] + (int)line * info->screen[SIZE_LINE]]
						= heart_color(mlx, (int)(row / resize_w), (int)(line / resize_h));
			row += 1.0;
		}
		line += 1.0;
	}
}
