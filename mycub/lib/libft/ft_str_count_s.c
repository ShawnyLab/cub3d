/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:39 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:43 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_count_s(const char *s, const char *delim)
{
	size_t i;
	size_t state;

	i = 0;
	state = OUT;
	while (*s != '\0')
	{
		if (ft_strchr(delim, *s))
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
