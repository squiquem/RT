/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:12:13 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/10 15:34:46 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

void		clean_texture_value(t_mat *mat, int i)
{
	mat[i].tex.bpp = 0;
	mat[i].tex.s_line = 0;
	mat[i].tex.ed = 0;
	mat[i].tex.w = 0;
	mat[i].tex.h = 0;
	mat[i].tex.realw = 0;
	mat[i].tex.realh = 0;
	mat[i].tex.angle = 0;
	mat[i].tex.center.x = 0;
	mat[i].tex.center.y = 0;
	mat[i].tex.center.z = 0;
	mat[i].tex.direction.x = 0;
	mat[i].tex.direction.y = 0;
	mat[i].tex.direction.z = 0;
}

void		clean_value_mat(t_mat *mat, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		mat[i].type = 0;
		mat[i].path_text = NULL;
		mat[i].reflection = 0;
		mat[i].transparency = 0;
		mat[i].specvalue = 0;
		mat[i].specpower = 0;
		mat[i].n = 0;
		mat[i].bump = 0;
		mat[i].diffuse.red = 0;
		mat[i].diffuse.green = 0;
		mat[i].diffuse.blue = 0;
		mat[i].diffuse2.red = 0;
		mat[i].diffuse2.green = 0;
		mat[i].diffuse2.blue = 0;
		mat[i].scale = 0;
		clean_texture_value(mat, i);
		i++;
	}
}
