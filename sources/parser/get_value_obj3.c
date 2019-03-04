/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_obj3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:17:57 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/08 16:28:51 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		get_isnega(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "isneg"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].isnega = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].isnega < 0 || e->item[i].isnega > 1)
		std_err(0);
	return (0);
}

int		get_param(t_env *e, t_element elem, int i, char *name)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, name))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].quadric = ft_getpos(elem.attribut[j].content);
	return (0);
}

int		get_sizequadric(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "sizequadric"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].sizequadric = ft_atoi(elem.attribut[j].content);
	return (0);
}

int		recup_tr(t_env *e, t_element elem, int i)
{
	int j;
	int f;

	j = 0;
	f = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "rotation"))
		j++;
	if (j != elem.nbr_attr)
	{
		e->item[i].rotation = ft_getpos(elem.attribut[j].content);
		f++;
	}
	if (f == 0)
		std_err(0);
	return (f);
}
