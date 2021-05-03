/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:26:38 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:34:01 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_sprite_guard(t_sprites *new)
{
	new->guard.line_img = G_BASIC_L;
	new->guard.row_img = G_BASIC_R;
	new->guard.status = 0;
	new->guard.shooting = 0;
}

void	add_sprite_info(t_mlx *mlx, t_rcast *cam, int line, int row)
{
	t_sprites	*new;

	if (!(new = malloc(sizeof(*new))))
	{
		free_sprite_struct(mlx->spri);
		error_msg_destroy_img("Malloc failed\n", mlx);
	}
	new->type = cam->map[line][row];
	new->size = sprite_size(new->type);
	new->addr_img = add_sprite_img_addr(mlx, new->type);
	new->inv_color = sprites_background_color(new->type);
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
		init_sprite_guard(new);
	add_sprite_struct(mlx, new);
}
