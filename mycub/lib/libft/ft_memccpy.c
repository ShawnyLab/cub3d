/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:36:29 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:36:30 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char *s;

	d = dst;
	s = src;
	while (n--)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return ((void *)++d);
		d++;
		s++;
	}
	return (NULL);
}
