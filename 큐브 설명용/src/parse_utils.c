/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:12 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 13:56:55 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
t_list 형 프리
*/
void	free_lst_quit(t_list *head, t_cub *cub, char *err_msg)
{
	ft_lstclear(&head, free);
	quit_cub(cub, EXIT_FAILURE, err_msg);
}
/*
char ** info 프리
*/
void	free_info_lst_quit(char **info, t_list *head, t_cub *cub, char *err_msg)
{
	ft_free_strarr(info);
	free_lst_quit(head, cub, err_msg);
}
/*
숫자 아니면 -1 반환. 숫자이면 길이 반환
*/
int		strlen_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (i);
}
