/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:45:22 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 14:54:47 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	reset_player_pos(t_rcast *cam, t_point previous_pos)
{
	cam->x = previous_pos.x;
	cam->y = previous_pos.y;
}

void	move_accords_framerate(t_mlx *mlx, double move)
{
	double			time;
	struct timeval	end;
	t_point			player_pos;
	
	player_pos.x = mlx->cam->x;
	player_pos.y = mlx->cam->y;
	gettimeofday(&end, NULL);
	time = (double)(end.tv_usec - mlx->start_move.tv_usec) / 1000000.0 +
         (double)(end.tv_sec - mlx->start_move.tv_sec);
	if (mlx->start_move.tv_sec != 0.0)
		move *= time / TIME_MOVE;
	mlx->cam->m_up ? move_up_in_map(mlx, move) : 0;
	if (sprite_collision(mlx, mlx->cam, player_pos.x, player_pos.y))
		reset_player_pos(mlx->cam, player_pos);
	mlx->cam->m_down ? move_down_in_map(mlx, move) : 0;
	if (sprite_collision(mlx, mlx->cam, player_pos.x, player_pos.y))
		reset_player_pos(mlx->cam, player_pos);
	mlx->cam->m_left ? move_left_in_map(mlx, move) : 0;
	if (sprite_collision(mlx, mlx->cam, player_pos.x, player_pos.y))
		reset_player_pos(mlx->cam, player_pos);
	mlx->cam->m_right ? move_right_in_map(mlx, move) : 0;
	if (sprite_collision(mlx, mlx->cam, player_pos.x, player_pos.y))
		reset_player_pos(mlx->cam, player_pos);
	gettimeofday(&mlx->start_move, NULL);
}

void	rota_accords_framerate(t_mlx *mlx, double rota)
{
	double			time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	time = (double)(end.tv_usec - mlx->start_rota.tv_usec) / 1000000.0 +
         (double)(end.tv_sec - mlx->start_rota.tv_sec);
	if (mlx->start_rota.tv_sec != 0.0)
		rota *= time / TIME_MOVE;
	mlx->cam->r_left ? mlx->cam->angle = positive_angle(mlx->cam->angle + rota) : 0;
	mlx->cam->r_right ? mlx->cam->angle = positive_angle(mlx->cam->angle - rota) : 0;
	gettimeofday(&mlx->start_rota, NULL);
}
