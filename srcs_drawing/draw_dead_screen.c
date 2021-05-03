/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dead_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:55:20 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:09:21 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		font2_color(t_mlx *mlx, int row, int line, int c)
{
	int		color;
	int		row_start;
	int		line_start;
	
	c -= 'A';
	row_start = c % 8 * FONT_PIX_W;
	line_start = c / 8 * FONT_PIX_H;
	color = mlx->addr.font[row + line * mlx->info.font[SIZE_LINE] + row_start
			+ line_start * mlx->info.font[SIZE_LINE]];
	return (color);
}

void	draw_letter_font2(t_mlx *mlx, double line_screen, double row_screen, char c)
{
	double	resize_w;
	double	resize_h;
	double	row;
	double	line;
	
	resize_h = (mlx->par->reso[1] / (double)FONT_PIX_H) * (FONT2_SIZE_H);
	resize_w = (mlx->par->reso[0] / (double)FONT_PIX_W) * (FONT2_SIZE_W);
	line = 0.0;
	while ((int)(line / resize_h) < FONT_PIX_H)
	{
		row = 0.0;
		while ((int)(row / resize_w) < FONT_PIX_W)
		{
			if (font2_color(mlx, (int)(row / resize_w), (int)(line / resize_h), (int)c) != INV_COLOR)
				mlx->addr.screen[(int)row + (int)(row_screen * mlx->par->reso[0]) 
						+ (int)(mlx->par->reso[1] * line_screen) * mlx->info.screen[SIZE_LINE] +
						(int)line * mlx->info.screen[SIZE_LINE]]
						= font2_color(mlx, (int)(row / resize_w), (int)(line / resize_h), (int)c);
			row += 1.0;
		}
		line += 1.0;
	}

}

void	draw_gameover_message(t_mlx *mlx)
{
	int		i;

	i = 0;
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'G');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'A');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'M');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'E');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'O');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'V');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'E');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'R');
}

void	draw_you_are_dead_message(t_mlx *mlx)
{
	int		i;

	i = -2;
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'Y');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'O');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'U');
	i++; //space
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'A');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'R');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'E');
	i++;
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'D');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'E');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'A');
	draw_letter_font2(mlx, FONT2_SCREEN_L, FONT2_SCREEN_R + FONT2_SIZE_W * i++, 'D');
}

void	draw_colored_screen(t_mlx *mlx, int nb_pixel, int color)
{
	int		i;

	i = 0;
	if (nb_pixel <= 0)
		return ;
	while (i < (int)mlx->par->reso[1] * mlx->info.screen[SIZE_LINE])
	{
		mlx->addr.screen[i] = color;
		i += nb_pixel;
	}
	mlx->eve.nb_life > 1 ? draw_you_are_dead_message(mlx) : 0;
	mlx->eve.nb_life == 1 ? draw_gameover_message(mlx) : 0;
}