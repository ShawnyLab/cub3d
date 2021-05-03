/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:07:22 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:33:33 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_sprite_struct(t_sprites **spri)
{
	int		i;

	i = 0;
	while (spri && spri[i])
		free(spri[i++]);
	free(spri);
}

void	add_sprite_struct(t_mlx *mlx, t_sprites *new)
{
	int			i;
	t_sprites	**tmp;
	
	i = 0;
	if (!mlx->spri)
	{
		if (!(mlx->spri = malloc(sizeof(*tmp) * 2)))
			error_msg_destroy_img("Malloc failed\n", mlx);
		mlx->spri[0] = new;
		mlx->spri[1] = NULL;
	}
	else
	{
		tmp = mlx->spri;
		while (mlx->spri[i])
			i++;
		if (!(mlx->spri = malloc(sizeof(*tmp) * (i + 2))))
		{
			free_sprite_struct(mlx->spri);
			error_msg_destroy_img("Malloc failed\n", mlx);
		}
		mlx->spri[i] = new;
		mlx->spri[i + 1] = NULL;
		while (--i >= 0)
			mlx->spri[i] = tmp[i];
		free(tmp);
	}
}

int		sprites_background_color(int type)
{
	int		inv_color;

	inv_color = 0;
	type == SP_GUARD ? inv_color = INV_COLOR : 0;
	type == SP_TREE ? inv_color = INV_COLOR : 0;
	type == SP_ARMOR ? inv_color = INV_COLOR : 0;
	type == SP_HEALTH ? inv_color = INV_COLOR : 0;
	type == SP_AMMO ? inv_color = INV_COLOR : 0;
	type == SP_FLAG ? inv_color = INV_COLOR : 0;
	return (inv_color);
}

int		*add_sprite_img_addr(t_mlx *mlx, int type)
{
	int		*addr_sprite;

	addr_sprite = NULL;
	type == SP_GUARD ? addr_sprite = mlx->addr.s_4 : 0;
	type == SP_TREE ? addr_sprite = mlx->addr.s_5 : 0;
	type == SP_ARMOR ? addr_sprite = mlx->addr.s_6 : 0;
	type == SP_HEALTH ? addr_sprite = mlx->addr.s_7 : 0;
	type == SP_AMMO ? addr_sprite = mlx->addr.s_8 : 0;
	type == SP_FLAG ? addr_sprite = mlx->addr.s_9 : 0;
	return (addr_sprite);
}

int		sprite_size(int type)
{
	int		size;

	size = 0;
	type == SP_GUARD ? size = GUARD_SIZE : 0;
	type == SP_TREE ? size = TREE_SIZE : 0;
	type == SP_ARMOR ? size = ARMOR_SIZE : 0;
	type == SP_HEALTH ? size = HEALTH_SIZE : 0;
	type == SP_AMMO ? size = AMMO_SIZE : 0;
	type == SP_FLAG ? size = FLAG_SIZE : 0;
	return (size);
}
