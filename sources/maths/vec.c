/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:02:34 by squiquem          #+#    #+#             */
/*   Updated: 2019/01/24 14:58:25 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	MAGNITUDE2 function:
**	Calculates the squared magnitude of a vector
*/

double	magnitude2(t_vec v)
{
	double	x;

	x = dotproduct(v, v);
	return (x);
}

/*
**	MAGNITUDE function:
**	Returns the magnitude of a vector
*/

double	magnitude(t_vec u)
{
	return (sqrt(magnitude2(u)));
}

/*
**	NORMALIZE function:
**	Normalizes a vector if its magnitude != 0
*/

t_vec	normalize(t_vec v)
{
	t_vec	uv;
	double	tmp;
	double	tmp2;

	tmp2 = magnitude2(v);
	if (!tmp2)
		return (newvec(0, 0, 0));
	tmp = 1.0f / sqrt(tmp2);
	uv = scale(tmp, v);
	return (uv);
}

/*
**	ADD function:
**	Returns the sum of 2 vectors
*/

t_vec	add(t_vec u, t_vec v)
{
	t_vec	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

/*
**	SUB function:
**	Returns the difference of 2 vectors
*/

t_vec	sub(t_vec u, t_vec v)
{
	t_vec	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}
