/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:45:53 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 13:55:18 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	struct_init_par(t_pars *par)
{
	par->fd = -1;
	par->reso[0] = -1;
	par->reso[1] = -1;
	par->path_no = NULL;
	par->path_so = NULL;
	par->path_ea = NULL;
	par->path_we = NULL;
	par->path_sp = NULL;
	par->path_b_fl = NULL;
	par->path_b_sk = NULL;
	par->path_b_do = NULL;
	par->flo_rgb = -1;
	par->sky_rgb = -1;
	par->map = NULL;
}

void	struct_free(t_pars *par)
{
	int i;

	i = -1;
	par->fd != -1 ? close(par->fd) : 0;
	free(par->path_no);
	free(par->path_so);
	free(par->path_ea);
	free(par->path_we);
	free(par->path_sp);
	free(par->path_b_fl);
	free(par->path_b_sk);
	free(par->path_b_do);
	if (par->map)
	{
		while (par->map[++i])
			free(par->map[i]);
		free(par->map);
	}
}

int		error_msg(char *str, t_pars *par, char *line)
{
    ft_printf("Error\n%s", str);
	if (par)
		struct_free(par);
	free(line);
	exit(EXIT_FAILURE);
}

int		error_msg_map(char *str, t_pars *par, int *line)
{
	int		i;

	i = -1;
    ft_printf("Error\n%s", str);
	if (line)
	{
		ft_printf("Errored line : |");
		while (line[++i] != -2)
		{
			if (line[i] == -1)
				ft_printf(" ");
			else if (line[i] == NORTH)
				ft_printf("N");
			else if (line[i] == SOUTH)
				ft_printf("S");
			else if (line[i] == EAST)
				ft_printf("E");
			else if (line[i] == WEST)
				ft_printf("W");
			else
				ft_printf("%d", line[i]);
		}
		ft_printf("|\n");
	}
	if (par)
		struct_free(par);
	exit(EXIT_FAILURE);
}

int     check_arg(int ac, char **av)
{
    int		i;
	int		ret;

    i = 0;
	ret = 0;
    if (ac < 2)
        error_msg("Arguments : no file, enter it with the first argument\n", NULL, NULL);
    if (ac == 3)
	{
		if (ft_strcmp("--save", av[2]))
			error_msg("Arguments : second argument can only be '--save' option\n", NULL, NULL);
		ret = 1;
	}
	if (ac > 3)
        error_msg("Arguments : too many arguments, enter only the map file (and save option)\n", NULL, NULL);
	while (av[1][i])
		i++;
	i -= 4;
	if (ft_strcmp(&av[1][i], ".cub"))
		error_msg("Arguments : file map must end by \".cub\"\n", NULL, NULL);
	if (!i)
		error_msg("Arguments : file \".cub\" must have a name and not only be the extension\n", NULL, NULL);
    return (ret);
}