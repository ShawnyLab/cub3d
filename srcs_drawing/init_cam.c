/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:59:44 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 17:08:47 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_init_player_pos(t_mlx *mlx, t_rcast *cam)
{
	int		line;
	int		row;

	line = 0;
	while (cam->map[line])
	{
		row = 0;
		while (cam->map[line][row] != -2)
		{
			if (cam->map[line][row] >= 10)
			{
				cam->x = (double)row + 0.5;
				cam->y = (double)line + 0.5;
				cam->map[line][row] == EAST ? cam->angle = V_EAST : 0;
				cam->map[line][row] == NORTH ? cam->angle = V_NORTH : 0;
				cam->map[line][row] == WEST ? cam->angle = V_WEST : 0;
				cam->map[line][row] == SOUTH ? cam->angle = V_SOUTH : 0;
				cam->map[line][row] = 0;
			}
			else if (cam->map[line][row] > 3)
				ft_add_spr(mlx, cam, line, row);
			row++;
		}
		cam->nb_rows[line] = row;
		line++;
	}
}

void	ft_init_cam_two(t_rcast *cam)
{
	cam->m_up = 0;
	cam->m_down = 0;
	cam->m_left = 0;
	cam->m_right = 0;
	cam->r_left = 0;
	cam->r_right = 0;
	cam->rm_left = 0;
	cam->rm_right = 0;
	cam->mouse_bool = 0;
	cam->mouse_x = 0;	
}

void	ft_init_cam(t_mlx *mlx, t_rcast *cam, t_pars *par)
{
	int		line;

	line = 0;
	ft_init_cam_two(cam);
	while (par->map[line])
		line++;
	cam->nb_lines = line;
	if (!(cam->nb_rows = malloc(line * sizeof(int))))
		ft_err_img("Malloc failed\n", mlx);
	cam->map = par->map;
	ft_init_player_pos(mlx, cam);
	cam->dist_screen = (par->reso[0] / 2.0) / tan(((double)FOV / 2.0) * (TO_RAD));
	cam->freq_ray = (double)FOV / par->reso[0];
	cam->par = par;
	mlx->eve.start_angle = cam->angle;
	mlx->eve.start_pos_x = cam->x;
	mlx->eve.start_pos_y = cam->y;
}