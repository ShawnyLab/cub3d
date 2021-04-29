/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:26:38 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 16:33:04 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_init_guard(t_sprites *new)
{
	new->guard.line_img = G_BASIC_L;
	new->guard.row_img = G_BASIC_R;
	new->guard.status = 0;
	new->guard.shooting = 0;
}

void	ft_add_spr_two(t_mlx *mlx, t_sprites *new)
{
	int			i;
	t_sprites	**tmp;

	i = 0;
	if (!mlx->spri)
	{
		if (!(mlx->spri = malloc(sizeof(*tmp) * 2)))
			ft_err_img("Malloc failed\n", mlx);
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
			ft_free_spr(mlx->spri);
			ft_err_img("Malloc failed\n", mlx);
		}
		mlx->spri[i] = new;
		mlx->spri[i + 1] = NULL;
		while (--i >= 0)
			mlx->spri[i] = tmp[i];
		free(tmp);
	}
}