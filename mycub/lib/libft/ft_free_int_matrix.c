/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:35:08 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:35:08 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_matrix(int **matrix, size_t size)
{
	size_t	i;

	if (matrix)
	{
		i = 0;
		while (i < size)
		{
			free(matrix[i]);
			i++;
		}
	}
	free(matrix);
}
