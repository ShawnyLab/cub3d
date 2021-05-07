/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:02:48 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 12:02:49 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	free_lst_quit(t_list *head, t_cub *cub, char *err_msg)
{
	ft_lstclear(&head, free);
	quit_cub(cub, EXIT_FAILURE, err_msg);
}

void	free_info_lst_quit(char **info, t_list *head, t_cub *cub, char *err_msg)
{
	ft_free_strarr(info);
	free_lst_quit(head, cub, err_msg);
}

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
