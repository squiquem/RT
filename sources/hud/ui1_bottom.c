/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:50:52 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/26 14:22:36 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	Set globals used for filters, textures and uniform material for an easier
**	reading of the code
*/

const int	g_filter1_xs = WIN_W / 5 / 4;
const int	g_filter2_xs = WIN_W / 5 + WIN_W / 5 / 4;
const int	g_filter3_xs = 2 * WIN_W / 5 + WIN_W / 5 / 4;

const int	g_filter1_ys = IMG_H + BOTTOM_SPC / 8;
const int	g_filter2_ys = IMG_H + 3 * BOTTOM_SPC / 5;

const int	g_text1_xs = 3 * WIN_W / 5 + WIN_W / 5 / 10;
const int	g_text1_xe = g_text1_xs + 64;
const int	g_text1_ys = IMG_H + 20;
const int	g_text1_ye = IMG_H + 84;

const int	g_text2_xs = 3 * WIN_W / 5 + WIN_W / 5 / 10 * 6;
const int	g_text2_xe = g_text2_xs + 64;
const int	g_text2_ys = IMG_H + BOTTOM_SPC / 2 + 20;
const int	g_text2_ye = IMG_H + BOTTOM_SPC / 2 + 84;

const int	g_unif_xs = 4 * WIN_W / 5 + WIN_W / 5 / 6 - 7;
const int	g_unif_xe = 4 * WIN_W / 5 + WIN_W / 5 / 6 + 133;
const int	g_unif_ys = IMG_H + BOTTOM_SPC / 8;
const int	g_unif_ye = IMG_H + BOTTOM_SPC / 8 + 2 * MARGE;

/*
**	TEXTURE_FRAME function:
**	Draw frame for the texture of a picked item
*/

static void	texture_frame(t_rect *r, t_env *e)
{
	if (e->itf.nb_texture == 1)
		frame(BOTTOM, r[6], C_GREEN, e);
	else if (e->itf.nb_texture == 2)
		frame(BOTTOM, r[7], C_GREEN, e);
	else if (e->itf.nb_texture == 3)
		frame(BOTTOM, r[8], C_GREEN, e);
	else if (e->itf.nb_texture == 4)
		frame(BOTTOM, r[9], C_GREEN, e);
	if (e->itf.mat.type == UNIFORM && e->itf.pick.button > -1)
		frame(BOTTOM, r[10], C_GREEN, e);
}

/*
**	SET_FRAMES function:
**	Set table of frames to draw for every xpm image on the tab 1
*/

static void	set_frames(t_rect *r)
{
	r[0] = init_rect(0, 0, 0, 0);
	r[1] = init_rect(g_filter2_xs, g_filter1_ys - IMG_H, 100, 60);
	r[2] = init_rect(g_filter3_xs, g_filter1_ys - IMG_H, 100, 60);
	r[3] = init_rect(g_filter2_xs, g_filter2_ys - IMG_H, 100, 60);
	r[4] = init_rect(g_filter1_xs, g_filter2_ys - IMG_H, 100, 60);
	r[5] = init_rect(g_filter3_xs, g_filter2_ys - IMG_H, 100, 60);
	r[6] = init_rect(g_text1_xs, g_text1_ys - IMG_H, g_text1_xe - g_text1_xs,
			(g_text1_ye - IMG_H) - (g_text1_ys - IMG_H));
	r[7] = init_rect(g_text2_xs, g_text1_ys - IMG_H, g_text2_xe - g_text2_xs,
			(g_text1_ye - IMG_H) - (g_text1_ys - IMG_H));
	r[8] = init_rect(g_text1_xs, g_text2_ys - IMG_H, g_text1_xe - g_text1_xs,
			(g_text2_ye - IMG_H) - (g_text2_ys - IMG_H));
	r[9] = init_rect(g_text2_xs, g_text2_ys - IMG_H, g_text2_xe - g_text2_xs,
			(g_text2_ye - IMG_H) - (g_text2_ys - IMG_H));
	r[10] = init_rect(g_unif_xs, g_unif_ys - IMG_H, g_unif_xe - g_unif_xs,
			(g_unif_ye - IMG_H) - (g_unif_ys - IMG_H));
}

/*
**	UI1_FRAME function
**	Draw the frame for selecting textures or filters
*/

static void	ui1_frame(t_rect *r, t_env *e)
{
	int i;

	i = 0;
	while (++i < 5)
	{
		frame(BOTTOM, r[i], DARK_GREY, e);
		if (i == e->filter)
			frame(BOTTOM, r[i], C_GREEN, e);
	}
	if (e->cartoon)
		frame(BOTTOM, r[i], C_GREEN, e);
	else
		frame(BOTTOM, r[i], DARK_GREY, e);
}

/*
**	UI1_BOTTOM_XPM function:
**	Insert all the xpm image for the menuing in tab 1
*/

static void	ui1_bottom_xpm(t_env *e)
{
	t_pix	pt;

	pt = init_point(g_filter2_xs, g_filter1_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-sepia.xpm", e);
	pt = init_point(g_filter3_xs, g_filter1_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-greyscale.xpm", e);
	pt = init_point(g_filter1_xs, g_filter2_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-saturate.xpm", e);
	pt = init_point(g_filter2_xs, g_filter2_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-reverse.xpm", e);
	pt = init_point(g_filter3_xs, g_filter2_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-cartoon.xpm", e);
	pt = init_point(g_text1_xs, g_text1_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "textures/redbrick.xpm", e);
	pt = init_point(g_text2_xs, g_text1_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "textures/bluestone.xpm", e);
	pt = init_point(g_text1_xs, g_text2_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "textures/colorstone.xpm", e);
	pt = init_point(g_text2_xs, g_text2_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "textures/wood.xpm", e);
}

/*
**	UI1_BOTTOM function:
**	Centralize the functions calls for the bottom of the tab 1
*/

void		ui1_bottom(t_env *e)
{
	t_rect	rect[11];

	ui1_bottom_xpm(e);
	rect[0] = init_rect(4 * (WIN_W / 5) + (WIN_W / 5) / 6 - 7,
			(BOTTOM_SPC) / 8, 140, 30);
	draw_rect(BOTTOM, rect[0], LIGHT_GREY, e);
	rect[0] = init_rect(4 * (WIN_W / 5) + (WIN_W / 7) / 4 - 14,
			5 * (BOTTOM_SPC) / 8 + 9, 159, 50);
	draw_rect(BOTTOM, rect[0], LIGHT_GREY, e);
	ui1_bottom_strokes(e);
	set_frames(rect);
	ui1_frame(rect, e);
	texture_frame(rect, e);
}
