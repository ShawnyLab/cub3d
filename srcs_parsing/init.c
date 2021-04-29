/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:45:53 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:45:39 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_struct_init(t_pars *par)
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

void	ft_free_all(t_pars *par)
{
	int	i;

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

int		ft_str_error(char *str, t_pars *par, char *line)
{
	ft_printf("Error\n%s", str);
	if (par)
		free_all(par);
	free(line);
	exit(EXIT_FAILURE);
	
}

int		ft_check_arg(int argc, char **argv)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (argc < 2)
		ft_str_error("Arguments : no file, enter it with the first argument\n", NULL, NULL);
	if (argc == 3)
	{
		if (ft_strcmp("--save", argv[2]))
			ft_str_error("Arguments : second argument can only be '--save' option\n", NULL, NULL);
		ret = 1;
	}
	if (argc > 3)
	    ft_str_error("Arguments : too many arguments, enter only the map file (and save option)\n", NULL, NULL);
	while (argv[1][i])
		i++;
	i -= 4;
	if (ft_strcmp(&argv[1][i], ".cub"))
		ft_str_error("Arguments : file map must end by \".cub\"\n", NULL, NULL);
	if (!i)
		ft_str_error("Arguments : file \".cub\" must have a name and not only be the extension\n", NULL, NULL);
	return (ret);
}

int		ft_maperror(char *str, t_pars *par, int *line)
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
		ft_free_all(par);
	exit(EXIT_FAILURE);
}