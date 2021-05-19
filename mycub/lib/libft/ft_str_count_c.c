/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:36 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:36 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_count_c(const char *s, char c)
{
	size_t i;
	size_t state;

	i = 0;
	state = OUT;
	while (*s != '\0')
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			i++;
		}
		s++;
	}
	return (i);
}
