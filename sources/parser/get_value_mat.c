/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:08:12 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/26 09:35:03 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int		recup_value_checker(t_mat *mat, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "diffusion"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].diffuse = ft_getcolor(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name,
				"diffusionbis"))
		j++;
	if (j == elem.nbr_attr && ft_strcmp(elem.object, "waves"))
		std_err(0);
	else if (ft_strcmp(elem.object, "waves") == 0 && j != elem.nbr_attr)
		std_err(0);
	else if (ft_strcmp(elem.object, "waves"))
		mat[i].diffuse2 = ft_getcolor(elem.attribut[j].content);
	return (0);
}

int		recup_value_text(t_mat *mat, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "angle"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].tex.angle = ft_posatoi(elem.attribut[j].content);
	if (mat[i].tex.angle > 360)
		std_err(0);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "width"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].tex.realw = ft_posatoi(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "height"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].tex.realh = ft_posatoi(elem.attribut[j].content);
	if (mat[i].tex.realh <= 0 || mat[i].tex.realw <= 0)
		std_err(0);
	return (0);
}

int		get_bump(t_mat *mat, t_element elem, int i)
{
	int j;
	int nb;

	nb = 0;
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "bump"))
		j++;
	if (j != elem.nbr_attr)
	{
		mat[i].bump = ft_posatoi(elem.attribut[j].content) / 100;
		if (mat[i].bump > 0.99)
			std_err(0);
		nb++;
	}
	if (mat[i].type <= 2 || mat[i].type == 5)
		return (nb);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "scale"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].scale = (double)atoi(elem.attribut[j].content) / 100;
	nb++;
	return (nb);
}

int		recup_value_mat2(t_mat *mat, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "specpower"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].specpower = ft_posatoi(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "n"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].n = ft_posatoi(elem.attribut[j].content) / 1000;
	return (0);
}

int		recup_value_mat(t_mat *mat, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "t"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].transparency = ft_posatoi(elem.attribut[j].content) / 100;
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "r"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].reflection = ft_posatoi(elem.attribut[j].content) / 100;
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "specvalue"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	mat[i].specvalue = ft_posatoi(elem.attribut[j].content) / 100;
	recup_value_mat2(mat, elem, i);
	return (0);
}
