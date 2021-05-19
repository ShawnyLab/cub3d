/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:38:16 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:38:20 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, size_t flag)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (flag == 1)
		free(s1);
	else if (flag == 2)
		free(s2);
	else if (flag == 12)
	{
		free(s1);
		free(s2);
	}
	return (ret);
}
