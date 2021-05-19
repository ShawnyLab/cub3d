/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:55 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:55 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	const char *resetn;
	const char *ret;

	if (*need == '\0')
		return ((char *)hay);
	ret = hay;
	resetn = need;
	while (*hay && len)
	{
		need = resetn;
		while ((*hay == *need) && *hay != '\0' && *need != '\0' && len)
		{
			need++;
			hay++;
			len--;
		}
		if (*need == '\0')
			return ((char *)hay - (need - resetn));
		if (*hay == '\0' || len == '\0')
			return (NULL);
		hay = ++ret;
		len += (need - resetn);
		len--;
	}
	return (NULL);
}
