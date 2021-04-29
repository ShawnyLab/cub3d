/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:57:58 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:19:31 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_texture_resize(t_mlx *mlx, t_texture *textu, double *pix_wall)
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

void	ft_draw_swf(t_mlx *mlx, t_texture *textu, int i, unsigned int pix_wall)
{
	unsigned int	x;
	unsigned int	pix_sf;
	x = 0;
	pix_sf = (unsigned int)((mlx->par->reso[1] - pix_wall) / 2.0);
	pix_wall += pix_sf;
	while (x < pix_sf)
	{

			
	}
}

void	ft_raycast(t_mlx *mlx)
{
	int			i;
	double		pix_wall;
	t_texture	textu;

	i = -1;
	mlx->textu = &textu;
	ft_spr_ori(mlx->spri, mlx->cam->angle);
	while (++i < (int)mlx->par->reso[0])
	{
		ft_reset_ray_spr(mlx->spri);
		pix_wall = ft_pix_wall(mlx, mlx->cam, &textu,
			ft_pos_angle(mlx->cam->angle + (FOV / 2.0) - mlx->cam->freq_ray * (double)i));
		ft_texture_resize(mlx, &textu, &pix_wall);
		
	}
}

int		ft_draw(t_pars *par, int save)
{
	t_mlx	mlx;
	t_rcast	cam;

	mlx.par = par;
	mlx.cam = &cam;
	ft_struct_init(&mlx);
	ft_init_cam(&mlx, &cam, par);
	
}