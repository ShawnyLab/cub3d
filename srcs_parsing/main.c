/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:43:57 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/03 16:17:51 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int main(int ac, char **av)
{
	t_pars	par;
	int		save;
	
    save = check_arg(ac, av);
	struct_init_par(&par);
	if ((par.fd = open(av[1], O_RDONLY)) == -1)
		error_msg("Arguments : incorrect file, failed to open it\n", &par, NULL);
	parsing(&par);
	drawing(&par, save);
    return (0);
}
