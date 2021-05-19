/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:28 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:33 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strtomatr(char **split, const char *s, char c)
{
	char const	*word_start;
	int			i;
	size_t		state;

	i = -1;
	state = 0;
	while (*s != '\0')
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			word_start = s;
			i++;
		}
		if ((state == IN && *(s + 1) == c) || (state == IN && *(s + 1) == '\0'))
			if ((split[i] = ft_strndup(word_start, s - word_start + 1)) == NULL)
			{
				ft_free_strarr(split);
				return (NULL);
			}
		s++;
	}
	return (split);
}

char			**ft_split(const char *s, char c)
{
	size_t		i;
	char		**split;

	if (s == NULL)
		return (NULL);
	i = ft_str_count_c(s, c);
	if (!(split = ft_calloc(i + 1, sizeof(char *))))
		return (NULL);
	return (ft_strtomatr(split, s, c));
}
