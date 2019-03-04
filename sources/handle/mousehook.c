/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:29:16 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:25:01 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"

/*
**	Set the static globals used to select the tabs
*/

static const int	g_tab1_xe = IMG_W + RIGHT_SPC / 3;
static const int	g_tab_ye = 2 * MARGE;
static const int	g_tab2_xs = g_tab1_xe + 1;
static const int	g_tab2_xe = IMG_W + 2 * (RIGHT_SPC / 3) + 1;
static const int	g_tab3_xs = g_tab2_xe + 1;

/*
**	UI_CHECKER function:
**	Check if the user click in 1 of the 3 tab zones
*/

static void	ui_checker(t_mouse m, t_env *e)
{
	t_pix	pt;

	if (e->itf.onglet == 1)
	{
		pt = init_point(M_IMG_H + (CIRCLE) / 2, g_shad_ys);
		ui_spectrum(0, pt, m, e);
		pt.x = g_shad_ye;
		ui_shade(0, pt, m, e);
	}
	if (e->itf.onglet == 2)
	{
		pt.x = 3 * MARGE + (RIGHT_SPC) / 2 - MARGE;
		pt.y = 3 * MARGE + RIGHT_SPC - MARGE;
		ui_spectrum(1, pt, m, e);
		pt.x = pt.y + MARGE;
		ui_shade(1, pt, m, e);
		pt = init_point(M_IMG_H + 35 + (RIGHT_SPC) / 2 - MARGE
				, M_IMG_H + 35 + RIGHT_SPC - MARGE);
		ui_spectrum(2, pt, m, e);
		pt.x = pt.y + MARGE;
		ui_shade(2, pt, m, e);
	}
	pick_item(m, e);
	ui_zones(e->itf.onglet, m, e);
}

/*
**	MOUSEPRESS function:
**	Handle the pressed button, mouse pointer position at this moment, called by
**	the mlx_hook function
*/

int			mousepress(int button, int x, int y, t_env *e)
{
	t_mouse	mouse;

	mouse.button = button;
	mouse.x = x;
	mouse.y = y;
	if (x >= IMG_W && x <= g_tab1_xe && y >= 0 && y <= g_tab_ye)
		e->itf.onglet = 1;
	else if (x >= g_tab2_xs && x <= g_tab2_xe && y >= 0 && y <= g_tab_ye)
		e->itf.onglet = 2;
	else if (x >= g_tab3_xs && x <= WIN_W && y >= 0 && y <= g_tab_ye)
		e->itf.onglet = 3;
	ui_checker(mouse, e);
	hud(e);
	return (0);
}

/*
**	MOURELEASE function:
**	Replace de mouse button state at 0, useful for long click needed features,
**	called by the mlx_hook function
*/

int			mouserelease(int button, int x, int y, t_env *e)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		e->itf.shade[i].button = 0;
		e->itf.spectrum[i].button = 0;
	}
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

/*
**	MOUSEMOVE and UPDATE_MOUSE functions:
**	Save the mouse pointer position from the last movement and update its
**	position with the mouse motion, called by the mlx_hook function
*/

static void	update_mouse(int nb, t_pix pt, t_pix coord, t_env *e)
{
	t_mouse	mouse;

	if (e->itf.shade[nb].button == L_CLICK)
	{
		if (pt.x < IMG_W + MARGE)
			e->itf.shade[nb].x = MARGE;
		else if (pt.x > WIN_W - MARGE)
			e->itf.shade[nb].x = RIGHT_SPC - MARGE - 1;
		else
			e->itf.shade[nb].x = pt.x - IMG_W;
		hud(e);
	}
	if (e->itf.spectrum[nb].button == L_CLICK)
	{
		mouse.button = e->itf.spectrum[nb].button;
		mouse.x = pt.x;
		mouse.y = pt.y;
		ui_spectrum(nb, coord, mouse, e);
		hud(e);
	}
}

int			mousemove(int x, int y, t_env *e)
{
	t_pix	pt;
	t_pix	coord;

	pt = init_point(x, y);
	coord = init_point(M_IMG_H + 85, g_shad_ys);
	update_mouse(0, pt, coord, e);
	coord = init_point(3 * MARGE + (RIGHT_SPC) / 2 - MARGE,
			3 * MARGE + RIGHT_SPC - MARGE);
	update_mouse(1, pt, coord, e);
	coord = init_point(M_IMG_H + 35 + (RIGHT_SPC) / 2 - MARGE,
			M_IMG_H + 35 + RIGHT_SPC - MARGE);
	update_mouse(2, pt, coord, e);
	return (0);
}
