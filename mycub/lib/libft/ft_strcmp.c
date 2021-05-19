/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:54 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:55 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (str1 == str2)
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (((unsigned char)*str1) - ((unsigned char)*str2));
		str1++;
		str2++;
	}
	return (((unsigned char)*str1) - ((unsigned char)*str2));
}
