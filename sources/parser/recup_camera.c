/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:07:51 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/15 17:14:46 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_dirpos(t_element elem, t_env *e)
{
	int i;

	i = 0;
	while (i < elem.nbr_attr && ft_strcmp(elem.attribut[i].name, "pos"))
		i++;
	if (i == elem.nbr_attr)
		std_err(0);
	e->cam->pos = ft_getpos(elem.attribut[i].content);
	i = 0;
	while (i < elem.nbr_attr && ft_strcmp(elem.attribut[i].name, "dir"))
		i++;
	if (i == elem.nbr_attr)
		std_err(0);
	e->cam->dir = ft_getpos(elem.attribut[i].content);
	return (0);
}

int		get_t_r(t_element elem, t_env *e)
{
	int		j;
	int		i;
	t_vec	r;

	i = 0;
	j = 0;
	while (i < elem.nbr_attr && ft_strcmp(elem.attribut[i].name, "translation"))
		i++;
	if (i < elem.nbr_attr)
	{
		e->cam->pos = add(e->cam->pos, ft_getpos(elem.attribut[i].content));
		j++;
	}
	i = 0;
	while (i < elem.nbr_attr && ft_strcmp(elem.attribut[i].name, "rotation"))
		i++;
	if (i < elem.nbr_attr)
	{
		r = ft_getpos(elem.attribut[i].content);
		e->cam->dir = rotate(e->cam->dir, r.x, r.y, r.z);
		j++;
	}
	return (j);
}

int		get_camera(t_element elem, t_env *e)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(e->cam = (t_cam*)malloc(sizeof(t_cam) * 1)))
		std_err(0);
	if (elem.nbr_element != 0)
		std_err(0);
	if (elem.nbr_attr < 2 || elem.nbr_attr > 4)
		std_err(0);
	get_dirpos(elem, e);
	if (elem.nbr_attr > 2)
		j = get_t_r(elem, e);
	if (j + 2 != elem.nbr_attr)
		std_err(0);
	if (e->cam->dir.x == 0 && e->cam->dir.y == 0 && e->cam->dir.z == 0)
		std_err(0);
	return (0);
}

t_env	*recup_camera(t_env *e, t_element elem)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "camera") == 0)
		{
			if (j == 1)
				std_err(0);
			get_camera(elem.elem[i], e);
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	return (e);
}
