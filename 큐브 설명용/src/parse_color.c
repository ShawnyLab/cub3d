/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:50 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 14:21:33 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	str_to_color(char *str)
{
	int		color;
	int		len;

	len = strlen_isdigit(str);
	if (len < 1 || len > 3 ||
			(len != 1 && *str == '0'))
		return (-1);
	color = ft_atoi(str);
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}

/*
color에 r, g, b 비트연산해서 넣어줌
*/
static int	create_color(char **rgb, int *color)
{
	int		red;
	int		green;
	int		blue;

	red = str_to_color(rgb[0]);
	if (red < 0)
		return (-1);
	green = str_to_color(rgb[1]);
	if (green < 0)
		return (-1);
	blue = str_to_color(rgb[2]);
	if (blue < 0)
		return (-1);
	*color = (0 << 24) | (red << 16) | (green << 8) | blue;    //비트 연산 
	return (0);
}
/*
rgb 색 코드 포맷이 올바른지 체크 숫자 세개, 구분자 ',' 두개 여야함. 오류이면 -1 리턴 올바르면 0 리턴
*/
static int	check_color_format(char *colors, int delim)
{
	int	i;
	int	n_colors;
	int	n_delim;   //구분자 개수 2개여야함.

	i = 0;
	n_colors = 0;
	n_delim = 0;
	while (colors[i])
	{
		if (!ft_isdigit(colors[i]))
			return (-1);
		while (ft_isdigit(colors[i]))    //색깔 코드  끝까지 땡겨줌
			i++;
		n_colors++;
		if (colors[i] && colors[i] != delim)   //구분자 , 가 아니면 오류
			return (-1);
		if (colors[i] && colors[i] == delim)
			n_delim++;
		if (colors[i])
			i++;
	}
	if (n_delim != 2 || n_colors != 3)
		return (-1);
	return (0);
}
/*
map.ceil_color, map.floor_color 에 rgb 파싱해서 넣음, 플래그 설정 오류이면 -1 리턴 
*/
static int	save_color(int *flags, int flag, t_cub *cub)
{
	char	**rgb;
	int		color;

	if (*flags & flag || ft_strarrlen(cub->info) != 2 ||
			check_color_format(cub->info[1], ',') == -1 ||
			((rgb = ft_split(cub->info[1], ',')) == NULL)) // ',' 로 스플릿   rgb 에 , 로 스플릿 한 숫자가 들어있음.
		return (-1);
	if (ft_strarrlen(rgb) != 3 || (create_color(rgb, &color)) < 0)  //rgb 의 길이는 3이어야함. 
	{
		ft_free_strarr(rgb);
		return (-1);
	}
	if (flag & CEIL_COL)
		cub->map.ceil_color = color;
	else
		cub->map.floor_color = color;
	ft_free_strarr(rgb);
	*flags |= flag;
	return (0);
}
/*
컬러는 숫자,숫자,숫자   이기 때문에 공백으로 스플릿 되지 않음.
RGB 색깔 코드 파싱
*/
int			parse_color(int *flags, t_cub *cub)
{
	char	**info;

	info = cub->info;
	if (!ft_strcmp(*info, "C"))
	{
		if (save_color(flags, CEIL_COL, cub) < 0)
			return (-1);
	}
	else
	{
		if (save_color(flags, FLOOR_COL, cub) < 0)
			return (-1);
	}
	ft_free_strarr(info);
	return (0);
}
