/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:35:43 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/12 16:35:44 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *p2;

	if (new != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			p2 = ft_lstlast(*alst);
			p2->next = new;
		}
	}
}
