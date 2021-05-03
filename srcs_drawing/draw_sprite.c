/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:40:15 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:20:31 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	swap_sprites(t_sprites **sprite1, t_sprites **sprite2)
{
	t_sprites	*tmp;

	tmp = *sprite1;
	*sprite1 = *sprite2;
	*sprite2 = tmp;
}

void	sort_sprites_tab(t_sprites **spri)
{
	int			i;
	int			j;

	i = 0;
	while (spri && spri[i] && spri[i + 1])
	{
		j = i;
		while (spri[++j])
			if (spri[i]->ray_len < spri[j]->ray_len)
				swap_sprites(&spri[i], &spri[j]);
		i++;
	}
}

void	sprite_resizing(t_mlx *mlx, t_sprites *spri, double *pix_spri)
{
	int		pix_spri2;
	int		no_limit_pix_spri;

	no_limit_pix_spri = (int)*pix_spri;
	*pix_spri > mlx->par->reso[1] ? *pix_spri = mlx->par->reso[1] : 0;
	pix_spri2 = (int)*pix_spri;
	if (pix_spri2 >= no_limit_pix_spri)
	{
		spri->start_line_img = 0;
		spri->freq_pixel = (double)WALL_SIZE / (double)pix_spri2;
	}
	else
	{
		spri->start_line_img = (WALL_SIZE - (int)((double)WALL_SIZE *
					(double)pix_spri2 / (double)no_limit_pix_spri)) / 2;
		spri->freq_pixel = (double)(WALL_SIZE - 2 * spri->start_line_img) / (double)pix_spri2;
	}
}

int		*sprite_addr(t_mlx *mlx, int type)
{
	int		*address;

	address = NULL;
	type == SP_GUARD ? address = mlx->addr.s_4 : 0;
	type == SP_TREE ? address = mlx->addr.s_5 : 0;
	type == SP_ARMOR ? address = mlx->addr.s_6 : 0;
	type == SP_HEALTH ? address = mlx->addr.s_7 : 0;
	type == SP_AMMO ? address = mlx->addr.s_8 : 0;
	type == SP_FLAG ? address = mlx->addr.s_9 : 0;
	return (address);
}

int		*sprite_info_addr(t_mlx *mlx, int **info, int type)
{
	type == SP_GUARD ? *info = mlx->info.s_4 : 0;
	type == SP_TREE ? *info = mlx->info.s_5 : 0;
	type == SP_ARMOR ? *info = mlx->info.s_6 : 0;
	type == SP_HEALTH ? *info = mlx->info.s_7 : 0;
	type == SP_AMMO ? *info = mlx->info.s_8 : 0;
	type == SP_FLAG ? *info = mlx->info.s_9 : 0;
	return (sprite_addr(mlx, type));
}
