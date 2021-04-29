/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:38:00 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:15:17 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CUBE3D_H
# define	CUBE3D_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<math.h>
# include	<float.h>
# include	<time.h>
# include	<sys/time.h>

# include	"libftprintf.h"
# include	"mlx.h"
# include	"mlx_macro.h"
# include	"define.h"
# include	"structures.h"

int					ft_check_arg(int argc, char **argv);
int					ft_str_error(char *str, t_pars *par, char *line);
void				ft_free_all(t_pars *par);
void				ft_struct_init(t_pars *par);
int					ft_maperror(char *str, t_pars *par, int *line);


int					ft_keytype(char *line, t_pars *par);
int 				ft_map_line(t_pars *par, char *line);
int					ft_cnt_keymiss(t_pars *par);
void				ft_check_key(t_pars *par);

void				ft_check_sp(t_pars *par, char *line, int key);
int					ft_parse(t_pars *par);
int					ft_parse_func(t_pars *par, char *line, int key);

int					ft_reso(t_pars *par, char *line);
int					ft_check_rgb(char *line);
int					ft_parse_rgb(t_pars *par, char *line);
int					ft_parse_path(t_pars *par, char **path, char *line);
int					ft_parse_sky_rgb(t_pars *par, char *line);

int					ft_parse_map(t_pars *par, char *line);
int		            *ft_convert_int(char *line);
int					**ft_add_map(t_pars *par, int *line);

int					ft_check_map(t_pars *par);
int					ft_player_pos(int *line_map);
int					ft_check_blocked(t_pars *par, int *line);
void				ft_check_wall(t_pars *par, int *now, int *bef);
void				ft_check_end(t_pars *par, int *line);


int					ft_len_map(int *line);
void				ft_check_bef(t_pars *par, int i, int *bef);
void				ft_check_now(t_pars *par, int i, int *now, int *bef);
void				ft_now_spaces(t_pars *par, int i, int *now, int *bef);
void				ft_bef_spaces(t_pars *par, int i, int *now, int *bef);

void				ft_check_door(t_pars *par, int *next, int *now, int *bef);

void				ft_init_cam(t_mlx *mlx, t_rcast *cam, t_pars *par);
void				ft_init_cam_two(t_rcast *cam);

void				ft_free_spr(t_sprites **spr);
void				ft_add_spr(t_mlx *mlx, t_rcast *cam, int line, int row);
int					ft_spr_size(int type);
int					*ft_spr_img_addr(t_mlx *mlx, int type);
int					ft_spr_color(int type);


void				ft_err_img(const char *str, t_mlx *mlx);
void				ft_remove_img(t_mlx *mlx, t_img *img);

void				ft_init_guard(t_sprites *new);
void				ft_add_spr_two(t_mlx *mlx, t_sprites *new);

void				ft_spr_ori(t_sprites **spri, double angle);
void				ft_calc_coor(double angle, t_sprites *spri, char c);
void				ft_reset_ray_spr(t_sprites **spri);
void				ft_find_sprite(t_mlx *mlx, t_sprites *spri, double xd, double yd, double angle);
t_sprites			*ft_xray_spr_ptr(t_mlx *mlx, double angle, double x1, double y1);

void				ft_texture_resize(t_mlx *mlx, t_texture *textu, double *pix_wall);
void				ft_raycast(t_mlx *mlx);
int					ft_draw(t_pars *par, int save);


double				ft_angle_rect(double angle);
double				ft_pos_angle(double angle);
double				ft_pix_wall(t_mlx *mlx, t_rcast *cam, t_texture *textu, double angle);
double				ft_seg_len(double xa, double ya, double xb, double yb);
void				ft_spr_beh_wall(t_sprites **spri, double ray_len);



double				ft_xray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu);
double				ft_xray_y1(t_rcast *cam, double angle);
double				ft_xray_ya(double angle);
double				ft_xray_x1(double angle, double y1);
double				ft_xray_xa(double angle, double y1, double ya);

int					ft_xray_wall(t_mlx *mlx, double angle, double x_len, double y_len);

double				ft_yray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu);
double				ft_yray_xa(double angle);
double				ft_yray_y1(double angle, double x1);
double				ft_yray_ya(double angle, double x1, double xa);
double				ft_yray_x1(t_rcast *cam, double angle);

int					ft_yray_wall(t_mlx *mlx, double angle, double x_len, double y_len);

t_sprites			*ft_yray_spr_ptr(t_mlx *mlx, double angle, double x1, double y1);

int					ft_img_row(t_rcast *cam, t_texture *textu, double xa, double ya);
double				ft_obj_height(t_rcast *cam, double ray_len);

















#endif