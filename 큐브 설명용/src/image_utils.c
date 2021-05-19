/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:36 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:30:44 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
bpp : ARGB 32 bits   8로 나눠줘야함.
char 형이기 때문에 (1바이트)  4바이트인 unsigned int* 로 형변환 해줘야함.
*/
void		pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
픽셀의 정보를 가져옴.
*/
int			pixel_get(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
