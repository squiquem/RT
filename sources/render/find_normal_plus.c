/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:16:07 by sderet            #+#    #+#             */
/*   Updated: 2019/02/26 11:25:59 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	find_normal_plus(t_vec newstart, t_ray r, t_env *e, int id)
{
	double	finite;
	t_vec	n;
	int		type;

	n = newvec(0, 0, 0);
	type = itemtype(id, e);
	finite = dotproduct(e->item[id].dir, sub(newstart, e->item[id].center))
		/ magnitude2(e->item[id].dir);
	if (type == PLANE || type == DISK || (type == F_CYL
				&& (finite <= 0.001 || finite >= e->item[id].height - 0.001))
			|| (type == F_CONE && (finite >= e->item[id].height - 0.001)))
		n = (dotproduct(r.dir, e->item[id].dir) < 0 ? e->item[id].dir
				: opposite(e->item[id].dir));
	else if (type == BOX)
		n = find_box_normal(newstart, id, e);
	else
		n = find_normal_vec_if_not_plane(id, newstart, e);
	return (n);
}

t_vec	find_box_normal(t_vec impact, int id, t_env *e)
{
	t_vec	n;
	t_item	item;

	item = e->item[id];
	if ((impact.x > item.center.x - 0.001 && impact.x < item.center.x + 0.001)
			|| (impact.x > item.end.x - 0.001 && impact.x < item.end.x + 0.001))
		n = (impact.x > item.center.x + 0.001 ? newvec(1, 0, 0)
				: opposite(newvec(1, 0, 0)));
	else if ((impact.y > item.center.y - 0.001
				&& impact.y < item.center.y + 0.001)
			|| (impact.y > item.end.y - 0.001 && impact.y < item.end.y + 0.001))
		n = (impact.y > item.center.y + 0.001 ? newvec(0, 1, 0)
				: opposite(newvec(0, 1, 0)));
	else
		n = (impact.z > item.center.z + 0.001 ? newvec(0, 0, 1)
				: opposite(newvec(0, 0, 1)));
	return (n);
}
