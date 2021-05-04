/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:26:31 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 22:15:44 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cube3d.h"

typedef struct		s_pars
{
	int				fd;
	double			reso[2];
	char			*path_no;
	char			*path_so;
	char			*path_ea;
	char			*path_we;
	char			*path_sp;
	char			*path_b_fl;
	char			*path_b_sk;
	char			*path_b_do;
	char			*path_b_sd;
	int				flo_rgb;
	int				sky_rgb;
	int				**map;
}					t_pars;

typedef struct		s_guard
{
	int				status;
	int				row_img;
	int				line_img;
	int				shooting;
	struct timeval	time_detect;
	struct timeval	time_death;
}					t_guard;

typedef struct		s_texture
{
	double			x_xa;
	double			x_ya;
	double			y_xa;
	double			y_ya;
	double			angle_raycast;
	int				side_wall;
	int				doors_x;
	int				doors_y;
	int				no_limit_pix_wall;
	int				start_line_img;
	double			freq_pixel;
	int				row_img;
}					t_texture;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_sprites
{
	int				type;
	int				size;
	int				*addr_img;
	int				inv_color;
	double			x;
	double			y;
	double			ray_len;
	double			nb_pix;
	int				start_line_img;
	double			freq_pixel;
	double			row_percent;
	t_point			a;
	t_point			b;
	t_point			a_sized;
	t_point			b_sized;
	t_guard			guard;
}					t_sprites;

typedef struct		s_rcast
{
	double			angle;
	double			freq_ray;
	double			x;
	double			y;
	double			dist_screen;
	int				*nb_rows;
	int				nb_lines;
	int				m_up;
	int				m_down;
	int				m_left;
	int				m_right;
	int				r_left;
	int				r_right;
	double			rm_left;
	double			rm_right;
	int				mouse_bool;
	int				mouse_x;
	int				**map;
	t_pars			*par;
}					t_rcast;

typedef struct		s_event
{
	int				print_texture;
	int				ammo;
	int				player_is_shooting;
	int				gun_shot;
	struct timeval	gun_time_start;
	int				lifebar;
	int				level;
	int				nb_life;
	double			start_pos_x;
	double			start_pos_y;
	double			start_angle;
	struct timeval	time_player_death;
}					t_event;

typedef struct		s_img
{
	void			*screen;
	void			*t_no;
	void			*t_so;
	void			*t_ea;
	void			*t_we;
	void			*t_fl;
	void			*t_sk;
	void			*t_do;
	void			*s_4;
	void			*s_5;
	void			*s_6;
	void			*s_7;
	void			*s_8;
	void			*s_9;
	void			*hud;
	void			*life;
	void			*guns;
	void			*num;
	void			*font;
}					t_img;

typedef struct		s_addr
{
	int				*screen;
	int				*t_no;
	int				*t_so;
	int				*t_ea;
	int				*t_we;
	int				*t_fl;
	int				*t_sk;
	int				*t_do;
	int				*s_4;
	int				*s_5;
	int				*s_6;
	int				*s_7;
	int				*s_8;
	int				*s_9;
	int				*hud;
	int				*life;
	int				*guns;
	int				*num;
	int				*font;
}					t_addr;

typedef struct		s_info
{
	int				screen[5];
	int				t_no[5];
	int				t_so[5];
	int				t_ea[5];
	int				t_we[5];
	int				t_fl[5];
	int				t_sk[5];
	int				t_do[5];
	int				s_4[5];
	int				s_5[5];
	int				s_6[5];
	int				s_7[5];
	int				s_8[5];
	int				s_9[5];
	int				hud[5];
	int				life[5];
	int				guns[5];
	int				num[5];
	int				font[5];
}					t_info;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	struct timeval	start_move;
	struct timeval	start_rota;
	t_img			img;
	t_addr			addr;
	t_info			info;
	t_pars			*par;
	t_rcast			*cam;
	t_event			eve;
	t_texture		*textu;
	t_sprites		**spri;
}					t_mlx;

#endif
