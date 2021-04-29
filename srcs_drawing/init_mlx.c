/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:05:27 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 16:35:18 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_remove_img(t_mlx *mlx, t_img *img)
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

void	ft_err_img(const char *str, t_mlx *mlx)
{
	ft_printf("Error\n%s", str);
	if (mlx->par)
		ft_free_all(mlx->par);
	if (mlx->spri)
		ft_free_spr(mlx->spri);
	ft_remove_img(mlx, &mlx->img);
	exit(EXIT_FAILURE);
}