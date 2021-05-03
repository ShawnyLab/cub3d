/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:12:51 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:21:28 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		sprite_color(t_mlx *mlx, t_sprites *spri, int x, int type)
{
	int		row_img;
	int		*addr;
	int		*info;
	int		color;

	row_img = spri->row_percent * WALL_SIZE;
	x = (int)((double)x * spri->freq_pixel);
	addr = sprite_info_addr(mlx, &info, type);
	if (x >= info[WIDTH])
		x = info[WIDTH] - 1;
	if (type == SP_GUARD)
		color = addr[row_img + spri->guard.row_img + spri->guard.line_img * info[SIZE_LINE]
				+ spri->start_line_img * info[SIZE_LINE] + x * info[SIZE_LINE]];
	else
		color = addr[row_img + spri->start_line_img * info[SIZE_LINE] + x * info[SIZE_LINE]];
	return (color);
}

void	draw_sprites(t_mlx *mlx, t_sprites **spri, int screen_row)
{
	int		i;
	int		x;
	int		nb_start_print;
	int		color;
	
	i = 0;
	sort_sprites_tab(spri);
	while (spri && spri[i] && spri[i]->ray_len >= 0.0)
	{
		spri[i]->nb_pix = height_object(mlx->cam, spri[i]->ray_len);
		sprite_resizing(mlx, spri[i], &(spri[i]->nb_pix));
		nb_start_print = (int)((mlx->par->reso[1] - spri[i]->nb_pix) / 2.0);
		x = nb_start_print;
		while (x < nb_start_print + (int)(spri[i]->nb_pix))
		{
			color = sprite_color(mlx, spri[i], x - nb_start_print, spri[i]->type);
			if (color == spri[i]->inv_color)
				x++;
			else
				mlx->addr.screen[screen_row + x++ * mlx->info.screen[SIZE_LINE]] = color;
		}
		i++;
	}
}
