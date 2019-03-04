/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_mat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:34:46 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/31 13:10:08 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int			recup_checker_mat(t_mat *mat, t_element elem, int i, char *name)
{
	int nb;

	if (elem.nbr_attr < 9)
		std_err(0);
	recup_value_mat(mat, elem, i);
	recup_value_checker(mat, elem, i);
	if (ft_strcmp(name, "checker") == 0)
	{
		nb = 1;
		mat[i].type = 2;
		recup_value_text(mat, elem, i);
	}
	else
	{
		nb = 0;
		mat[i].type = 5;
		recup_value_text(mat, elem, i);
	}
	nb += get_bump(mat, elem, i);
	if (elem.nbr_attr - nb != 9)
		std_err(0);
	return (0);
}
