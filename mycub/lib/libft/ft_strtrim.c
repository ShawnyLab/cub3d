/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:39:02 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:39:03 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = s1;
	while (ft_strchr(set, *start) && *start)
		start++;
	if (*start == '\0')
		return (ft_strdup(""));
	end = start;
	while (*(end + 1))
		end++;
	while (ft_strchr(set, *end) && end > s1)
		end--;
	return (ft_strndup(start, (end - start) + 1));
}
