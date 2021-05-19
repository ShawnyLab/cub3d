/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:14 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:22 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strtomatr(char **split, const char *s, const char *delim)
{
	char const	*word_start;
	int			i;
	size_t		state;

	i = -1;
	state = 0;
	while (*s != '\0')
	{
		if (ft_strchr(delim, *s))
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			word_start = s;
			i++;
		}
		if ((state && ft_strchr(delim, *(s + 1))) || (state && !*(s + 1)))
			if (!(split[i] = ft_strndup(word_start, s - word_start + 1)))
			{
				ft_free_strarr(split);
				return (NULL);
			}
		s++;
	}
	return (split);
}

char			**ft_split_str(const char *s, const char *delim)
{
	size_t		i;
	char		**split;

	if (s == NULL || delim == NULL)
		return (NULL);
	i = ft_str_count_s(s, delim);
	if (!(split = ft_calloc(i + 1, sizeof(char *))))
		return (NULL);
	return (ft_strtomatr(split, s, delim));
}
