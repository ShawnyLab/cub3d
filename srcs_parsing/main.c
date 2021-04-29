/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:43:57 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/28 20:40:17 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_pars	par;
	int		save;

	save = ft_check_arg(argc, argv);
	ft_struct_init(&par);
	if ((par.fd = open(argv[1], O_RDONLY)) == -1)
		ft_str_error("Arguments : incorrect file, failed to open it\n", &par, NULL);
	ft_parse(&par);
	
}