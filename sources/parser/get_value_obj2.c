/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_obj2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:24:23 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/12 14:35:02 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		get_angle(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "angle"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].angle = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].angle == 0 || e->item[i].angle >= 70)
		std_err(0);
	return (0);
}

int		get_height(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "height"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].height = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].height == 0)
		std_err(0);
	return (0);
}

int		get_translation(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "translation"))
		j++;
	if (j == elem.nbr_attr)
		return (0);
	e->item[i].center = add(e->item[i].center,\
			ft_getpos(elem.attribut[j].content));
	return (1);
}

int		get_rotation(t_env *e, t_element elem, int i)
{
	int		j;
	t_vec	r;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "rotation"))
		j++;
	if (j == elem.nbr_attr)
		return (0);
	r = ft_getpos(elem.attribut[j].content);
	e->item[i].dir = rotate(e->item[i].dir, r.x, r.y, r.z);
	return (1);
}

int		get_end(t_env *e, t_element elem, int i, char *name)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, name))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].end = ft_getpos(elem.attribut[j].content);
	return (0);
}
