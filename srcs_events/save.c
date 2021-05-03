/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:54:21 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 15:01:32 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	exit_with_sucess(t_mlx *mlx, const char *msg)
{
	if (mlx->par)
		struct_free(mlx->par);
	if (mlx->spri)
		free_sprite_struct(mlx->spri);
	destroy_all_images(mlx, &mlx->img);
	ft_printf("%s", msg);
	exit(EXIT_SUCCESS);
}

void	put_3_octets_in_str_img(char *int_to_fill, int *i, int value)
{
	*((unsigned char *)int_to_fill) = *(unsigned char *)&value;
	*((unsigned char *)int_to_fill + 1) = *((unsigned char *)&value + 1); //green
	*((unsigned char *)int_to_fill + 2) = *((unsigned char *)&value + 2); //red
	*i += 3;
}

void	put_4_octets_in_str_img(int *int_to_fill, int *i, int value)
{
	*int_to_fill = value;
	*i += 4;
}

int		fill_bmp_header_info(t_mlx *mlx, char *img_str, int i, int size_str_img)
{
	img_str[i++] = 0x42;
	img_str[i++] = 0x4D;
	put_4_octets_in_str_img((int *)&img_str[i], &i, size_str_img);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x36);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x28);
	put_4_octets_in_str_img((int *)&img_str[i], &i, (int)mlx->par->reso[0]);
	put_4_octets_in_str_img((int *)&img_str[i], &i, (int)mlx->par->reso[1]);
	img_str[i++] = 0x1;
	img_str[i++] = 0x0;
	img_str[i++] = 0x18;
	img_str[i++] = 0x0;
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);
	put_4_octets_in_str_img((int *)&img_str[i], &i, 0x0);	
	return (i);
}

void	fill_bmp_with_data_img(t_mlx *mlx, char *img_str, int i, int padding_byte)
{
	int		row;
	int		line;
	int		j;
	int		line_img;

	line = -1;
	line_img = (int)mlx->par->reso[1] - 1;
	while (++line < (int)mlx->par->reso[1])
	{
		j = 0;
		row = -1;
		while (++row < (int)mlx->par->reso[0])
			put_3_octets_in_str_img(&img_str[i], &i, mlx->addr.screen[j++ 
					+ line_img * mlx->info.screen[SIZE_LINE]]); 
		line_img--;
		padding_byte == 3 ? put_3_octets_in_str_img(&img_str[i], &i, 0) : 0;
		if (padding_byte == 2)	
		{
			img_str[i++] = 0x0;
			img_str[i++] = 0x0;
		}
		padding_byte == 1 ? img_str[i++] = 0x0 : 0;
	}
}