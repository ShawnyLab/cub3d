/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:49:38 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:32:28 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	load_sprites(t_mlx *mlx, char *path, char *name, int num_sprite)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(path, name)))
		error_msg_destroy_img("Malloc failed\n", mlx);
	if (num_sprite == SP_GUARD && !(mlx->img.s_4 = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.s_4[WIDTH]), &(mlx->info.s_4[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading sprite number 5\n", mlx);
	if (num_sprite == SP_TREE && !(mlx->img.s_5 = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.s_5[WIDTH]), &(mlx->info.s_5[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading sprite number 5\n", mlx);
	else if (num_sprite == SP_ARMOR && !(mlx->img.s_6 = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.s_6[WIDTH]), &(mlx->info.s_6[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading sprite number 6\n", mlx);
	else if (num_sprite == SP_HEALTH && !(mlx->img.s_7 = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.s_7[WIDTH]), &(mlx->info.s_7[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading sprite number 7\n", mlx);
	else if (num_sprite == SP_AMMO && !(mlx->img.s_8 = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.s_8[WIDTH]), &(mlx->info.s_8[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading sprite number 8\n", mlx);
	else if (num_sprite == SP_FLAG && !(mlx->img.s_9 = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.s_9[WIDTH]), &(mlx->info.s_9[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading sprite number 9\n", mlx);
	else if (num_sprite == SP_HUD && !(mlx->img.hud = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.hud[WIDTH]), &(mlx->info.hud[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading HUD\n", mlx);
	else if (num_sprite == SP_LIFEBAR && !(mlx->img.life = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.life[WIDTH]), &(mlx->info.life[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading lifebar\n", mlx);
	else if (num_sprite == SP_GUNS && !(mlx->img.guns = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.guns[WIDTH]), &(mlx->info.guns[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading gun\n", mlx);
	else if (num_sprite == SP_NUMBERS && !(mlx->img.num = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.num[WIDTH]), &(mlx->info.num[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading numbers\n", mlx);
	else if (num_sprite == SP_FONT && !(mlx->img.font = mlx_xpm_file_to_image(mlx->ptr, tmp,
			&(mlx->info.font[WIDTH]), &(mlx->info.font[HEIGHT]))))
		error_msg_destroy_img("Sprites : error loading fonts\n", mlx);
	free(tmp);
}

void	struct_init_img(t_mlx *mlx, t_info *info)
{
	struct_init_img_ptr_to_null(&mlx->img);
	mlx->img.screen = mlx_new_image(mlx->ptr, (int)mlx->par->reso[0], (int)mlx->par->reso[1]);
	if (!(mlx->img.t_no = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_no, &(info->t_no[WIDTH]), &(info->t_no[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading north texture\n", mlx);
	if (!(mlx->img.t_so = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_so, &(info->t_so[WIDTH]), &(info->t_so[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading south texture\n", mlx);
	if (!(mlx->img.t_ea = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_ea, &(info->t_ea[WIDTH]), &(info->t_ea[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading east texture\n", mlx);
	if (!(mlx->img.t_we = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_we, &(info->t_we[WIDTH]), &(info->t_we[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading west texture\n", mlx);
	if (!(mlx->img.t_fl = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_b_fl, &(info->t_fl[WIDTH]), &(info->t_fl[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading floor texture\n", mlx);
	if (!(mlx->img.t_sk = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_b_sk, &(info->t_sk[WIDTH]), &(info->t_sk[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading sky texture\n", mlx);
	if (!(mlx->img.t_do = mlx_xpm_file_to_image(mlx->ptr, mlx->par->path_b_do, &(info->t_do[WIDTH]), &(info->t_do[HEIGHT]))))
		error_msg_destroy_img("Textures : error loading door texture\n", mlx);
	load_sprites(mlx, mlx->par->path_sp, "num_4/guard.xpm", SP_GUARD);
	load_sprites(mlx, mlx->par->path_sp, "num_5/tree.xpm", SP_TREE);
	load_sprites(mlx, mlx->par->path_sp, "num_6/armor.xpm", SP_ARMOR);
	load_sprites(mlx, mlx->par->path_sp, "num_7/health.xpm", SP_HEALTH);
	load_sprites(mlx, mlx->par->path_sp, "num_8/ammo.xpm", SP_AMMO);
	load_sprites(mlx, mlx->par->path_sp, "num_9/flag.xpm", SP_FLAG);
	load_sprites(mlx, mlx->par->path_sp, "hud.xpm", SP_HUD);
	load_sprites(mlx, mlx->par->path_sp, "lifebar.xpm", SP_LIFEBAR);
	load_sprites(mlx, mlx->par->path_sp, "guns.xpm", SP_GUNS);
	load_sprites(mlx, mlx->par->path_sp, "numbers.xpm", SP_NUMBERS);
	load_sprites(mlx, mlx->par->path_sp, "font.xpm", SP_FONT);
}

void	struct_init_events_bool(t_event *eve)
{
	eve->print_texture = 1;
	eve->ammo = AMMO_START;
	eve->player_is_shooting = 0;
	eve->gun_shot = 0;
	eve->lifebar = FULL_LIFE;
	eve->level = 1;
	eve->nb_life = 0;
}

void	struct_init_mlx(t_mlx *mlx)
{
	mlx->start_move.tv_sec = 0.0;
	mlx->start_rota.tv_sec = 0.0;
	mlx->spri = NULL;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, (int)mlx->par->reso[0], (int)mlx->par->reso[1], "cub3d");
	struct_init_img(mlx, &mlx->info);
	struct_init_addr_info(mlx, &mlx->addr, &mlx->info);
	struct_init_events_bool(&mlx->eve);
}
