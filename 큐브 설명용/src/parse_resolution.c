/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:04 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 13:55:37 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
해상도 파싱    R 숫자 숫자   // 오류면 -1 반환  정상적이면 0 반환 , flag 설정
*/
int		parse_resolution(int *flags, t_cub *cub)
{
	char	**info;
	int		len_width;
	int		len_height;

	info = cub->info;
	if (*flags & RESOLUTION || ft_strarrlen(info) != 3 ||     //오류 목록 인자가 3개가 아니거나, R  뒤에 숫자가 아닐 경우  -1 반환
			(len_width = strlen_isdigit(info[1])) < 1 ||
			(len_height = strlen_isdigit(info[2])) < 1 ||
			*info[1] == '0' || *info[2] == '0')
		return (-1);
	else  //정상적인 형태이면, cub->width, height 에 숫자 넣어 준후 프리.
	{
		cub->width = len_width < 10 ? ft_atoi(info[1]) : INT_MAX;
		cub->height = len_height < 10 ? ft_atoi(info[2]) : INT_MAX;
	}
	ft_free_strarr(info);
	*flags |= RESOLUTION;    //or 비트연산.  flag 가 하나라도 활성화 되어있으면 1
	return (0);
}
