/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:38:27 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 11:38:28 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_sprites(t_adata *a, t_sps *sps)
{
	int		i;

	i = 0;
	while (i < sps->number)
	{
		destroyimg(a, &sps->items[i].imgsp);
		i++;
	}
	free(sps->items);
}

void	*ft_freetext(char **text)
{
	size_t	i;

	i = 0;
	while (text[i])
	{
		free(text[i]);
		i++;
	}
	free(text);
	return (0);
}

void	free_all_strs(char **strs)
{
	while (*strs)
	{
		free(*strs);
		strs++;
	}
}
