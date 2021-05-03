/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:13:04 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 16:16:32 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		font1_color(t_mlx *mlx, int row, int line, int c)
{
	int		color;
	int		row_start;
	int		line_start;
	
	if (c >= 'A' && c <= 'Z')
		c -= 'A';
	else if (c >= '1' && c <= '9')
		c += -'1' + 30;
	else if (c == '-')
		c = 39;
	row_start = c % 8 * FONT_PIX_W;
	line_start = c / 8 * FONT_PIX_H + 5 * FONT_PIX_H;
	color = mlx->addr.font[row + line * mlx->info.font[SIZE_LINE] + row_start
			+ line_start * mlx->info.font[SIZE_LINE]];
	return (color);
}

void	draw_letter_font1(t_mlx *mlx, double line_screen, double row_screen, char c)
{
	double	resize_w;
	double	resize_h;
	double	row;
	double	line;
	
	resize_h = (mlx->par->reso[1] / (double)FONT_PIX_H) * (FONT1_SIZE_H);
	resize_w = (mlx->par->reso[0] / (double)FONT_PIX_W) * (FONT1_SIZE_W);
	line = 0.0;
	row = 0.0;
	while ((int)(line / resize_h) < FONT_PIX_H)
	{
		row = 0.0;
		while ((int)(row / resize_w) < FONT_PIX_W)
		{
			if (font1_color(mlx, (int)(row / resize_w), (int)(line / resize_h), (int)c) != INV_COLOR)
				mlx->addr.screen[(int)row + (int)(row_screen * mlx->par->reso[0]) 
						+ (int)(mlx->par->reso[1] * line_screen) * mlx->info.screen[SIZE_LINE] +
						(int)line * mlx->info.screen[SIZE_LINE]]
						= font1_color(mlx, (int)(row / resize_w), (int)(line / resize_h), (int)c);
			row += 1.0;
		}
		line += 1.0;
	}

}

void	draw_choose_your_level_message(t_mlx *mlx)
{
	int		i;

	i = 0;
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'C');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'H');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'O');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'O');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'S');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'E');
	i++; //space
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'Y');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'O');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'U');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'R');
	i++;
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'L');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'E');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'V');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'E');
	draw_letter_font1(mlx, FONT1_SCREEN_L, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'L');
}

void	draw_easy_medium_hard_message(t_mlx *mlx)
{
	int		i;

	i = 3;
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 2.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, '1');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 2.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, '-');
	i++;
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 2.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'E');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 2.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'A');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 2.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'S');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 2.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'Y');
	i = 3;
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, '2');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, '-');
	i++;
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'M');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'E');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'D');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'I');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'U');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 3.5, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'M');
	i = 3;
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 5.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, '3');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 5.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, '-');
	i++;
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 5.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'H');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 5.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'A');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 5.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'R');
	draw_letter_font1(mlx, FONT1_SCREEN_L + FONT1_SIZE_H * 5.0, FONT1_SCREEN_R + FONT1_SIZE_W * i++, 'D');
}

int		draw_level_menu(t_mlx *mlx)
{
	draw_colored_screen(mlx, 1, 0x0);
	draw_choose_your_level_message(mlx);
	draw_easy_medium_hard_message(mlx);
	mlx->eve.nb_life = NB_LIFE_START;
	return (1);
}