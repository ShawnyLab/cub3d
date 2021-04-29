/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:12:38 by jinspark          #+#    #+#             */
/*   Updated: 2021/04/25 16:01:19 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		**ft_add_map(t_pars *par, int *line)
{
	int	i;
	int	**tmp;

	i = 0;
	if (!par->map)
	{
		if (!(par->map = malloc(sizeof(int *) * 2)))
			return (NULL);
		par->map[0] = line;
		par->map[1] = (NULL);
	}
	else
	{
		tmp = par->map;
		while (par->map[i])
			i++;
		if (!(par->map = malloc(sizeof(int *) * (i + 2))))
		{
			par->map = tmp;
			return (NULL);
		}
		par->map[i] = line;
		par->map[i + 1] = (NULL);
		while (--i >= 0)
			par->map[i] = tmp[i];
		free(tmp);
	}
	return (par->map);
}

int		*ft_convert_int(char *line)
{
	int		i;
	int		*int_line;

	i = -1;
	if (!(int_line = malloc(sizeof(*int_line) * (ft_strlen(line) + 1))))
		return (NULL);
	while (line[++i])
	{
		if (line[i] == ' ')
			int_line[i] = -1;
		else
			int_line[i] = line[i] - '0';
	}
	int_line[i] = -2;
	return (int_line);
}

int		ft_parse_map(t_pars *par, char *line)
{
	int	i;
	int	*int_line;

	i = 0;
	if (!(int_line = ft_convert_int(line)))
		ft_str_error("Malloc failed\n", par, line);
	if (!(par->map = ft_add_map(par, int_line)))
	{
		free(int_line);
		ft_str_error("Malloc failed\n", par, line);
	}
	return (1);
}