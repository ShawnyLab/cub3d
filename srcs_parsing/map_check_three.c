/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:51:53 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 15:55:26 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_check_door(t_pars *par, int *next, int *now, int *bef)
{
	int		i;
	
	i = -1;
	while (now[++i] != -2)
	{
		if ((now[i] == 2 || now[i] == 3) && !((now[i - 1] == 1 &&
			now[i + 1] == 1 && bef[i] != 1 && next[i] != 1) ||
			(now[i - 1] != 1 && now[i + 1] != 1 && bef[i] == 1 &&
			next[i] == 1)))
			ft_maperror("File .cub, map : doors must be surrunded by 2 walls\n", par, now);
	}
}