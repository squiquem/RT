/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectrum_shade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:23:56 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/18 19:25:54 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	Set globals used for shade bar for an easier reading of the code
*/

const int	g_shad_xs = IMG_W + MARGE;
const int	g_shad_xe = IMG_W + RIGHT_SPC - MARGE;
const int	g_shad_ys = M_IMG_H + CIRCLE + MARGE;
const int	g_shad_ye = M_IMG_H + CIRCLE + 2 * MARGE;

/*
**	SPECTRUM_SHADE function:
**	Get the color from the mouse pointer click in the circle and call the
**	drawing function for spectrum cursor, shade bar and cursor shade bar
*/

void		spectrum_shade(int nb, int start, t_env *e)
{
	t_pix	pt;

	if (e->itf.spectrum[nb].x)
	{
		pt = init_point(e->itf.spectrum[nb].x, e->itf.spectrum[nb].y);
		e->itf.spec[nb].val = color_picker(e->img[RIGHT], pt);
		if (e->itf.spec[nb].val != WHITE)
			e->itf.spec_shade[nb].val = e->itf.spec[nb].val;
		cursor_spectrum(nb, e);
		pt = init_point(e->itf.spectrum[nb].x, e->itf.spectrum[nb].y);
		e->itf.spec_shade[nb].val = color_picker(e->img[RIGHT], pt);
		shade_bar(start + RIGHT_SPC - MARGE, e->itf.spec[nb].val, e);
		cursor_shade(nb, e);
	}
}

/*
**	UI_SHADE function:
**	Check if the mouse pointer is in the shade bar and set values for the shade
**	bar cursor
*/

void		ui_shade(int nb, t_pix pix, t_mouse mouse, t_env *e)
{
	if (mouse.x >= g_shad_xs && mouse.x < g_shad_xe && mouse.y >= pix.y
			&& mouse.y < pix.x)
	{
		e->itf.shade[nb].button = mouse.button;
		e->itf.shade[nb].x = mouse.x - IMG_W;
		e->itf.shade[nb].y = pix.y;
	}
}

/*
**	UI_SPECTRUM function:
**	Check if the mouse pointer is in any color spectrum circle and set values
**	to draw cursor for color spectrum circle and the shade bar
*/

int			ui_spectrum(int nb, t_pix pix, t_mouse mouse, t_env *e)
{
	int		a;
	int		b;

	a = IMG_W + (RIGHT_SPC) / 2;
	b = pix.x;
	if ((mouse.x - a) * (mouse.x - a) + (mouse.y - b) * (mouse.y - b)
			< ((CIRCLE) / 2) * ((CIRCLE) / 2))
	{
		e->itf.spectrum[nb] = mouse;
		e->itf.spectrum[nb].x = mouse.x - IMG_W;
		e->itf.shade[nb].x = (RIGHT_SPC) / 2;
		e->itf.shade[nb].y = pix.y;
		return (1);
	}
	return (0);
}
