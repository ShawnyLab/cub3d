/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:59:04 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 16:16:57 by jinspark         ###   ########.fr       */
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

int						font1_color(t_mlx *mlx, int row, int line, int c);
void					draw_letter_font1(t_mlx *mlx, double line_screen, double row_screen, char c);
void					draw_choose_your_level_message(t_mlx *mlx);
void					draw_easy_medium_hard_message(t_mlx *mlx);
int						draw_level_menu(t_mlx *mlx);

int						font2_color(t_mlx *mlx, int row, int line, int c);
void					draw_letter_font2(t_mlx *mlx, double line_screen, double row_screen, char c);
void					draw_gameover_message(t_mlx *mlx);
void					draw_you_are_dead_message(t_mlx *mlx);
void					draw_colored_screen(t_mlx *mlx, int nb_pixel, int color);

void					draw_death_screen(t_mlx *mlx);

void					initialize_guard_sprite(t_sprites *spri, int line, int row);
void					guard_anim_alive(t_event *player, t_sprites *spri);
void					guard_anim_dead(t_sprites *spri);
void					guards_animation(t_mlx *mlx, t_rcast *cam, t_sprites **spri);

void					draw_hud(t_mlx *mlx, t_pars *par, t_info *info);
int						lifebar_color(t_mlx *mlx, t_info *info, int row, int line);
void					draw_lifebar(t_mlx *mlx, t_pars *par, t_info *info);
int						gun_color(t_mlx *mlx, int num_sprite, int row, int line);
void					draw_gun(t_mlx *mlx, t_pars *par, t_info *info, int num_sprite);

int						number_color(t_mlx *mlx, int num, int row, int line);
void					draw_number(t_mlx *mlx, t_info *info, int num, double row_screen);
void					draw_all_hud_numbers(t_mlx *mlx, t_info *info);
int						heart_color(t_mlx *mlx, int row, int line);
void					draw_one_heart(t_mlx *mlx, t_pars *par, t_info *info, double row_screen);

void					draw_lives(t_mlx *mlx, t_pars *par, t_info *info);
void					draw_hud_and_gun_anims(t_mlx *mlx, t_pars *par, t_info *info);

void					swap_sprites(t_sprites **sprite1, t_sprites **sprite2);
void					sort_sprites_tab(t_sprites **spri);
void					sprite_resizing(t_mlx *mlx, t_sprites *spri, double *pix_spri);
int						*sprite_addr(t_mlx *mlx, int type);
int						*sprite_info_addr(t_mlx *mlx, int **info, int type);

int						sprite_color(t_mlx *mlx, t_sprites *spri, int x, int type);
void					draw_sprites(t_mlx *mlx, t_sprites **spri, int screen_row);

int						drawing(t_pars *par, int save);

int						tex_color(t_mlx *mlx, int x, int pix_row, int pix_line);
int						draw_texture(t_mlx *mlx, t_texture *textu, int x);
void					texture_resizing(t_mlx *mlx, t_texture *textu, double *pix_wall);
void					drawing_sky_wall_floor(t_mlx *mlx, t_texture *textu, int i, unsigned int pix_wall);
void					raycasting(t_mlx *mlx);

void					init_player_pos(t_mlx *mlx, t_rcast *cam);
void					struct_init_cam_bool(t_rcast *cam);
void					struct_init_camera(t_mlx *mlx, t_rcast *cam, t_pars *par);

void					load_sprites(t_mlx *mlx, char *path, char *name, int num_sprite);
void					struct_init_img(t_mlx *mlx, t_info *info);
void					struct_init_events_bool(t_event *eve);
void					struct_init_mlx(t_mlx *mlx);

void					destroy_all_images(t_mlx *mlx, t_img *img);
void					error_msg_destroy_img(const char *str, t_mlx *mlx);
void					init_addr_info(int **addr, void *img, int info[5]);
void					struct_init_addr_info(t_mlx *mlx, t_addr *addr, t_info *info);
void					struct_init_img_ptr_to_null(t_img *img);

void					init_sprite_guard(t_sprites *new);
void					add_sprite_info(t_mlx *mlx, t_rcast *cam, int line, int row);

void					free_sprite_struct(t_sprites **spri);
void					add_sprite_struct(t_mlx *mlx, t_sprites *new);
int						sprites_background_color(int type);
int						*add_sprite_img_addr(t_mlx *mlx, int type);
int						sprite_size(int type);

void					check_guard_detect_player(t_mlx *mlx, t_rcast *cam, t_sprites *spri);
double					find_angle(t_rcast *cam, t_sprites *spri);
int						x_ray_find_len_wall(t_mlx *mlx, double angle, double x_len, double y_len);
int						y_ray_find_len_wall(t_mlx *mlx, double angle, double x_len, double y_len);
double					x_ray_len_wall(t_mlx *mlx, t_rcast *cam, double angle);
double					y_ray_len_wall(t_mlx *mlx, t_rcast *cam, double angle);

int						motion_notify(int x, int y, t_mlx *mlx);
int						key_press(int keycode, t_mlx *mlx);
int						key_release(int keycode, t_mlx *mlx);
int						destroy_notify(t_mlx *mlx);
int						no_event(t_mlx *mlx);

void					reset_player_pos(t_rcast *cam, t_point previous_pos);
void					move_accords_framerate(t_mlx *mlx, double move);
void					rota_accords_framerate(t_mlx *mlx, double rota);

void					move(t_rcast *cam, double len, char coordinate);
void					move_up_in_map(t_mlx *mlx, double move_size);
void					move_down_in_map(t_mlx *mlx, double move_size);
void					move_left_in_map(t_mlx *mlx, double move_size);
void					move_right_in_map(t_mlx *mlx, double move_size);

int						shoot_angle(t_mlx *mlx, t_rcast *cam, double angle_shooting);
void					shoot_anim(t_mlx *mlx, t_rcast *cam);

void					add_len_to_ray(t_mlx *mlx, t_point *square, double size_len);
void					open_door(t_mlx *mlx);
int						set_ennemy_to_death_value(t_sprites *spri);
int						x_ray_shooting(t_mlx *mlx, t_rcast *cam, double angle, double ray_max_len);
int						y_ray_shooting(t_mlx *mlx, t_rcast *cam, double angle, double ray_max_len);

void					save_image_as_bmp(t_mlx *mlx);

void					fill_bmp_with_data_img(t_mlx *mlx, char *img_str, int i, int padding_byte);
int						fill_bmp_header_info(t_mlx *mlx, char *img_str, int i, int size_str_img);
void					put_4_octets_in_str_img(int *int_to_fill, int *i, int value);
void					put_3_octets_in_str_img(char *int_to_fill, int *i, int value);
void					exit_with_sucess(t_mlx *mlx, const char *msg);

int						sprite_collision(t_mlx *mlx, t_rcast *cam, double xc, double yc);
int						collision_or_event(t_mlx *mlx, t_sprites *square, int x, int y);
int						find_inter_rays(t_mlx *mlx, t_sprites *spri, double xc, double yc);
t_sprites				*sprite_ptr(t_mlx *mlx, int x, int y);

void					struct_init_par(t_pars *par);
void					struct_free(t_pars *par);
int						error_msg(char *str, t_pars *par, char *line);
int						error_msg_map(char *str, t_pars *par, int *line);
int						check_arg(int ac, char **av);

int						pos_player_check(int *line_map);
int						first_last_line_check(t_pars *par, int *line);
int						len_line_map(int *line);
void					line_is_ended_by_wall(t_pars *par, int *line);
void					walls_check_previous(t_pars *par, int i, int *previous);

void					walls_check_actual(t_pars *par, int i, int *actual, int *previous);
void					check_spaces_actual(t_pars *par, int i, int *actual, int *previous);
void					check_spaces_previous(t_pars *par, int i, int *actual, int *previous);
void					walls_check(t_pars *par, int *actual, int *previous);
void					doors_check(t_pars *par, int *next, int *actual, int *previous);

int						map_check(t_pars *par);

int						key_map_line(t_pars *par, char *line);
int						key_type(char *line, t_pars *par);
int						numbers_key_missing(t_pars *par);
void					key_check(t_pars *par);

int						**add_map_line(t_pars *par, int *line);
int						*convert_int_line(char *line);
int						parse_map(t_pars *par, char *line);

int						parse_reso(t_pars *par, char *line);
int						check_format_rgb(char *line);
int						parse_flo_rgb(t_pars *par, char *line);
int						parse_sky_rgb(t_pars *par, char *line);
int						parse_path(t_pars *par, char **path, char *line);

void					check_spaces_end_of_line(t_pars *par, char *line, int key);
int						parse_func(t_pars *par, char *line, int key);
int						parsing(t_pars *par);

int						draw_skybox(t_mlx *mlx, double height, double rcast_angle);
int						find_color_square_floor(t_mlx *mlx, t_point i);
int						floor_raycasting(t_mlx *mlx, double height, double rcast_angle);

void					erase_sprites_behing_walls(t_sprites **spri, double ray_len);
double					nb_pixel_wall(t_mlx *mlx, t_rcast *cam, t_texture *textu, double angle);

double					positive_angle(double angle);
double					angle_tri_rect(double angle);
double					ray_len(double xa, double ya, double xb, double yb);
double					height_object(t_rcast *cam, double ray_len);
int						nb_image_row(t_rcast *cam, t_texture *textu, double xa, double ya);

void	 				find_sprites(t_mlx *mlx, t_sprites *spri, double xd, double yd, double angle);

void					calc_coordinates(double angle, t_sprites *spri, char c);
void					calc_sprites_orientation(t_sprites **spri, double angle);
void					reset_ray_len_sprites(t_sprites **spri);
t_sprites				*sprites_ptr_x_ray(t_mlx *mlx, double angle, double x1, double y1);
t_sprites				*sprites_ptr_y_ray(t_mlx *mlx, double angle, double x1, double y1);

double					x_ray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu);
double					x_ray_y1_value(t_rcast *cam, double angle);
double					x_ray_ya_value(double angle);
double					x_ray_x1_value(double angle, double y1);
double					x_ray_xa_value(double angle, double y1, double ya);
int						x_ray_find_wall(t_mlx *mlx, double angle, double x_len, double y_len);

double					y_ray_len(t_mlx *mlx, t_rcast *cam, double angle, t_texture *textu);
double					y_ray_x1_value(t_rcast *cam, double angle);
double					y_ray_xa_value(double angle);
double					y_ray_y1_value(double angle, double x1);
double					y_ray_ya_value(double angle, double x1, double xa);
int						y_ray_find_wall(t_mlx *mlx, double angle, double x_len, double y_len);




#endif