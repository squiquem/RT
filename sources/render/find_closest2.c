/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/22 19:47:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FIND_CLOSEST_ITEM function:
**	Finds the closest item hit by the ray
*/

int			find_closest_item1(t_ray r, t_env *e, t_vec *newstart)
{
	double	t;
	int		curr;

	curr = get_closest_item(r, e);
	if (curr < 0)
		return (curr);
	t = -1;
	e->hit[e->item[curr].item_type](r, e->item[curr], &t);
	if (curr > -1 && !e->item[curr].isnega)
		*newstart = add(scale(t, r.dir), r.start);
	else if (e->item[curr].isnega)
		curr = check_nega_edges(r, e, newstart, curr);
	return (curr);
}

int			find_closest_item2(t_ray r, t_env *e, t_vec *newstart)
{
	double	t;
	int		curr;
	t_curr	ncurr;

	curr = get_closest_item(r, e);
	if (curr < 0)
		return (curr);
	t = -1;
	e->hit[e->item[curr].item_type](r, e->item[curr], &t);
	if (curr > -1 && !e->item[curr].isnega)
		*newstart = add(scale(t, r.dir), r.start);
	else if (e->item[curr].isnega)
		curr = find_post_nega(r, e, newstart, &ncurr);
	return (curr);
}
