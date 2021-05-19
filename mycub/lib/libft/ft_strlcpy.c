/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:34 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:35 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char *start;

	if (size == 0)
		return (ft_strlen(src));
	start = src;
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	while (*src)
		src++;
	return (src - start);
}
