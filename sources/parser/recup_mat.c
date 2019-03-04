/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:14:56 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/08 22:21:13 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			recup_last_mat(t_mat *mat, t_element elem, int i, char *name)
{
	int nb;

	nb = 0;
	if (ft_strcmp(name, "checker") == 0 || ft_strcmp(name, "waves") == 0)
	{
		recup_checker_mat(mat, elem, i, name);
		return (0);
	}
	if (elem.nbr_attr < 7)
		std_err(0);
	recup_value_mat(mat, elem, i);
	recup_value_checker(mat, elem, i);
	if (ft_strcmp(name, "marble") == 0)
		mat[i].type = 3;
	else if (ft_strcmp(name, "perturb") == 0)
		mat[i].type = 4;
	else if (ft_strcmp(name, "wood") == 0)
		mat[i].type = 6;
	else
		std_err(0);
	nb = get_bump(mat, elem, i);
	if (elem.nbr_attr - nb != 7)
		std_err(0);
	return (0);
}

int			recup_texture_mat(t_mat *mat, t_element elem, int i)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 9 || elem.nbr_attr > 11)
		std_err(0);
	mat[i].type = 1;
	recup_value_mat(mat, elem, i);
	recup_value_text(mat, elem, i);
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "pathtext"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].path_text = ft_strdup(elem.attribut[j].content);
	mat[i].tex.center = newvec(0, 0, 0);
	j = get_bump(mat, elem, i);
	if (elem.nbr_attr - j == 9)
		return (0);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "center"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].tex.center = ft_getpos(elem.attribut[j].content);
	return (0);
}

int			recup_uniform_mat(t_mat *mat, t_element elem, int i)
{
	int j;
	int nb;

	j = 0;
	if (elem.nbr_attr < 6 || elem.nbr_attr > 7)
		std_err(0);
	mat[i].type = 0;
	recup_value_mat(mat, elem, i);
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "diffusion"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].diffuse = ft_getcolor(elem.attribut[j].content);
	nb = get_bump(mat, elem, i);
	if (elem.nbr_attr - nb != 6)
		std_err(0);
	return (0);
}

t_mat		*get_mat(t_element elem, t_env *e)
{
	int		i;
	t_mat	*mat;

	i = 0;
	if (elem.nbr_element == 0 || elem.nbr_attr > 0)
		std_err(0);
	if (!(mat = (t_mat*)malloc(sizeof(t_mat) * elem.nbr_element)))
		std_err(0);
	clean_value_mat(mat, elem.nbr_element);
	e->nbs[MAT] = elem.nbr_element;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "uniform") == 0)
			recup_uniform_mat(mat, elem.elem[i], i);
		else if (ft_strcmp(elem.elem[i].object, "texture") == 0)
			recup_texture_mat(mat, elem.elem[i], i);
		else
			recup_last_mat(mat, elem.elem[i], i, elem.elem[i].object);
		if (mat[i].reflection > 100 || mat[i].transparency > 100
				|| mat[i].n > 2000)
			std_err(0);
		i++;
	}
	return (mat);
}

t_mat		*recup_mat(t_env *e, t_element elem)
{
	int		i;
	int		j;
	int		nbr_mat;
	t_mat	*mat;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "material") == 0)
		{
			if (j == 1)
				std_err(0);
			mat = get_mat(elem.elem[i], e);
			nbr_mat = elem.elem[i].nbr_element;
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	return (mat);
}
