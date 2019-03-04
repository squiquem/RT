/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:18:27 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/25 18:31:59 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int			free_checker_waves(t_mat *mat, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (mat[i].type == 1)
			free(mat[i].path_text);
		i++;
	}
	return (0);
}

int			cut_struct(t_mat *mat, int i, t_env *e, int j)
{
	e->mat[j] = mat[i];
	if (mat[i].type == 2)
		checker_tex_build(&e->mat[j].tex, e->mat[j].diffuse,
				e->mat[j].diffuse2);
	if (mat[i].type == 5)
		waves_tex_build(&e->mat[j].tex, e->mat[j].diffuse);
	if (mat[i].type == 1)
		if (!(e->mat[j].path_text = ft_strdup(mat[i].path_text)))
			ft_printerror("Error malloc");
	return (0);
}

int			soloobject(t_env *e, t_element elem, int i, t_mat *mat)
{
	if (ft_strcmp(elem.object, "sphere") == 0)
		get_sphere(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "plane") == 0)
		get_plane(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "icyl") == 0)
		get_lcyl(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "icone") == 0)
		get_lcone(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "disk") == 0)
		get_disk(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "fcyl") == 0)
		get_fcyl(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "fcone") == 0)
		get_fcone(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "box") == 0)
		get_box(e, elem, i, e->nbs[MAT]);
	else if (ft_strcmp(elem.object, "quadric") == 0)
		get_quadric(e, elem, i, e->nbs[MAT]);
	else
		std_err(0);
	cut_struct(mat, e->item[i].mat, e, i);
	e->item[i].mat = i;
	return (0);
}

int			get_objects(t_element elem, t_env *e, t_mat *mat)
{
	int i;

	i = 0;
	if (elem.nbr_element == 0)
		std_err(0);
	if (!(e->item = (t_item*)malloc(sizeof(t_item) * elem.nbr_element)))
		std_err(0);
	if (!(e->mat = (t_mat*)malloc(sizeof(t_mat) * elem.nbr_element)))
		std_err(0);
	e->nbs[ITEM] = elem.nbr_element;
	while (i < elem.nbr_element)
	{
		e->item[i].isnega = 0;
		soloobject(e, elem.elem[i], i, mat);
		i++;
	}
	return (0);
}

t_env		*recup_object(t_env *e, t_element elem, t_mat *mat)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "objects") == 0)
		{
			if (j == 1 || elem.elem[i].nbr_attr > 0)
				std_err(0);
			get_objects(elem.elem[i], e, mat);
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	free_checker_waves(mat, e->nbs[MAT]);
	free(mat);
	e->nbs[MAT] = e->nbs[ITEM];
	return (e);
}
