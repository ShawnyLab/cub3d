/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_anim_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:32:21 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 11:32:26 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

void	ft_init_animation(t_adata *a)
{
	a->joe.anim_start = 0;
	a->joe.anim_count = 0;
	a->map.map_r_half = ceil((double)(a->win.win_w / 2));
	a->map.map_b_half = ceil((double)(a->win.win_h / 2));
}
