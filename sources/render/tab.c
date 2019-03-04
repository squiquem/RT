/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:14:41 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/12 00:38:25 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	REFR_ENTER_OR_EXIT function:
**	Modifies work structure w when entering (k==1) or exiting (k==0) a
**	refractive item
*/

void	refr_enter_or_exit(t_work *w, int id, int k, t_env *e)
{
	double	m;
	double	n;

	if (!k)
		remove_from_tab(w->id, id, REFRINCL);
	n = e->mat[e->item[id].mat].n;
	m = find_max_ior(w->id, REFRINCL, e);
	if (k)
	{
		add_to_tab(w->id, id, REFRINCL);
		if (n > m)
			w->n = n;
	}
	else
		w->n = (m == -1) ? 1.0 : m;
}

/*
**	IS_IN_TAB function:
**	Returns the position of id if it is in tab, -1 else
*/

int		position_in_tab(int *tab, int id, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] == id)
			return (i);
	}
	return (-1);
}

/*
**	FIND_MAX function:
**	Finds maximum value in an int table
*/

double	find_max_ior(int *tab, int size, t_env *e)
{
	int		i;
	double	res;
	double	n;

	i = -1;
	res = 1;
	while (++i < size)
	{
		if (tab[i] == -1)
			continue ;
		n = e->mat[e->item[tab[i]].mat].n;
		if (n > res)
			res = n;
	}
	return (res);
}

/*
**	ADD_TO_TAB function:
**	Adds id to an int table
**	Returns 0 if table is full, else 1
*/

int		add_to_tab(int *tab, int id, int size)
{
	int	i;

	i = 0;
	while (tab[i] != -1 && i < size)
		++i;
	if (i != size)
	{
		tab[i] = id;
		return (1);
	}
	return (0);
}

/*
**	REMOVE_FROM_TAB function:
**	Removes id from an int table and returns 1
**	Else returns 0
*/

int		remove_from_tab(int *tab, int id, int size)
{
	int	i;

	i = position_in_tab(tab, id, size);
	if (i == -1)
		return (0);
	else
	{
		tab[i] = -1;
		return (1);
	}
}
