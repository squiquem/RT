/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:08:38 by sderet            #+#    #+#             */
/*   Updated: 2019/02/22 09:22:00 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hitdisk(t_ray r, t_item d, double *t)
{
	t_vec	relative;
	t_vec	intersec;
	double	t0;
	double	dist;

	d.dir = normalize(d.dir);
	r.dir = normalize(r.dir);
	t0 = dotproduct(d.dir, r.dir);
	if (t0 > -0.0001 && t0 < 0.0001)
		return (0);
	relative = sub(d.center, r.start);
	t0 = dotproduct(relative, d.dir) / t0;
	if (t0 < 0.001f)
		return (0);
	intersec = add(r.start, scale(t0, r.dir));
	intersec = sub(intersec, d.center);
	dist = dotproduct(intersec, intersec);
	if ((double)sqrt(dist) >= (double)d.radius || (*t != -1 && t0 >= *t))
		return (0);
	*t = t0;
	return (1);
}
