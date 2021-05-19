/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:36:45 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:36:46 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char const	*s;

	if (dst == src)
		return (dst);
	d = dst;
	s = src;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
		return (dst);
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
