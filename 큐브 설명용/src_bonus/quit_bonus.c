/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:03:02 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 12:03:03 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	quit_cub(t_cub *cub, int exit_code, char *error_message)
{
	int	i;

	free(cub->rays);
	free(cub->sprites);
	ft_free_int_matrix(cub->map.grid, cub->map.height);
	i = 0;
	while (i < TEXTURES)
	{
		free(cub->map.paths[i]);
		if (cub->texture[i].image.img)
			mlx_destroy_image(cub->mlx, cub->texture[i].image.img);
		i++;
	}
	if (cub->mlx && cub->image.img)
		mlx_destroy_image(cub->mlx, cub->image.img);
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	free(cub->mlx);
	ft_bzero(cub, sizeof(t_cub));
	if (exit_code == EXIT_FAILURE)
		ft_putendl_fd(error_message, 2);
	exit(exit_code);
}
