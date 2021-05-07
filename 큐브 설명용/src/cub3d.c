/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:25 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 13:18:06 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render(t_cub *cub)
{
	project_walls(cub);
	draw_sprites(cub);
}

int		update(t_cub *cub)
{
	move_player(&cub->map.player, cub);
	cast_rays(cub);
	render(cub);
	mlx_put_image_to_window(cub->mlx, cub->win,
			cub->image.img, 0, 0);
	mlx_do_sync(cub->mlx);
	return (0);
}

void	update_savebmp(t_cub *cub)
{
	cast_rays(cub);
	project_walls(cub);
	draw_sprites(cub);
	save_bitmap(cub);
	quit_cub(cub, EXIT_SUCCESS, "");
}

int		main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(cub));
	if (check_args(argc, argv, &cub))
		return (EXIT_FAILURE);
	parse_cub(argv[1], &cub);
	initialize(&cub);
	if (!cub.savebmp)
		set_hooks(&cub);
	else
		update_savebmp(&cub);
	mlx_loop_hook(cub.mlx, update, &cub);
	mlx_loop(cub.mlx);
	return (EXIT_SUCCESS);
}
