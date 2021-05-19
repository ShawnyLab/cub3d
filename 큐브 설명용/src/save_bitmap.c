/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:01:01 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/19 16:23:52 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
**비트맵 파일 헤더
*/
static void	initialize_bit_file_header(t_bitmap_file_header *bfh, t_cub *cub)
{
	bfh->bf_reverved1 = 0;   //사용되지 않는공간 1
	bfh->bf_reserved2 = 0;   // 2
	bfh->bf_off_bits = 54;    //비트맵 파일 헤더 (14 바이트) + 비트맵 정보 헤더 (40 바이트) 로 비트맵의 시작 위치.
	bfh->bf_size = 2 + sizeof(t_bitmap_file_header) +
					sizeof(t_bitmap_info_header) +
					cub->width * cub->height * 4;   //ARGB 라서 * 4
					//비트맵 헤더 크기  : 42 4D (BM) 라서 처음에 2를 더함.
					//t_bitmap_file_header 의 크기 : 12바이트
					//t_bitmap_info_header 의 크기 : 40바이트
}
/*
**비트맵 인포 헤더
*/
static void	initialize_bit_info_header(t_bitmap_info_header *bih, t_cub *cub)
{
	bih->bi_size = sizeof(t_bitmap_info_header);    //비트맵 인포 헤더의 크기   -> 4바이트
	bih->bi_width = cub->width;      				//큐브의 너비			 -> 4바이트
	bih->bi_height = cub->height;     //양수이기 때문에 이미지 상하가 뒤집힌 상태.  -> 4바이트
	bih->bi_planes = 1;				//									  -> 2바이트
	bih->bi_bit_count = 32;      // 0-256 2의 8제곱  ARGB 네개 이므로 8 * 4 = 32비트  -> 2바이트
	bih->bi_compression = 0;    //압축 유무
	bih->bi_size_image = 0;     //비트맵의 크기
	bih->bi_x_pels_per_meter = 2850;   //가로 해상도
	bih->bi_y_pels_per_meter = 2850;   //세로 해상도
	bih->bi_clr_used = 0;       //사용한 색상 수
	bih->bi_clr_important = 0;  //중요 색상 인덱스
}

static void	write_bitmap_to_image(t_bitmap_file_header *bfh,
		t_bitmap_info_header *bih, int fd, t_cub *cub)
{
	unsigned short	bf_type;
	int				y;
	int				x;
	int				pixel;

	bf_type = 0x4d42;   //비트맵 파일   Ascii 로 BM 비트맵 이라는 뜻   https://karfn84.tistory.com/entry/%EC%BB%B4%ED%93%A8%ED%84%B0%EC%9D%BC%EB%B0%98-%EB%B9%84%ED%8A%B8%EB%A7%B5BMP-%ED%8C%8C%EC%9D%BC-%EA%B5%AC%EC%A1%B0-%EB%B6%84%EC%84%9D
	if ((write(fd, &bf_type, sizeof(bf_type))) < 0)
		quit_cub(cub, EXIT_FAILURE, ERR_WR);
	if ((write(fd, bfh, sizeof(*bfh))) < 0)
		quit_cub(cub, EXIT_FAILURE, ERR_WR);
	if ((write(fd, bih, sizeof(*bih))) < 0)
		quit_cub(cub, EXIT_FAILURE, ERR_WR);
	y = bih->bi_height - 1;    //bi_height가 양수이기 때문에 아래서부터 위로 픽셀을 그려줘야함
	while (y >= 0)
	{
		x = 0;
		while (x < bih->bi_width)
		{
			pixel = pixel_get(&cub->image, x, y);
			if ((write(fd, &pixel, sizeof(pixel))) < 0)
				quit_cub(cub, EXIT_FAILURE, ERR_WR);
			x++;
		}
		y--;
	}
}

void		save_bitmap(t_cub *cub)
{
	t_bitmap_file_header	bfh;
	t_bitmap_info_header	bih;
	int						fd;

	initialize_bit_file_header(&bfh, cub);
	initialize_bit_info_header(&bih, cub);
	fd = open(SCREENSHOT, O_WRONLY | O_CREAT | O_TRUNC,    //WRONLY 쓰기전용, O_CREATE 없으면 생성 , O_TRUNC 파일 생성시 이미 있고, 쓰기옵션으로 열려있으면 
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);       //전부 지우고 파일의 길이를 0으로 변경, S_IRUSR 읽을 수 있음, S_IWUSR 쓰기 가능, s_IRGRP, SIROTH 권한내용
	if (fd < 0)
		quit_cub(cub, EXIT_FAILURE, "Open error.");
	write_bitmap_to_image(&bfh, &bih, fd, cub);
	close(fd);
}
