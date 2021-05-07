/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:01:55 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 12:01:57 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

static int	usage(char **argv)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(argv[0], 2);
	ft_putstr_fd(" FILE.cub [OPTION]\n", 2);
	return (1);
}

int			check_args(int argc, char **argv, t_cub *cub)
{
	size_t len;

	if (argc == 1 || argc > 3)
		return (usage(argv));
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strcmp(&argv[1][len - 4], ".cub"))
		return (usage(argv));
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			return (usage(argv));
		cub->savebmp = 1;
	}
	return (0);
}
