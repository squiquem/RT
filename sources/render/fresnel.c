/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:45:09 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/19 17:38:59 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	REFRACTED_RAY function:
**	Calculates the new ray produced by refraction
*/

t_ray	refracted_ray(t_vec inc, t_vec norm, double n, t_vec newstart)
{
	double	c1;
	double	c2;
	t_ray	r;

	r.start = newstart;
	c1 = -dotproduct(inc, norm);
	if (c1 < 0)
	{
		norm = opposite(norm);
		c1 = -c1;
	}
	c2 = 1 - (n * n) * (1 - (c1 * c1));
	if (c2 < 0)
	{
		r.dir = newvec(0, 0, 0);
		return (r);
	}
	r.dir = normalize(add(scale(n, inc), scale(n * c1 - sqrt(c2), norm)));
	return (r);
}

/*
**	REFLECTED_RAY function:
**	Calculates the new ray produced by reflection
*/

t_ray	reflected_ray(t_vec inc, t_vec norm, t_vec newstart)
{
	double	f;
	t_vec	tmp;
	t_ray	r;

	f = dotproduct(inc, norm);
	tmp = scale(2.0f * f, norm);
	r.dir = normalize(sub(inc, tmp));
	r.start = newstart;
	return (r);
}

/*
**	TRANSPARENT_RAY function:
**	Calculates the new ray from transparency
*/

t_ray	transp_r(t_ray r, t_vec impact)
{
	t_ray	r2;

	r2 = r;
	r2.start = impact;
	return (r2);
}

/*
**	FRESNEL function:
**	Calculates the Fresnel coefficient for the reflection
*/

double	fresnel(t_vec i, t_vec n, double n1, double n2)
{
	double	cosi;
	double	etai;
	double	etat;
	double	sint;
	double	cost;

	cosi = ft_clamp(-1, 1, dotproduct(i, n));
	etai = n1;
	etat = n2;
	if (cosi > 0)
		ft_dswap(&etai, &etat);
	sint = etai / etat * sqrt(ft_max(0.f, 1 - cosi * cosi));
	if (sint >= 1)
		return (1);
	else
	{
		cost = sqrt(ft_max(0.f, 1 - sint * sint));
		cosi = ft_abs(cosi);
		return ((pow(((etat * cosi) - (etai * cost)) / ((etat * cosi)
							+ (etai * cost)), 2) + pow(((etai * cosi)
							- (etat * cost)) / ((etai * cosi)
							+ (etat * cost)), 2)) / 2);
	}
}

/*
**	FIND_NREFR function:
**	Finds the right refraction index for refraction
*/

double	find_nrefr(t_work w, t_mat mat, int item_hit, t_env *e)
{
	double	nrefr;

	if (remove_from_tab(w.id, item_hit, REFRINCL))
		nrefr = find_max_ior(w.id, REFRINCL, e);
	else
		nrefr = ft_max(mat.n, find_max_ior(w.id, REFRINCL, e));
	return (nrefr);
}
