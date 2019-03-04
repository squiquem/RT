/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:19:51 by sderet            #+#    #+#             */
/*   Updated: 2019/02/20 15:39:32 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			is_empty(int *hit, int count, int *mod, t_env *e)
{
	int a;
	int	b;

	a = 0;
	b = 0;
	while (a < count && mod[a] != -1)
	{
		if (hit[a] % 2 != 0 && e->item[mod[a]].isnega == 0)
			b++;
		a++;
	}
	return (b);
}

int			get_hits(int *hit, int *mod, int last, int count)
{
	int a;

	a = 0;
	while (mod[a] != last && a < count)
		a++;
	return (hit[a]);
}

void		hit_mod(int *mod, int nb, int *hit, t_env *e)
{
	int a;

	if (e->item[nb].item_type == DISK || e->item[nb].item_type == PLANE)
		return ;
	a = 0;
	while (mod[a] != -1 && mod[a] != nb)
		a++;
	mod[a] = nb;
	hit[a]++;
}

void		init_int_tab(int *tab, int size, int value)
{
	int a;

	a = 0;
	while (a < size)
	{
		tab[a] = value;
		a++;
	}
}

int			got_out(int count, int *nb_hit, int *mod, t_env *e)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a < count && mod[a] > -1)
	{
		if (e->item[mod[a]].isnega == 1 && nb_hit[a] % 2 != 0)
			b++;
		a++;
	}
	return (b);
}
