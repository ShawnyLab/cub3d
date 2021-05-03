/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:16:58 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:02:27 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	save_image_as_bmp(t_mlx *mlx)
{
	int		fd;
	int		padding_byte;
	int		i;
	char	*img_str;
	int		size_str_img;

	i = 0;
	padding_byte = 4 - (int)mlx->par->reso[0] * 3 % 4;
	padding_byte == 4 ? padding_byte = 0 : 0;
	size_str_img = 54 + ((int)mlx->par->reso[0] * (int)mlx->par->reso[1] * 3)
			+ padding_byte * (int)mlx->par->reso[1];
	fd = open("save.bmp", O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		error_msg_destroy_img("File : failed to create save file\n", mlx);
	if (!(img_str = malloc(size_str_img + 1)))
		error_msg_destroy_img("Malloc failed\n", mlx);
	img_str[size_str_img] = '\0';
	i = fill_bmp_header_info(mlx, img_str, i, size_str_img);
	fill_bmp_with_data_img(mlx, img_str, i, padding_byte);
	write(fd, img_str, size_str_img);
	free(img_str);
	exit_with_sucess(mlx, "First image saved as BMP with sucess\n");
}