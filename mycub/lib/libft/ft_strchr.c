/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:50 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:51 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char		*p;

	p = s;
	while (*p)
	{
		if (*p == (const char)c)
			return ((char *)p);
		p++;
	}
	if (*p == (const char)c)
		return ((char *)p);
	return (NULL);
}
