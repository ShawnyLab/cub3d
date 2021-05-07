/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:26:51 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 11:26:52 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		ft_prepare_sprite_line(t_item *item, t_adata *a,
		int col_id)
{
	double		line_height;

	line_height = item->sprite_h;
	a->line_sp.start_x = col_id;
	a->line_sp.start_y = (a->win.win_h / 2) - (line_height * 11 / 40);
	if (a->line_sp.start_y < 0)
		a->line_sp.start_y = 0;
	a->line_sp.end_x = col_id;
	a->line_sp.end_y = (a->win.win_h / 2) + (line_height * 29 / 40);
	if (a->line_sp.end_y >= a->win.win_h)
		a->line_sp.end_y = a->win.win_h - 1.0;
	a->line_sp.deltax = a->line_sp.end_x - a->line_sp.start_x;
	a->line_sp.deltay = a->line_sp.end_y - a->line_sp.start_y;
	a->line_sp.pixels = sqrt(pow(a->line_sp.deltax, 2)
	+ pow(a->line_sp.deltay, 2));
	a->line_sp.deltax /= a->line_sp.pixels;
	a->line_sp.deltay /= a->line_sp.pixels;
	return (0);
}

int		ft_prepare_3d_line(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	double		line_height;
	double		nofish_dist;

	nofish_dist = (ray->distance / a->map.tile_size) *
	cos(ray_angle - a->joe.rotangle);
	line_height = a->ray.distprojplane / nofish_dist;
	a->line_3d.start_x = col_id;
	a->line_3d.start_y = (a->win.win_h / 2) - (line_height / 2);
	if (a->line_3d.start_y < 0)
		a->line_3d.start_y = 0;
	a->line_3d.end_x = col_id;
	a->line_3d.end_y = (a->win.win_h / 2) + (line_height / 2);
	if (a->line_3d.end_y >= a->win.win_h)
		a->line_3d.end_y = a->win.win_h - 1.0;
	a->line_3d.deltax = a->line_3d.end_x - a->line_3d.start_x;
	a->line_3d.deltay = a->line_3d.end_y - a->line_3d.start_y;
	a->line_3d.pixels = sqrt(pow(a->line_3d.deltax, 2) +
	pow(a->line_3d.deltay, 2));
	a->line_3d.deltax /= a->line_3d.pixels;
	a->line_3d.deltay /= a->line_3d.pixels;
	find_text_wallhit(ray_angle, ray, a);
	return (0);
}

int		ft_initline(t_adata *a)
{
	a->line.start_x = a->joe.x;
	a->line.start_y = a->joe.y;
	a->line.end_x = a->joe.x + (cos(a->joe.rotangle) * a->map.tile_size);
	a->line.end_y = a->joe.y + (sin(a->joe.rotangle) * a->map.tile_size);
	a->line.deltax = a->line.end_x - a->line.start_x;
	a->line.deltay = a->line.end_y - a->line.start_y;
	a->line.pixels = sqrt(pow(a->line.deltax, 2) + pow(a->line.deltay, 2));
	a->line.deltax /= a->line.pixels;
	a->line.deltay /= a->line.pixels;
	a->line.color = 0xb87cb3;
	return (0);
}
