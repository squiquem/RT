/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:04:12 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/19 17:50:58 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	get_quadric_matrix(t_item q)
{
	t_matrix	rot;
	t_matrix	m;

	m.col1.x = q.quadric.x;
	m.col2.y = q.quadric.y;
	m.col3.z = q.quadric.z;
	m.col1.y = 0;
	m.col1.z = 0;
	m.col2.x = 0;
	m.col2.z = 0;
	m.col3.x = 0;
	m.col3.y = 0;
	rot = matrix_rot(q.rotation);
	return (matrix_mult(rot, matrix_mult(m, matrix_transp(rot))));
}

int			hitquadric(t_ray r, t_item q, double *t)
{
	t_vec		sb;
	t_vec		rq;
	t_vec		par;
	t_vec		res;
	t_matrix	m;

	m = get_quadric_matrix(q);
	par = sub(r.start, q.center);
	rq = newvec(r.dir.x * m.col1.x, r.dir.y * m.col2.y, r.dir.z * m.col3.z);
	sb = newvec(par.x * m.col1.x, par.y * m.col2.y, par.z * m.col3.z);
	res.x = dotproduct(r.dir, rq) + 2 * (m.col2.x * r.dir.x * r.dir.y + m.col3.x
			* r.dir.x * r.dir.z + m.col3.y * r.dir.y * r.dir.z);
	res.y = 2 * (dotproduct(rq, par) + m.col2.x * (r.dir.x * par.y + r.dir.y
				* par.x) + m.col3.x * (r.dir.x * par.z + r.dir.z * par.x)
			+ m.col3.y * (r.dir.y * par.z + r.dir.z * par.y));
	res.z = dotproduct(sb, par) + 2 * (m.col2.x * par.x * par.y + m.col3.x
			* par.x * par.z + m.col3.y * par.y * par.z) - q.sizequadric;
	if (res.y * res.y - 4 * res.x * res.z < 0)
		return (0);
	else
		return (calc_discr(res.x, res.y, res.z, t));
}

t_vec		find_quadric_normal(t_vec impct, t_item q)
{
	t_vec		grad;
	t_matrix	m;

	m = get_quadric_matrix(q);
	impct = sub(impct, q.center);
	grad.x = 2 * (impct.x * m.col1.x + m.col2.x * impct.y + m.col3.x * impct.z);
	grad.y = 2 * (impct.y * m.col2.y + m.col1.y * impct.x + m.col3.y * impct.z);
	grad.z = 2 * (impct.z * m.col3.z + m.col1.z * impct.x + m.col2.z * impct.y);
	if (magnitude(grad))
		grad = normalize(grad);
	return (grad);
}
