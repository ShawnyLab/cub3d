/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:41 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/19 23:52:16 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
player의 방향 0으로 초기화, walkspeed, turnspeed 설정
player, sprite 의 초기위치 설정
*/
static void		initialize_player_sprites(t_player *player, t_cub *cub)
{
	int	i;

	player->turn_direction = 0;
	player->walk_direction = 0;
	player->strafe_direction = 0;
	player->walk_speed = WALK_SPEED;
	player->turn_speed = TURN_SPEED * (PI / 180);
	cub->map.player.x = cub->map.player.map_x * TILE_SIZE + TILE_SIZE / 2; // 타일에 중간에 서있기 때문에 + tilesize / 2
	cub->map.player.y = cub->map.player.map_y * TILE_SIZE + TILE_SIZE / 2;
	i = 0;
	while (i < cub->map.sprites)
	{
		cub->sprites[i].x = cub->sprites[i].map_x * TILE_SIZE + TILE_SIZE / 2;
		cub->sprites[i].y = cub->sprites[i].map_y * TILE_SIZE + TILE_SIZE / 2;  //스프라이트도 마찬가지
		i++;
	}
}
/*
texture 의 img.img, addr bpp, sizeline, endian 설정.
*/
static void		load_texture(t_cub *cub, t_texture *texture, char *path)
{
	texture->image.img = mlx_xpm_file_to_image(cub->mlx, path,
			&texture->width, &texture->height);
	if (!texture->image.img)
		quit_cub(cub, EXIT_FAILURE, "Invalid texture.");
	texture->image.addr = mlx_get_data_addr(
			texture->image.img,
			&texture->image.bits_per_pixel,
			&texture->image.size_line,
			&texture->image.endian);
}
/*
cub.texture, cub.map.paths  설정
*/
static void		initialize_image(t_cub *cub)
{
	cub->image.img = mlx_new_image(cub->mlx, cub->width,
			cub->height);
	if (!cub->image.img)
		quit_cub(cub, EXIT_FAILURE, "Image error.");
	cub->image.addr = mlx_get_data_addr(
			cub->image.img,
			&cub->image.bits_per_pixel,
			&cub->image.size_line,
			&cub->image.endian);
	load_texture(cub, &cub->texture[EAST], cub->map.paths[EAST]);
	load_texture(cub, &cub->texture[WEST], cub->map.paths[WEST]);
	load_texture(cub, &cub->texture[SOUTH], cub->map.paths[SOUTH]);
	load_texture(cub, &cub->texture[NORTH], cub->map.paths[NORTH]);
	load_texture(cub, &cub->texture[SPRITE], cub->map.paths[SPRITE]);
	if (cub->savebmp == 0)
	{
		cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, TITLE);
		if (!cub->win)
			quit_cub(cub, EXIT_FAILURE, "Can't create a new window.");
	}
}
/*
cub의 mlx, width, height, rays, fov_angle, half_fov_angle, angle_step, dist_proj_plane  설정
*/
static void		initialize_cub(t_cub *cub)
{
	int	width;
	int	height;

	cub->mlx = mlx_init();
	if (!cub->mlx)
		quit_cub(cub, EXIT_FAILURE, "Can't connect to the X server.");
	mlx_get_screen_size(cub->mlx, &width, &height);
	cub->width = ft_min(cub->width, width);
	cub->height = ft_min(cub->height, height);    //화면 보다 Reso 의 크기가 더 크면 화면 해상도로 적용함.
	cub->rays = malloc(sizeof(t_ray) * cub->width);   //넓이만큼 레이를 쏴야함.
	if (cub->rays == NULL)
		quit_cub(cub, EXIT_FAILURE, ERR_MEM);    //메모리 에러
	cub->fov_angle = FOV * (PI / 180);   //60도 라디안
	cub->half_fov_angle = (FOV / 2) * (PI / 180);   //30도 라디안
	cub->angle_step = cub->fov_angle / cub->width;    //60도 라디안을 화면 넓이로 나눔.
	//angle_step 은 60도를 화면 넓이 픽셀로 나눠서, 레이를 쏠 때 픽셀하나 움직일 때의 각도가 됨.
	cub->dist_proj_plane = (cub->width / 2) / tan(cub->half_fov_angle);  //화면의 끝 까지의 길이 distance
	//벽이 아니라, 화면의 끝 까지의 거리.
}

void			initialize(t_cub *cub)
{
	initialize_cub(cub);
	initialize_player_sprites(&cub->map.player, cub);
	initialize_image(cub);
}
