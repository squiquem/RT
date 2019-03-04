/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_calc3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:53:07 by sderet            #+#    #+#             */
/*   Updated: 2019/01/11 17:32:08 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	negative_firstadvance(t_hititem *i, t_ray *r, t_env *e, int *last_hit)
{
	init_all_nega(i);
	*last_hit = get_closest_item(*r, e);
	hit_mod(i->items_mod, *last_hit, i->hit_items, e);
	negative_advance(e, *last_hit, r);
}

void	negative_bigadvance(t_hititem *i, t_ray *r, t_env *e, int *last_hit)
{
	hit_mod(i->items_mod, *last_hit, i->hit_items, e);
	negative_advance(e, *last_hit, r);
}
