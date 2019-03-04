/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_items_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:32:50 by sderet            #+#    #+#             */
/*   Updated: 2019/02/25 18:15:32 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	HITPLANE function:
**	Returns 1 if the plane is hit and change the parameter t, else 0
*/

int		hitplane(t_ray r, t_item p, double *t)
{
	double	t0;

	if (dotproduct(p.dir, r.dir) != 0)
	{
		t0 = -(dotproduct(p.dir, r.start) + p.d) / dotproduct(p.dir, r.dir);
		if (t0 > 0.001f && (*t == -1 || t0 < *t))
		{
			*t = t0;
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

int		closest_disk(t_ray r, t_item cy, double *t)
{
	int		ret1;
	double	t1;
	int		ret2;
	double	t2;

	t1 = *t;
	t2 = *t;
	ret1 = hitdisk(r, newdisk(cy.dir, cy.center, cy.radius, cy.mat), &t1);
	ret2 = hitdisk(r, newdisk(cy.dir, add(cy.center, scale(cy.height, cy.dir)),
				cy.radius, cy.mat), &t2);
	if (ret1 && ret2)
	{
		*t = t1 > t2 ? t2 : t1;
		return (1);
	}
	else if (ret1 && !ret2)
		return (hitdisk(r, newdisk(cy.dir, cy.center, cy.radius, cy.mat), t));
	else if (!ret1 && ret2)
		return (hitdisk(r, newdisk(cy.dir, add(cy.center, scale(cy.height,
								cy.dir)), cy.radius, cy.mat), t));
	else
		return (0);
}

int		hitfcylinder(t_ray r, t_item cy, double *t)
{
	double	hit;
	double	sign;
	t_vec	intersection;

	hit = *t;
	if (!hitcylinder(r, cy, &hit))
		return (closest_disk(r, cy, t));
	intersection = add(r.start, scale(hit, r.dir));
	sign = dotproduct(cy.dir, sub(intersection, cy.center));
	if (sign < 0 || sign > cy.height)
		return (closest_disk(r, cy, t));
	else
	{
		closest_disk(r, cy, &hit);
		*t = hit;
		return (1);
	}
}

int		hitfcone(t_ray r, t_item cy, double *t)
{
	double	hit;
	double	sign;
	t_vec	intersection;

	hit = *t;
	if (!hitcone(r, cy, &hit))
		return (0);
	intersection = add(r.start, scale(hit, r.dir));
	sign = dotproduct(cy.dir, sub(intersection, cy.center))
		/ magnitude2(cy.dir);
	if (sign > cy.height)
		return (hitdisk(r, newdisk(cy.dir,
						add(cy.center, scale(cy.height, cy.dir)),
						tan(cy.angle * M_PI / 180) * cy.height, cy.mat), t));
	else if (sign <= 0)
		return (0);
	else
	{
		*t = hit;
		return (1);
	}
}
