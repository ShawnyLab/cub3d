/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:59:57 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 22:10:03 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_rotation_angle(int position, t_cub *cub)
{
	if (position == 'N')
		cub->map.player.rotation_angle = PI / 2 * 3;
	else if (position == 'S')
		cub->map.player.rotation_angle = PI / 2;
	else if (position == 'W')
		cub->map.player.rotation_angle = PI;
	else if (position == 'E')
		cub->map.player.rotation_angle = 0;
}
/*
map.spri 개수 늘려주고, 스폰 방향에 따라 시작 각도 설정, 올바른 문자가 들어가지 않으면 오류 -1 리턴
*/
static int	check_row(char *str, t_cub *cub)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(VALID_MAP_CHARS, str[i]) == NULL)   //맵에는 NSWE 0 1 2  공백 만 나올수 있음
			return (-1);
		if (str[i] == '2')
			cub->map.sprites++;    //스프라이트 개수 늘려주기.
		if (ft_strchr(SPAWN_ORIENTATION, str[i]))
		{
			if (cub->map.player_found != 0)    //NSWE 가 이미 하나 나왔음 ! 오류
				return (-1);
			cub->map.player_found++;
			cub->map.player.map_x = i;     //현재 x 위치
			cub->map.player.map_y = cub->map.height;    //현재 y 위치
			set_rotation_angle(str[i], cub);   //NSWE 에 따른 각도 설정
			str[i] = '0';   //0으로 바꿔줌.
		}
		i++;
	}
	cub->map.height++;   //다음 줄로 넘어가기
	cub->map.width = ft_max(i, cub->map.width);  // i 에 따라 넓이 조정
	return (i == 0 ? -1 : 0);
}

void		parse_grid(t_list *trav, t_list *head, t_cub *cub)
{
	int		open;
	t_list	*lst;

	while (trav && *(char *)trav->content == '\0')    // 맵 전 공백을 모두 띄어 넘음 
		trav = trav->next;
	lst = trav;     // 맵 파싱 첫 줄 시작
	while (lst)
	{
		if (check_row(lst->content, cub) == -1)
			free_lst_quit(head, cub, ERR_MAP);
		lst = lst->next;
	} //맵이 끝날 때 까지 올바른 형식의 맵인지 체크
	if (cub->map.player_found != 1 ||
			cub->width <= 0 ||
			cub->height <= 0)
		free_lst_quit(head, cub, ERR_MAP);
	if (save_map(trav, cub) == -1)
		free_lst_quit(head, cub, ERR_MEM);
	open = FALSE;
	boundary_fill(cub->map.player.map_x, cub->map.player.map_y, &open, cub);  //맵이 오픈되어있는지 체크
	if (open == TRUE)
		free_lst_quit(head, cub, ERR_MAP);
	rev_boundary_fill(cub);
}
