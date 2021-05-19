/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:46 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:47 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (!n || str1 == str2)
		return (0);
	while (*str1 && *str2 && (n-- - 1))
	{
		if (*str1 != *str2)
			return (((unsigned char)*str1) - ((unsigned char)*str2));
		str1++;
		str2++;
	}
	return (((unsigned char)*str1) - ((unsigned char)*str2));
}
