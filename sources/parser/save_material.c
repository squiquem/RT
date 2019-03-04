/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:33:46 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/26 09:13:48 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	texture_mat(int fd, t_mat mat)
{
	if (mat.type == TEXTURE)
	{
		ft_putstr_fd(" pathtext=\"", fd);
		ft_putstr_fd(mat.path_text, fd);
		ft_putstr_fd("\"", fd);
	}
	else
		save_color(fd, " diffusion=\"", mat.diffuse);
	if (mat.type == CHECKER)
		save_color(fd, " diffusionbis=\"", mat.diffuse2);
	save_name_val(fd, " angle=\"", mat.tex.angle);
	save_name_val(fd, " width=\"", mat.tex.realw);
	save_name_val(fd, " height=\"", mat.tex.realh);
}

static void	type_mat(int fd, int type)
{
	if (type == UNIFORM)
		ft_putstr_fd("\t\t<uniform", fd);
	else if (type == TEXTURE)
		ft_putstr_fd("\t\t<texture", fd);
	else if (type == CHECKER)
		ft_putstr_fd("\t\t<checker", fd);
	else if (type == MARBLE)
		ft_putstr_fd("\t\t<marble", fd);
	else if (type == PERTURB)
		ft_putstr_fd("\t\t<perturb", fd);
	else if (type == WAVES)
		ft_putstr_fd("\t\t<waves", fd);
	else if (type == WOOD)
		ft_putstr_fd("\t\t<wood", fd);
}

/*
**	SAVE_MATERIAL function:
**	Save the materials settings in the save scene file
*/

void		save_material(int fd, int nbmat, t_mat *m)
{
	int		i;

	ft_putendl_fd("\t<material>", fd);
	i = -1;
	while (++i < nbmat)
	{
		type_mat(fd, m[i].type);
		if (m[i].type == TEXTURE || m[i].type == WAVES || m[i].type == CHECKER)
			texture_mat(fd, m[i]);
		else
			save_color(fd, " diffusion=\"", m[i].diffuse);
		if (!(m[i].type <= CHECKER || m[i].type == WAVES))
			save_color(fd, " diffusionbis=\"", m[i].diffuse2);
		save_name_val(fd, " r=\"", m[i].reflection * 100);
		save_name_val(fd, " t=\"", m[i].transparency * 100);
		save_name_val(fd, " specvalue=\"", m[i].specvalue * 100);
		save_name_val(fd, " specpower=\"", m[i].specpower);
		save_name_val(fd, " n=\"", m[i].n * 1000);
		if (m[i].type == WOOD || m[i].type == MARBLE || m[i].type == PERTURB)
			save_name_val(fd, " scale=\"", m[i].scale * 100);
		if (m[i].bump > 0)
			save_name_val(fd, " bump=\"", m[i].bump * 100);
		ft_putendl_fd("/>", fd);
	}
	ft_putendl_fd("\t</material>", fd);
}
