/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:24:12 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/22 14:42:10 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	CALC_H1 function:
**	Intermediate function for hitting calculations
*/

t_vec	calc_h1(t_ray r, t_vec dir)
{
	t_vec	h1;
	t_vec	tmp;
	double	f;

	f = dotproduct(r.dir, dir);
	tmp = scale(f, dir);
	h1 = sub(r.dir, tmp);
	return (h1);
}

/*
**	CALC_H2 function:
**	Intermediate function for hitting calculations
*/

t_vec	calc_h2(t_vec dist, t_vec dir)
{
	t_vec	h2;
	double	f;
	t_vec	tmp;

	f = dotproduct(dist, dir);
	tmp = scale(f, dir);
	h2 = sub(dist, tmp);
	return (h2);
}
