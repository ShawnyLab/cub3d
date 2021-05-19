/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:35:40 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:35:41 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_nblen(long int nb)
{
	if (nb == 0)
		return (0);
	return (1 + ft_nblen(nb / 10));
}

static char		*ft_nbtostrarr(char *ret, long int nb, long int len, int i)
{
	while (len > 0)
	{
		if (len >= i)
		{
			len--;
			ret[len] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	long int	nb;
	char		*ret;
	long int	len;
	long int	s;
	int			i;

	if (n == 0)
		return (ft_strdup("0"));
	nb = (long int)n;
	len = ft_nblen(n);
	s = (n < 0) ? 1 : 0;
	if (!(ret = ft_calloc(sizeof(char), len + 1 + s)))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		ret[i] = '-';
		i++;
		nb *= -1;
	}
	ft_nbtostrarr(&ret[i], nb, len, i);
	return (ret);
}
