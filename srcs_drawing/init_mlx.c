/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:05:27 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:27:53 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	destroy_all_images(t_mlx *mlx, t_img *img)
{
	img->t_no ? mlx_destroy_image(mlx->ptr, img->t_no) : 0;
	img->t_so ? mlx_destroy_image(mlx->ptr, img->t_so) : 0;
	img->t_ea ? mlx_destroy_image(mlx->ptr, img->t_ea) : 0;
	img->t_we ? mlx_destroy_image(mlx->ptr, img->t_we) : 0;
	img->t_fl ? mlx_destroy_image(mlx->ptr, img->t_fl) : 0;
	img->t_sk ? mlx_destroy_image(mlx->ptr, img->t_sk) : 0;
	img->t_do ? mlx_destroy_image(mlx->ptr, img->t_do) : 0;
	img->s_4 ? mlx_destroy_image(mlx->ptr, img->s_4) : 0;
	img->s_5 ? mlx_destroy_image(mlx->ptr, img->s_5) : 0;
	img->s_6 ? mlx_destroy_image(mlx->ptr, img->s_6) : 0;
	img->s_7 ? mlx_destroy_image(mlx->ptr, img->s_7) : 0;
	img->s_8 ? mlx_destroy_image(mlx->ptr, img->s_8) : 0;
	img->s_9 ? mlx_destroy_image(mlx->ptr, img->s_9) : 0;
	img->hud ? mlx_destroy_image(mlx->ptr, img->hud) : 0;
	img->life ? mlx_destroy_image(mlx->ptr, img->life) : 0;
	img->guns ? mlx_destroy_image(mlx->ptr, img->guns) : 0;
	img->num ? mlx_destroy_image(mlx->ptr, img->num) : 0;
	img->font ? mlx_destroy_image(mlx->ptr, img->font) : 0;
	img->screen ? mlx_destroy_image(mlx->ptr, img->screen) : 0;
	mlx->win ? mlx_destroy_window(mlx->ptr, mlx->win) : 0;
}

void	error_msg_destroy_img(const char *str, t_mlx *mlx)
{
	ft_printf("Error\n%s", str);
	if (mlx->par)
		struct_free(mlx->par);
	if (mlx->spri)
		free_sprite_struct(mlx->spri);
	destroy_all_images(mlx, &mlx->img);
	exit(EXIT_FAILURE);
}

void	init_addr_info(int **addr, void *img, int info[5])
{
	*addr = (int *)mlx_get_data_addr(img, &(info[BITS_PER_PIX]), 
			&(info[SIZE_LINE]), &(info[ENDIAN]));
	info[SIZE_LINE] /= (info[BITS_PER_PIX] / 8);
}

void	struct_init_addr_info(t_mlx *mlx, t_addr *addr, t_info *info)
{
	init_addr_info(&(addr->screen), mlx->img.screen, info->screen);
	init_addr_info(&(addr->t_no), mlx->img.t_no, info->t_no);
	init_addr_info(&(addr->t_so), mlx->img.t_so, info->t_so);
	init_addr_info(&(addr->t_ea), mlx->img.t_ea, info->t_ea);
	init_addr_info(&(addr->t_we), mlx->img.t_we, info->t_we);
	init_addr_info(&(addr->t_fl), mlx->img.t_fl, info->t_fl);
	init_addr_info(&(addr->t_sk), mlx->img.t_sk, info->t_sk);
	init_addr_info(&(addr->t_do), mlx->img.t_do, info->t_do);
	init_addr_info(&(addr->s_4), mlx->img.s_4, info->s_4);
	init_addr_info(&(addr->s_5), mlx->img.s_5, info->s_5);
	init_addr_info(&(addr->s_6), mlx->img.s_6, info->s_6);
	init_addr_info(&(addr->s_7), mlx->img.s_7, info->s_7);
	init_addr_info(&(addr->s_8), mlx->img.s_8, info->s_8);
	init_addr_info(&(addr->s_9), mlx->img.s_9, info->s_9);
	init_addr_info(&(addr->hud), mlx->img.hud, info->hud);
	init_addr_info(&(addr->life), mlx->img.life, info->life);
	init_addr_info(&(addr->guns), mlx->img.guns, info->guns);
	init_addr_info(&(addr->num), mlx->img.num, info->num);
	init_addr_info(&(addr->font), mlx->img.font, info->font);
}

void	struct_init_img_ptr_to_null(t_img *img)
{
	img->screen = NULL;
	img->t_no = NULL;
	img->t_so = NULL;
	img->t_ea = NULL;
	img->t_we = NULL;
	img->t_fl = NULL;
	img->t_sk = NULL;
	img->t_do = NULL;
	img->s_4 = NULL;
	img->s_5 = NULL;
	img->s_6 = NULL;
	img->s_7 = NULL;
	img->s_8 = NULL;
	img->s_9 = NULL;
	img->hud = NULL;
	img->life = NULL;
	img->guns = NULL;
	img->num = NULL;
	img->font = NULL;
}
