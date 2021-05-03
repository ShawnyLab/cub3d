/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 19:38:11 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:25:49 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		drawing(t_pars *par, int save)
{
	t_mlx	mlx;
	t_rcast	cam;
	
	mlx.par = par;
	mlx.cam = &cam;
	struct_init_mlx(&mlx);
	struct_init_camera(&mlx, &cam, par);
	raycasting(&mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.screen, 0, 0);
	if (save)
		save_image_as_bmp(&mlx);
	mlx.eve.level = 0;
	draw_level_menu(&mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.screen, 0, 0);
	mlx_hook(mlx.win, MOTIONNOTIFY, 0, &motion_notify, &mlx);
	mlx_hook(mlx.win, KEYPRESS, 0, &key_press, &mlx);
	mlx_hook(mlx.win, KEYRELEASE, 0, &key_release, &mlx);
	mlx_hook(mlx.win, DESTROYNOTIFY, 0, &destroy_notify, &mlx);
	mlx_loop_hook(mlx.ptr, &no_event, &mlx);
	mlx_loop(mlx.ptr);
	return (1);
}