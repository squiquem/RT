/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:44:27 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:53:12 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	APPLY_CHANGE function:
**	Apply changes from user to the material
*/

static void	apply_change(t_env *e)
{
	e->mat[e->itf.item.mat].reflection = e->itf.param[REFLECTION] / 100;
	e->mat[e->itf.item.mat].transparency = e->itf.param[TRANSPARENCY] / 100;
	e->mat[e->itf.item.mat].specvalue = e->itf.param[SPECVALUE];
	e->mat[e->itf.item.mat].specpower = e->itf.param[SPECPOWER];
	e->mat[e->itf.item.mat].n = e->itf.param[N] / 10;
	e->mat[e->itf.item.mat].bump = e->itf.param[BUMP] / 100;
	e->mat[e->itf.item.mat].scale = e->itf.param[SCALE];
}

/*
**	FILL_TYPE, DOUBLE_DIFFUSE_TYPE, APPLY_MAT functions:
** Apply material, color and value changes to the item material
*/

static void	fill_type(t_env *e)
{
	if (e->itf.spec[2].val)
	{
		e->mat[e->itf.item.mat].diffuse2.red =
			(double)e->itf.spec_shade[2].argb[R];
		e->mat[e->itf.item.mat].diffuse2.green =
			(double)e->itf.spec_shade[2].argb[G];
		e->mat[e->itf.item.mat].diffuse2.blue =
			(double)e->itf.spec_shade[2].argb[B];
	}
	if (e->itf.mat.type == CHECKER)
	{
		checker_tex_build(&e->mat[e->itf.item.mat].tex,
				e->mat[e->itf.item.mat].diffuse,
				e->mat[e->itf.item.mat].diffuse2);
		e->mat[e->itf.item.mat].tex.realw = 100;
		e->mat[e->itf.item.mat].tex.realh = 100;
	}
}

static void	double_diffuse_type(t_env *e)
{
	if (e->itf.spec[1].val)
	{
		e->mat[e->itf.item.mat] = e->itf.mat;
		e->mat[e->itf.item.mat].diffuse.red =
			(double)e->itf.spec_shade[1].argb[R];
		e->mat[e->itf.item.mat].diffuse.green =
			(double)e->itf.spec_shade[1].argb[G];
		e->mat[e->itf.item.mat].diffuse.blue =
			(double)e->itf.spec_shade[1].argb[B];
	}
	if (e->itf.mat.type == WAVES)
	{
		waves_tex_build(&e->mat[e->itf.item.mat].tex,
				e->mat[e->itf.item.mat].diffuse);
		e->mat[e->itf.item.mat].tex.realw = 100;
		e->mat[e->itf.item.mat].tex.realh = 100;
	}
	else
		fill_type(e);
	apply_change(e);
	e->mat[e->itf.item.mat].scale = (e->mat[e->itf.item.mat].scale == 0 ? 0.01
			: e->mat[e->itf.item.mat].scale);
}

void		apply_mat(int type, t_env *e)
{
	if (type == UNIFORM)
	{
		if (e->itf.spec[0].val)
		{
			e->mat[e->itf.item.mat] = e->itf.mat;
			e->mat[e->itf.item.mat].diffuse.red =
				(double)e->itf.spec_shade[0].argb[R];
			e->mat[e->itf.item.mat].diffuse.green =
				(double)e->itf.spec_shade[0].argb[G];
			e->mat[e->itf.item.mat].diffuse.blue =
				(double)e->itf.spec_shade[0].argb[B];
		}
		apply_change(e);
	}
	else if (type == CHECKER || type == MARBLE || type == PERTURB
			|| type == WOOD || type == WAVES)
		double_diffuse_type(e);
}

/*
**	APPLY_TEXTURE function:
**	Apply the new texture material to the current item
*/

void		apply_texture(t_env *e)
{
	t_img	img;
	char	*s[5];

	s[0] = "textures/redbrick.xpm";
	s[1] = "textures/bluestone.xpm";
	s[2] = "textures/colorstone.xpm";
	s[3] = "textures/wood.xpm";
	s[4] = NULL;
	if (!(img.img = mlx_xpm_file_to_image(e->mlx, s[e->itf.nb_texture - 1],
					&img.w, &img.h))
			|| !(img.pixel_img = (unsigned char *)mlx_get_data_addr(img.img,
					&img.bpp, &img.s_line, &img.ed)))
		ft_printerror("Error mlx");
	e->mat[e->itf.item.mat] = e->itf.mat;
	e->mat[e->itf.item.mat].tex = img;
	e->mat[e->itf.item.mat].tex.realw = 100;
	e->mat[e->itf.item.mat].tex.realh = 100;
	e->mat[e->itf.item.mat].type = TEXTURE;
	e->mat[e->itf.item.mat].path_text = s[e->itf.nb_texture - 1];
	e->mat[e->itf.item.mat].diffuse.red = 0;
	e->mat[e->itf.item.mat].diffuse.green = 0;
	e->mat[e->itf.item.mat].diffuse.blue = 0;
}
