/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:48:55 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:47:44 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		motion_notify(int x, int y, t_mlx *mlx)
{
	unsigned int	x_tmp;

	(void)y;
	if (mlx->cam->mouse_bool == 1)
	{
		mlx->cam->mouse_bool = 2;
		mlx->cam->mouse_x = x;
	}
	if (mlx->cam->mouse_bool) 
	{
		x_tmp = abs(x - mlx->cam->mouse_x);
		if (x_tmp > 9)
			x_tmp = (int)sqrt((double)x_tmp) * 3;
		if (x < mlx->cam->mouse_x)
			mlx->cam->rm_left = M_ROTA_SIZE * x_tmp;
		else if (x > mlx->cam->mouse_x)
			mlx->cam->rm_right = M_ROTA_SIZE * x_tmp;
		mlx->cam->mouse_x = x;
	}
	return (1);
}

int		key_press(int keycode, t_mlx *mlx)
{
	if ((keycode == K1_KEY || keycode == K2_KEY || keycode == K3_KEY) && !mlx->eve.level)
		mlx->eve.level = keycode - (K1_KEY - 1);
	if (keycode == W_KEY)
		mlx->cam->m_up = 1;
	else if (keycode == S_KEY)
		mlx->cam->m_down = 1;
	else if (keycode == A_KEY)
		mlx->cam->m_left = 1;
	else if (keycode == D_KEY)
		mlx->cam->m_right = 1;
	else if (keycode == LEFT_KEY)
		mlx->cam->r_left = 1;
	else if (keycode == RIGHT_KEY)
		mlx->cam->r_right = 1;
	else if (keycode == M_KEY)
		mlx->cam->mouse_bool = (mlx->cam->mouse_bool == 0) ? 1 : 0;
	else if (keycode == T_KEY)
		mlx->eve.print_texture = (mlx->eve.print_texture == 0) ? 1 : 0;
	else if (keycode == E_KEY)
		open_door(mlx);
	else if (keycode == SP_KEY)
		mlx->eve.player_is_shooting = 1;
	else if (keycode == ESC_KEY)
	{
		struct_free(mlx->par);
		free_sprite_struct(mlx->spri);
		destroy_all_images(mlx, &mlx->img);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		key_release(int keycode, t_mlx *mlx)
{
	if (keycode == W_KEY)
		mlx->cam->m_up = 0;
	else if (keycode == S_KEY)
		mlx->cam->m_down = 0;
	else if (keycode == A_KEY)
		mlx->cam->m_left = 0;
	else if (keycode == D_KEY)
		mlx->cam->m_right = 0;
	else if (keycode == LEFT_KEY)
		mlx->cam->r_left = 0;
	else if (keycode == RIGHT_KEY)
		mlx->cam->r_right = 0;
	else if (keycode == SP_KEY)
		mlx->eve.player_is_shooting = 0;
	return (1);
}

int		destroy_notify(t_mlx *mlx)
{
	struct_free(mlx->par);
	free_sprite_struct(mlx->spri);
	destroy_all_images(mlx, &mlx->img);
	exit(EXIT_SUCCESS);
}

int		no_event(t_mlx *mlx)
{
	if (!mlx->eve.level)
		return (1);
	if (mlx->eve.player_is_shooting && !mlx->eve.gun_shot && mlx->eve.ammo > 0)
		shoot_anim(mlx, mlx->cam);
	if (((mlx->cam->m_up || mlx->cam->m_down) && (mlx->cam->m_left || mlx->cam->m_right))
			&& (!(mlx->cam->m_up && mlx->cam->m_down) && !(mlx->cam->m_left && mlx->cam->m_right)))
		move_accords_framerate(mlx, MOVE_SIZE / 2.0);
	else if (mlx->cam->m_up || mlx->cam->m_down || mlx->cam->m_left || mlx->cam->m_right)
		move_accords_framerate(mlx, MOVE_SIZE);
	else
		mlx->start_move.tv_sec = 0.0;
	if (mlx->cam->r_left || mlx->cam->r_right)
		rota_accords_framerate(mlx, ROTA_SIZE);
	else
		mlx->start_rota.tv_sec = 0.0;
	mlx->cam->rm_left ? mlx->cam->angle = positive_angle(mlx->cam->angle + mlx->cam->rm_left) : 0;
	mlx->cam->rm_right ? mlx->cam->angle = positive_angle(mlx->cam->angle - mlx->cam->rm_right) : 0;
	mlx->eve.lifebar > 0 ? guards_animation(mlx, mlx->cam, mlx->spri) : 0;
	mlx->eve.lifebar > 0 ? raycasting(mlx) : 0;
	mlx->eve.lifebar > 0 ? draw_hud_and_gun_anims(mlx, mlx->par, &mlx->info) : 0;
	mlx->eve.lifebar <= 0 ? draw_death_screen(mlx) : 0;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.screen, 0, 0);
	mlx->cam->rm_left = 0.0;
	mlx->cam->rm_right = 0.0;
	return (1);
}
