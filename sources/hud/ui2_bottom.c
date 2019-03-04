/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:28:53 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 19:54:42 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	Set globals used for every kind of material in tab 2
*/

const int	g_checker_xs = WIN_W / 6 - WIN_W / 8 / 2;
const int	g_marble_xs = 2 * WIN_W / 6 - WIN_W / 8 / 2;
const int	g_perturb_xs = 3 * WIN_W / 6 - WIN_W / 8 / 2;
const int	g_wood_xs = 4 * WIN_W / 6 - WIN_W / 8 / 2;
const int	g_waves_xs = 5 * WIN_W / 6 - WIN_W / 8 / 2;

const int	g_mat_ys = IMG_H + BOTTOM_SPC / 4;

/*
**	UI2_FRAMES function:
**	Draw the confirmation frames for the picked item
*/

static void	ui2_frames(t_rect *r, t_env *e)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		frame(BOTTOM, r[i], DARK_GREY, e);
		if (i + 2 == e->itf.mat.type)
			frame(BOTTOM, r[i], C_GREEN, e);
	}
}

/*
**	SET_FRAMES function:
**	Set the frames to draw for tabe 2
*/

static void	set_frames(t_rect *r)
{
	r[0] = init_rect(g_checker_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[1] = init_rect(g_marble_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[2] = init_rect(g_perturb_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[3] = init_rect(g_waves_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[4] = init_rect(g_wood_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
}

/*
**	UI2_BOTTOM_XPM function:
**	Insert all xpm images for tab 2
*/

static void	ui2_bottom_xpm(t_env *e)
{
	t_pix	pt;

	pt = init_point(g_checker_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-damier.xpm", e);
	pt = init_point(g_marble_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-marbre.xpm", e);
	pt = init_point(g_perturb_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-perlin.xpm", e);
	pt = init_point(g_wood_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-wood.xpm", e);
	pt = init_point(g_waves_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-waves.xpm", e);
}

/*
**	UI2_BOTTOM function:
**	Centralize all the functions calls for tab 2 bottom
*/

void		ui2_bottom(t_env *e)
{
	t_rect	rect[5];

	ui2_bottom_xpm(e);
	set_frames(rect);
	ui2_frames(rect, e);
}
