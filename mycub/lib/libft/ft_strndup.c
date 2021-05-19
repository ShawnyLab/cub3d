/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:51 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:52 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	if (len < n)
		return (ft_strdup(s1));
	if (!(ret = malloc(sizeof(char) * n + 1)))
		return (NULL);
	*(ret + n) = '\0';
	while (len-- && n--)
		*(ret + n) = *(s1 + n);
	return (ret);
}
