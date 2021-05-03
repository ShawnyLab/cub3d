/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:57:58 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:23:41 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		tex_color(t_mlx *mlx, int x, int pix_row, int pix_line)
{
	int		color;

	if (mlx->textu->side_wall == NORTH)
		color = mlx->addr.t_no[mlx->textu->row_img + pix_row + mlx->textu->start_line_img * mlx->info.t_no[SIZE_LINE]
				+ x * mlx->info.t_no[SIZE_LINE] + pix_line * mlx->info.t_no[SIZE_LINE]];
	if (mlx->textu->side_wall == SOUTH)
		color = mlx->addr.t_so[mlx->textu->row_img + pix_row + mlx->textu->start_line_img * mlx->info.t_so[SIZE_LINE]
				+ x * mlx->info.t_so[SIZE_LINE] + pix_line * mlx->info.t_no[SIZE_LINE]];
	if (mlx->textu->side_wall == EAST)
		color = mlx->addr.t_ea[mlx->textu->row_img + pix_row + mlx->textu->start_line_img * mlx->info.t_ea[SIZE_LINE]
				+ x * mlx->info.t_ea[SIZE_LINE] + pix_line * mlx->info.t_no[SIZE_LINE]];
	if (mlx->textu->side_wall == WEST)
		color = mlx->addr.t_we[mlx->textu->row_img + pix_row + mlx->textu->start_line_img * mlx->info.t_we[SIZE_LINE]
				+ x * mlx->info.t_we[SIZE_LINE] + pix_line * mlx->info.t_no[SIZE_LINE]];
	return (color);
}

int		draw_texture(t_mlx *mlx, t_texture *textu, int x)
{
	int		color;
	int		side;
	int		lev;

	side = textu->side_wall;
	lev = mlx->eve.level;
	x = (int)((double)x * mlx->textu->freq_pixel);
	x >= mlx->info.t_no[WIDTH] ? x = mlx->info.t_no[WIDTH] - 1 : 0;
	side == NORTH && lev == 1 ? color = tex_color(mlx, x, T1_NORTH_R, T1_NORTH_L) : 0;
	side == NORTH && lev == 2 ? color = tex_color(mlx, x, T2_NORTH_R, T2_NORTH_L) : 0;
	side == NORTH && lev == 3 ? color = tex_color(mlx, x, T3_NORTH_R, T3_NORTH_L) : 0;
	side == SOUTH && lev == 1 ? color = tex_color(mlx, x, T1_SOUTH_R, T1_SOUTH_L) : 0;
	side == SOUTH && lev == 2 ? color = tex_color(mlx, x, T2_SOUTH_R, T2_SOUTH_L) : 0;
	side == SOUTH && lev == 3 ? color = tex_color(mlx, x, T3_SOUTH_R, T3_SOUTH_L) : 0;
	side == EAST && lev == 1 ? color = tex_color(mlx, x, T1_EAST_R, T1_EAST_L) : 0;
	side == EAST && lev == 2 ? color = tex_color(mlx, x, T2_EAST_R, T2_EAST_L) : 0;
	side == EAST && lev == 3 ? color = tex_color(mlx, x, T3_EAST_R, T3_EAST_L) : 0;
	side == WEST && lev == 1 ? color = tex_color(mlx, x, T1_WEST_R, T1_WEST_L) : 0;
	side == WEST && lev == 2 ? color = tex_color(mlx, x, T2_WEST_R, T2_WEST_L) : 0;
	side == WEST && lev == 3 ? color = tex_color(mlx, x, T3_WEST_R, T3_WEST_L) : 0;
	if (side == DOOR)
		color = mlx->addr.t_do[textu->row_img + textu->start_line_img * mlx->info.t_do[SIZE_LINE]
					+ x * mlx->info.t_do[SIZE_LINE]];
	return (color);
}

void	texture_resizing(t_mlx *mlx, t_texture *textu, double *pix_wall)
{
	int		pix_wall2;

	textu->no_limit_pix_wall = (int)*pix_wall;
	*pix_wall > mlx->par->reso[1] ? *pix_wall = mlx->par->reso[1] : 0;
	pix_wall2 = (int)*pix_wall;
	if (pix_wall2 >= textu->no_limit_pix_wall)
	{
		textu->start_line_img = 0;
		textu->freq_pixel = (double)WALL_SIZE / (double)pix_wall2;
	}
	else
	{
		textu->start_line_img = (WALL_SIZE - (int)((double)WALL_SIZE *
					(double)pix_wall2 / (double)textu->no_limit_pix_wall)) / 2;
		textu->freq_pixel = (double)(WALL_SIZE - 2 * textu->start_line_img) / (double)pix_wall2;
	}
}

void	drawing_sky_wall_floor(t_mlx *mlx, t_texture *textu, int i, unsigned int pix_wall)
{
	unsigned int	x;
	unsigned int	pix_sky_floor;

	x = 0;
	pix_sky_floor = (unsigned int)((mlx->par->reso[1] - pix_wall) / 2.0);
	pix_wall += pix_sky_floor;
	while (x < pix_sky_floor)
	{
		if (mlx->eve.print_texture)
			mlx->addr.screen[i + x * mlx->info.screen[SIZE_LINE]] = 
				draw_skybox(mlx, mlx->par->reso[1] - (double)x, 
				positive_angle(mlx->cam->angle + (FOV / 2.0) - mlx->cam->freq_ray * (double)i));
		else
			mlx->addr.screen[i + x * mlx->info.screen[SIZE_LINE]] = mlx->par->sky_rgb;
		x++;
	}
	while (x < pix_wall)
	{
		mlx->addr.screen[i + x * mlx->info.screen[SIZE_LINE]] = draw_texture(mlx, textu, x - pix_sky_floor);
		x++;
	}
	while (x < (unsigned int)mlx->par->reso[1])
	{
		if (mlx->eve.print_texture)
			mlx->addr.screen[i + x * mlx->info.screen[SIZE_LINE]] = 
				floor_raycasting(mlx, (double)x - mlx->par->reso[1] / 2.0, 
				positive_angle(mlx->cam->angle + (FOV / 2.0) - mlx->cam->freq_ray * (double)i));
		else
			mlx->addr.screen[i + x * mlx->info.screen[SIZE_LINE]] = mlx->par->flo_rgb;
		x++;
	}
}

void	raycasting(t_mlx *mlx)
{
	int			i;
	double		pix_wall;
	t_texture	textu;

	i = -1;
	mlx->textu = &textu;
	calc_sprites_orientation(mlx->spri, mlx->cam->angle);
	while (++i < (int)mlx->par->reso[0])
	{
		reset_ray_len_sprites(mlx->spri);
		pix_wall = nb_pixel_wall(mlx, mlx->cam, &textu,
				positive_angle(mlx->cam->angle + (FOV / 2.0) - mlx->cam->freq_ray * (double)i));
		texture_resizing(mlx, &textu, &pix_wall);
		drawing_sky_wall_floor(mlx, &textu, i, (unsigned int)pix_wall);
		draw_sprites(mlx, mlx->spri, i);
	}
}