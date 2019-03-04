/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:42:21 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/20 15:06:09 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	matrix_rotx(double angle)
{
	t_matrix	a;

	angle = angle * M_PI / 180;
	a.col1 = newvec(1, 0, 0);
	a.col2 = newvec(0, cos(angle), sin(angle));
	a.col3 = newvec(0, -sin(angle), cos(angle));
	return (a);
}

t_matrix	matrix_roty(double angle)
{
	t_matrix	a;

	angle = angle * M_PI / 180;
	a.col2 = newvec(0, 1, 0);
	a.col1 = newvec(cos(angle), 0, -sin(angle));
	a.col3 = newvec(sin(angle), 0, cos(angle));
	return (a);
}

t_matrix	matrix_rotz(double angle)
{
	t_matrix	a;

	angle = angle * M_PI / 180;
	a.col3 = newvec(0, 0, 1);
	a.col2 = newvec(-sin(angle), cos(angle), 0);
	a.col1 = newvec(cos(angle), sin(angle), 0);
	return (a);
}

t_matrix	matrix_rot(t_vec angle)
{
	t_matrix	m;

	m = matrix_mult(matrix_rotx(angle.x), matrix_mult(matrix_roty(angle.y),
				matrix_rotz(angle.z)));
	return (m);
}
