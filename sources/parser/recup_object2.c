/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:13:14 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/11 12:14:34 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		get_sphere(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 4 || elem.nbr_attr > 5)
		std_err(0);
	e->item[i].item_type = 1;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].isnega = 0;
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_center(e, elem, i, "center");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_isnega(e, elem, i);
	if (elem.nbr_attr == 5)
	{
		j = get_translation(e, elem, i);
		if (j == 0)
			std_err(0);
	}
	return (0);
}

int		get_plane(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 3 || elem.nbr_attr > 5)
		std_err(0);
	e->item[i].item_type = 2;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].isnega = 0;
	e->item[i].angle = 0;
	get_dir(e, elem, i, "normale");
	get_d(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	if (elem.nbr_attr > 3)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 3 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_lcyl(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 5 || elem.nbr_attr > 7)
		std_err(0);
	e->item[i].item_type = 4;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_isnega(e, elem, i);
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	if (elem.nbr_attr > 5)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 5 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_lcone(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 5 || elem.nbr_attr > 7)
		std_err(0);
	e->item[i].item_type = 3;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_isnega(e, elem, i);
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_angle(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	if (elem.nbr_attr > 5)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 5 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_disk(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 4 || elem.nbr_attr > 6)
		std_err(0);
	e->item[i].item_type = 5;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].isnega = 0;
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	if (elem.nbr_attr > 4)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 4 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}
