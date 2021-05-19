/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:08 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:09 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (*str1 != '\0')
	{
		if (ft_strchr(str2, *str1) != NULL)
			return (i);
		str1++;
		i++;
	}
	return (i);
}
