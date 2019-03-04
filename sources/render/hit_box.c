/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:37:23 by sderet            #+#    #+#             */
/*   Updated: 2019/02/22 12:45:54 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	small_box(t_item bo, t_vec *min, t_vec *max, t_ray r)
{
	double tmp;

	min->x = (bo.center.x - r.start.x) / r.dir.x;
	max->x = (bo.end.x - r.start.x) / r.dir.x;
	if (min->x > max->x)
	{
		tmp = min->x;
		min->x = max->x;
		max->x = tmp;
	}
	min->y = (bo.center.y - r.start.y) / r.dir.y;
	max->y = (bo.end.y - r.start.y) / r.dir.y;
	if (min->y > max->y)
	{
		tmp = min->y;
		min->y = max->y;
		max->y = tmp;
	}
}

static void	small_box2(t_item bo, t_vec *min, t_vec *max, t_ray r)
{
	double tmp;

	min->x = (min->y > min->x ? min->y : min->x);
	max->x = (max->y < max->x ? max->y : max->x);
	min->z = (bo.center.z - r.start.z) / r.dir.z;
	max->z = (bo.end.z - r.start.z) / r.dir.z;
	if (min->z > max->z)
	{
		tmp = min->z;
		min->z = max->z;
		max->z = tmp;
	}
}

int			hitbox(t_ray r, t_item bo, double *t)
{
	t_vec	min;
	t_vec	max;

	small_box(bo, &min, &max, r);
	if (min.x > max.y || min.y > max.x)
		return (0);
	small_box2(bo, &min, &max, r);
	if (min.x > max.z || min.z > max.x)
		return (0);
	min.x = (min.z > min.x ? min.z : min.x);
	max.x = (max.z < max.x ? max.z : max.x);
	return (calc_discr(1.0, -min.x - max.x, min.x * max.x, t));
}
