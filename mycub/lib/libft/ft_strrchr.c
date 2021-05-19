/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:58 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:59 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	size_t		len;
	const char	*str;

	ch = c;
	str = s;
	len = ft_strlen(str);
	while (len)
	{
		if (*(str + len) == ch)
			return ((char *)(str + len));
		len--;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}
