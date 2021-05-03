/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_guard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:25:00 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:11:47 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	initialize_guard_sprite(t_sprites *spri, int line, int row)
{
	spri->guard.line_img = line;
	spri->guard.row_img = row;
}

void	guard_anim_alive(t_event *player, t_sprites *spri)
{
	double			time;
	int				time_tmp;
	struct timeval	end;

	if (spri->guard.status >= DYING)
		return ;
	gettimeofday(&end, NULL);
	time = 0.0;
	spri->guard.status == DETECTING_PLAYER ? time = (double)(end.tv_usec - spri->guard.time_detect.tv_usec)
			/ 1000000.0 + (double)(end.tv_sec - spri->guard.time_detect.tv_sec) : 0;
	time_tmp = (int)(time * 100.0);
	if (!spri->guard.status || time_tmp < 50)
		initialize_guard_sprite(spri, G_BASIC_L, G_BASIC_R);
	else if (time_tmp < 100)
		initialize_guard_sprite(spri, G_DETECT_L, G_DETECT_R);
	else if (time_tmp % 180 < 165)
	{
		spri->guard.shooting = 0;
		initialize_guard_sprite(spri, G_SHOOT_L, G_SHOOT1_R);
	}
	else
	{
		!spri->guard.shooting ? player->lifebar -= 10 * player->level : 0;
		player->lifebar < 0 ? player->lifebar = 0 : 0;
		gettimeofday(&player->time_player_death, NULL);
		spri->guard.shooting = 1;
		initialize_guard_sprite(spri, G_SHOOT_L, G_SHOOT2_R);
	}
}

void	guard_anim_dead(t_sprites *spri)
{
	double			time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	time = 0.0;
	if (spri->guard.status == DEAD)
	{
		initialize_guard_sprite(spri, G_DEAD_L, G_DEAD5_R);
		return ;
	}
	time = (double)(end.tv_usec - spri->guard.time_death.tv_usec)
			/ 1000000.0 + (double)(end.tv_sec - spri->guard.time_death.tv_sec);
	if (time < 0.1)
		initialize_guard_sprite(spri, G_DEAD_L, G_DEAD1_R);
	else if (time < 0.2)
		initialize_guard_sprite(spri, G_DEAD_L, G_DEAD2_R);
	else if (time < 0.3)
		initialize_guard_sprite(spri, G_DEAD_L, G_DEAD3_R);
	else if (time < 0.4)
		initialize_guard_sprite(spri, G_DEAD_L, G_DEAD4_R);
	else
		spri->guard.status = DEAD;
}

void	guards_animation(t_mlx *mlx, t_rcast *cam, t_sprites **spri)
{
	int		i;

	if (!spri)
		return ;
	i = -1;
	while (spri[++i])
		if (spri[i]->type == SP_GUARD)
			check_guard_detect_player(mlx, cam, spri[i]);
	i = -1;
	while (spri[++i])
	{
		if (spri[i]->type == SP_GUARD && spri[i]->guard.status <= DETECTING_PLAYER)
			guard_anim_alive(&mlx->eve, spri[i]);
		if (spri[i]->type == SP_GUARD && spri[i]->guard.status >= DYING)
			guard_anim_dead(spri[i]);
	}
}
