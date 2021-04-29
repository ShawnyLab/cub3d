/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:07:22 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 16:35:08 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_spr_color(int type)
{
	int		inv_color;

	inv_color = 0;
	inv_color = 0;
	type == SP_GUARD ? inv_color = INV_COLOR : 0;
	type == SP_TREE ? inv_color = INV_COLOR : 0;
	type == SP_ARMOR ? inv_color = INV_COLOR : 0;
	type == SP_HEALTH ? inv_color = INV_COLOR : 0;
	type == SP_AMMO ? inv_color = INV_COLOR : 0;
	type == SP_FLAG ? inv_color = INV_COLOR : 0;
	return (inv_color);
}

int		*ft_spr_img_addr(t_mlx *mlx, int type)
{
	int	*spr_addr;

	spr_addr = NULL;
	type == SP_GUARD ? spr_addr = mlx->addr.s_4 : 0;
	type == SP_TREE ? spr_addr = mlx->addr.s_5 : 0;
	type == SP_ARMOR ? spr_addr = mlx->addr.s_6 : 0;
	type == SP_HEALTH ? spr_addr = mlx->addr.s_7 : 0;
	type == SP_AMMO ? spr_addr = mlx->addr.s_8 : 0;
	type == SP_FLAG ? spr_addr = mlx->addr.s_9 : 0;
	return (spr_addr);
}

int		ft_spr_size(int type)
{
	int		size;

	size = 0;
	type = SP_GUARD ? size = GUARD_SIZE : 0;
	type == SP_TREE ? size = TREE_SIZE : 0;
	type == SP_ARMOR ? size = ARMOR_SIZE : 0;
	type == SP_HEALTH ? size = HEALTH_SIZE : 0;
	type == SP_AMMO ? size = AMMO_SIZE : 0;
	type == SP_FLAG ? size = FLAG_SIZE : 0;
	return (size);
}

void	ft_free_spr(t_sprites **spr)
{
	int     i;

	i = 0;
	while (spr && spr[i])
		free(spr[i++]);
	free(spr);
}

void	ft_add_spr(t_mlx *mlx, t_rcast *cam, int line, int row)
{
	t_sprites   *new;

	if (!(new = malloc(sizeof(*new))))
	{
		ft_free_spr(mlx->spri);
		ft_err_img("Malloc failed\n", mlx);
	}
	new->type = cam->map[line][row];
	new->size = ft_spr_size(new->type);
	new->addr_img = ft_spr_img_addr(mlx, new->type);
	new->inv_color = ft_spr_color(new->type);
	new->x = (double)row + 0.5;
	new->y = (double)line + 0.5;
	new->ray_len = -1.0;
	new->start_line_img = -1;
	new->freq_pixel = -1.0;
	new->nb_pix = -1.0;
	new->row_percent = -1.0;
	new->a.x = -1.0;
	new->a.y = -1.0;
	new->b.x = -1.0;
	new->b.y = -1.0;
	if (new->type == SP_GUARD)
		ft_init_guard(new);
	ft_add_spr_two(mlx, new);
}