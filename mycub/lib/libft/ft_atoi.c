/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:34:53 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:34:55 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned	nbr;
	int			sign;

	while (ft_isspace(*str))
		str++;
	nbr = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '+') ? 1 : -1;
	while (ft_isdigit(*str))
		nbr = *str++ - '0' + nbr * 10;
	return ((int)nbr * sign);
}
