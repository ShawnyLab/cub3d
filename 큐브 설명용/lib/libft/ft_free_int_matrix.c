/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:02:42 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 22:02:43 by jinspark         ###   ########.fr       */
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
