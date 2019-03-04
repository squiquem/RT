/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:02:34 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/19 21:55:23 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	CROSSPRODUCT function:
**	Returns the crossproduct of 2 vectors
*/

t_vec	crossproduct(t_vec u, t_vec v)
{
	t_vec	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

/*
**	DOTPRODUCT function:
**	Returns the dotproduct of 2 vectors
*/

double	dotproduct(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

/*
**	SCALE function:
**	Returns the product of a vector by a scalar
*/

t_vec	scale(double k, t_vec u)
{
	t_vec	w;

	w.x = u.x * k;
	w.y = u.y * k;
	w.z = u.z * k;
	return (w);
}

/*
**	OPPOSITE function:
**	Returns the opposite vector
*/

t_vec	opposite(t_vec u)
{
	return (sub(newvec(0, 0, 0), u));
}

/*
**	NEWVEC function:
**	Returns a new vector (x, y, z)
*/

t_vec	newvec(double x, double y, double z)
{
	t_vec	u;

	u.x = x;
	u.y = y;
	u.z = z;
	return (u);
}
