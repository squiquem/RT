/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_to_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/22 11:32:37 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	is_not_mat_n(t_resolve res, t_env *e)
{
	return (add_3colors(get_light_value(res.w, res.hit, res.mat, e),
				multp_color(ft_resolve(e, newwork(res.w,
							reflected_ray(res.w.r.dir, res.w.n_vec,
								res.hit), 0, e), res.lvl + 1),
					res.mat.reflection), multp_color(ft_resolve(e,
							newwork(res.w, transp_r(res.w.r, res.hit),
								0, e), res.lvl + 1),
						res.mat.transparency)));
}

static t_color	is_mat_n(t_resolve res, t_env *e)
{
	return (add_3colors(get_light_value(res.w, res.hit, res.mat, e),
				multp_color(ft_resolve(e, newwork(res.w,
							refracted_ray(res.w.r.dir, res.w.n_vec,
								res.w.n / res.nrefr, res.hit), 1, e),
						res.lvl + 1), 1 - fresnel(res.w.r.dir, res.w.n_vec,
							res.w.n, res.nrefr)),
				multp_color(ft_resolve(e, newwork(res.w,
							reflected_ray(res.w.r.dir, res.w.n_vec, res.hit),
							0, e), res.lvl + 1),
					fresnel(res.w.r.dir, res.w.n_vec, res.w.n, res.nrefr))));
}

/*
**	FT_RESOLVE function:
**	Test for tree of rays
*/

t_color			ft_resolve(t_env *e, t_work w, int lvl)
{
	t_resolve	res;

	res.w = w;
	res.lvl = lvl;
	res.w.item_hit = find_closest_item1(res.w.r, e, &res.hit);
	if (res.w.item_hit == EMPTY || lvl > e->lvl)
		return (add_2colors(lens_flaring(res.w.r, e), e->backgroundcolor));
	res.mat = find_material(res.w.item_hit % (e->nbs[ITEM] + 1), e);
	res.nrefr = find_nrefr(res.w, res.mat, res.w.item_hit % (e->nbs[ITEM] + 1),
			e);
	res.w.n_vec = find_normal_vec(res.w.r, res.w.item_hit, e);
	res.w.item_hit %= (e->nbs[ITEM] + 1);
	if (res.mat.n)
		return (is_mat_n(res, e));
	else if (!res.mat.n && (res.mat.reflection || res.mat.transparency))
		return (is_not_mat_n(res, e));
	else
		return (get_light_value(res.w, res.hit, res.mat, e));
}

/*
**	NEWWORK function:
**	Creation of a new work structure (for refraction and reflection)
*/

t_work			newwork(t_work oldwork, t_ray newray, int refr, t_env *e)
{
	t_work		w;
	int			itemstart;
	int			itemend;
	t_mat		mat;
	t_vec		newstart;

	w = oldwork;
	w.r = newray;
	itemstart = find_closest_item1(oldwork.r, e, &newstart);
	mat = find_material(itemstart, e);
	itemend = find_closest_item1(newray, e, &newstart);
	w.n_vec = find_normal_vec(newray, itemend, e);
	itemend %= (e->nbs[ITEM] + 1);
	itemstart %= (e->nbs[ITEM] + 1);
	if (refr)
	{
		if (itemtype(itemstart, e) != 2 && itemtype(itemstart, e) != 5
				&& position_in_tab(w.id, itemstart, REFRINCL) != -1)
			refr_enter_or_exit(&w, itemstart, 0, e);
		else
			refr_enter_or_exit(&w, itemstart, 1, e);
	}
	w.coef = oldwork.coef * mat.reflection;
	return (w);
}

/*
**	ITEMTYPE function:
**	Finds the item type from the item id
*/

int				itemtype(int id, t_env *e)
{
	return (e->item[id].item_type);
}
