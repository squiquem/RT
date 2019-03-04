/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/26 11:21:54 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FIND_NORMAL_VEC_IF_NOT_PLANE function:
**	Finds the normal vector in the point newstart according to the hit item
**	(only if the item != plane)
*/

t_vec		find_normal_vec_if_not_plane(int id, t_vec newstart, t_env *e)
{
	t_vec	n;
	int		type;

	type = itemtype(id, e);
	n = newvec(0, 0, 0);
	if (type == SPHERE)
		n = sub(newstart, e->item[id].center);
	else if (type == I_CYL || type == F_CYL)
		n = find_cylinder_normal(newstart, e->item[id]);
	else if (type == I_CONE || type == F_CONE)
		n = find_cone_normal(newstart, e->item[id]);
	else if (type == QUADRIC)
		n = find_quadric_normal(newstart, e->item[id]);
	return (n);
}

/*
**	FIND_CYLINDER_NORMAL function:
**	Calculates the normal vector to a cylinder
*/

t_vec		find_cylinder_normal(t_vec newstart, t_item cyl)
{
	t_vec	m;
	t_vec	n;

	m = find_h(cyl.dir, cyl.center, newstart);
	n = sub(newstart, m);
	return (n);
}

/*
**	FIND_CONE_NORMAL function:
**	Calculate the normal vector to plane
*/

t_vec		find_cone_normal(t_vec newstart, t_item cone)
{
	t_vec	n;
	t_vec	h;
	t_vec	tmp;
	t_vec	tmp2;
	t_vec	sc1;

	h = find_h(cone.dir, cone.center, newstart);
	tmp = sub(cone.center, h);
	tmp2 = sub(newstart, h);
	tmp2 = normalize(tmp2);
	sc1 = scale(cos(cone.angle * M_PI / 180), tmp2);
	if (dotproduct(tmp, cone.dir) > 0)
		tmp2 = scale(sin(cone.angle * M_PI / 180), cone.dir);
	else
		tmp2 = scale(-sin(cone.angle * M_PI / 180), cone.dir);
	n = add(sc1, tmp2);
	return (n);
}

/*
**	FIND_H function:
**	Intermediate function to find normal vector to a cylinder or cone
*/

t_vec		find_h(t_vec cd, t_vec cc, t_vec n)
{
	t_vec	u;
	t_vec	v;
	t_vec	w;
	double	z;

	u = sub(n, cc);
	z = dotproduct(cd, u) / magnitude2(cd);
	v = scale(z, cd);
	w = add(cc, v);
	return (w);
}

/*
**	FIND_NORMAL_VEC function:
**	Finds the normal vector to an item according to the incoming ray
*/

t_vec		find_normal_vec(t_ray r, int id, t_env *e)
{
	t_vec	newstart;
	t_vec	n;
	int		type;
	int		negative;

	negative = 0;
	if (id > e->nbs[ITEM])
	{
		negative = 1;
		id = (id / (e->nbs[ITEM] + 1)) - 1;
	}
	n = newvec(0, 0, 0);
	if (id == EMPTY)
		return (n);
	type = itemtype(id, e);
	newstart = find_newstart(e, r);
	n = find_normal_plus(newstart, r, e, id);
	if (negative)
		n = opposite(n);
	if (!magnitude2(n))
		return (newvec(0, 0, 0));
	n = (dotproduct(r.dir, n) < 0 ? n : opposite(n));
	return (bumpmapping(normalize(n), newstart, find_material(id, e)));
}
