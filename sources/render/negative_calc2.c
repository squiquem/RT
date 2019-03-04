/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_calc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:22:34 by sderet            #+#    #+#             */
/*   Updated: 2019/02/22 11:22:20 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			free_nega(int ret, int *hit_items, int *items_mod)
{
	free(hit_items);
	free(items_mod);
	return (ret);
}

void		init_all_nega(t_hititem *i)
{
	i->hit_items = (int*)malloc(sizeof(int) * (i->item_count + 1));
	i->items_mod = (int*)malloc(sizeof(int) * (i->item_count + 1));
	if (!(i->items_mod) || !(i->hit_items))
		ft_printerror("Error malloc");
	init_int_tab(i->hit_items, i->item_count, 0);
	init_int_tab(i->items_mod, i->item_count, -1);
}

void		negative_advance(t_env *e, int last_hit, t_ray *r)
{
	double t;

	t = -1;
	e->hit[e->item[last_hit].item_type](*r, e->item[last_hit], &t);
	r->start = add(scale(t, r->dir), r->start);
}

int			count_items(t_ray r, t_env *e)
{
	double	t;
	int		i;
	int		count;

	if (!magnitude2(r.dir))
		return (-1);
	i = -1;
	count = 0;
	while (++i < e->nbs[ITEM])
	{
		t = -1;
		if (e->hit[e->item[i].item_type](r, e->item[i], &t) > 0)
			count++;
	}
	return (count);
}

int			get_closest_item(t_ray r, t_env *e)
{
	double	t;
	double	before;
	int		i;
	int		curr;

	if (!magnitude2(r.dir))
		return (-1);
	t = -1;
	before = -1;
	curr = -1;
	i = -1;
	while (++i < e->nbs[ITEM])
	{
		if (e->hit[e->item[i].item_type](r, e->item[i], &t)
			&& ((before == -1 || t < before) && t > 0.001f))
		{
			before = t;
			curr = i;
		}
	}
	return (curr);
}
