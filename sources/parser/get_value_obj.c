/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:29:36 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/27 16:56:49 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			get_center(t_env *e, t_element elem, int i, char *name)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, name))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].center = ft_getpos(elem.attribut[j].content);
	return (0);
}

int			get_radius(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "radius"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].radius = ft_atoi(elem.attribut[j].content);
	if (e->item[i].radius <= 0)
		std_err(0);
	return (0);
}

int			get_material(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "mat"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].mat = ft_atoi(elem.attribut[j].content);
	if (e->item[i].mat < 0 || e->item[i].mat >= nbr_mat)
		std_err(0);
	return (0);
}

int			get_dir(t_env *e, t_element elem, int i, char *name)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, name))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].dir = ft_getpos(elem.attribut[j].content);
	if (e->item[i].dir.x == 0 && e->item[i].dir.y == 0 && e->item[i].dir.z == 0)
		std_err(0);
	e->item[i].dir = normalize(e->item[i].dir);
	return (0);
}

int			get_d(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "d"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].d = ft_atoi(elem.attribut[j].content);
	return (0);
}
