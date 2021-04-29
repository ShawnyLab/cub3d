/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:42:28 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 15:51:39 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_check_now(t_pars *par, int i, int *now, int *bef)
{
	long	j;
	
	j = ft_len_map(bef) - 1;
	i++;
	while (--j >= 0)
		if (now[j + i] != 1 && now[j + i] != -1)
			ft_maperror("File .cub, map : must only be"
			" surrunded by walls ('1')\n", par, now);
}

void	ft_check_bef(t_pars *par, int i, int *bef)
{
	long	j;
	j = ft_len_map(bef) - 1;
	i--;
	while (++i <= 0)
		if (bef[j + i] != 1 && bef[j + i] != -1)
			ft_maperror("File .cub, map : must only be"
			" surrunded by walls ('1')\n", par, bef);
}

int		ft_len_map(int *line)
{
	int		i;

	i = 0;
	while (line[i] != -2)
		i++;
	return (i);
}

void	ft_now_spaces(t_pars *par, int i, int *now, int *bef)
{
	int		err;
	int		j;

	err = 0;
	j = ft_len_map(bef) - 1;
	if (i != 0)
		err += (now[i - 1] != -1 && now[i - 1] != 1) ? 1 : 0;
	if (now[i + 1] != -2)
		err += (now[i + 1] != -1 && now[i + 1] != 1) ? 1 : 0;
	if (i != 0 && i - 1 <= j)		
		err += (bef[i - 1] != -1 && bef[i - 1] != 1) ? 1 : 0;
	if (i <= j)
		err += (bef[i] != -1 && bef[i] != 1) ? 1 : 0;
	if (i + 1 <= j)
		err += (bef[i + 1] != -1 && bef[i + 1] != 1) ? 1 : 0;
	if (err)
		ft_maperror("File .cub, map : must only be surrunded"
				" by walls ('1)\n", par, bef);
}

void	ft_bef_spaces(t_pars *par, int i, int *now, int *bef)
{
	int		err;
	int		j;

	err = 0;
	j = len_line_map(now) - 1;
	if (i != 0)
		err += (bef[i - 1] != -1 && bef[i - 1] != 1) ? 1 : 0;
	if (bef[i + 1] != -2)
		err += (bef[i + 1] != -1 && bef[i + 1] != 1) ? 1 : 0;
	if (i != 0 && i - 1 <= j)
		err += (now[i - 1] != -1 && now[i - 1] != 1) ? 1 : 0;
	if (i <= j)
		err += (now[i] != -1 && now[i] != 1) ? 1 : 0;
	if (i + 1 <= j)
		err += (now[i + 1] != -1 && now[i + 1] != 1) ? 1 : 0;
	if (err)
		error_msg_map("File .cub, map : must only be surrunded"
				" by walls ('1)\n", par, bef);
}