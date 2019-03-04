/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:04:25 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:53:35 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"

/*
**	SHADE_DISPLAY function:
**	Draw the shade bar under the color spectrum circle + the 2 triangle cursors
**	for any color spectrum circle
*/

static void	shade_display(int nb, t_rect r, t_colo color, t_env *e)
{
	t_rect	rect;

	rect = init_rect(r.x, r.y, 9, 5);
	draw_rev_tri(RIGHT, rect, color.val, e);
	rect = init_rect(e->itf.shade[nb].x, e->itf.shade[nb].y + MARGE,
			rect.width, rect.height);
	draw_tri(RIGHT, rect, color.val, e);
	rect = init_rect((RIGHT_SPC) / 2 - 2 * MARGE, r.height,
			MARGE * 4, MARGE * 2);
	draw_rect(RIGHT, rect, e->itf.spec_shade[nb].val, e);
	frame(RIGHT, rect, GREY, e);
}

/*
**	CURSOR_SHADE function:
**	Set the position and the color of the triangle cursors to draw by
**	shade_dispay funtion
*/

void		cursor_shade(int nb, t_env *e)
{
	t_pix	pt;
	t_colo	color;
	t_rect	r;

	if (e->itf.shade[nb].x >= MARGE
			&& e->itf.shade[nb].x < g_shad_xe - IMG_W)
	{
		pt = init_point(e->itf.shade[nb].x, e->itf.shade[nb].y);
		e->itf.spec_shade[nb].val = color_picker(e->img[RIGHT], pt);
		if (e->itf.shade[nb].x < (RIGHT_SPC) / 2)
			color.val = WHITE;
		else
			color.val = BLACK;
		r = init_rect(pt.x, pt.y, 0, 0);
		if (nb == 0)
			r.height = g_shad_ye + MARGE;
		if (nb == 1)
			r.height = 3 * MARGE + RIGHT_SPC + MARGE;
		if (nb == 2)
			r.height = M_IMG_H + 35 + RIGHT_SPC + MARGE;
		shade_display(nb, r, color, e);
	}
}

/*
**	CURSOR_SPECTRUM function:
**	Draw the white cross cursor for each color spectrum circle
*/

void		cursor_spectrum(int nb, t_env *e)
{
	int		i;
	int		j;
	t_pix	pt;

	j = -2;
	if (e->itf.spectrum[nb].x > 0 && e->itf.spectrum[nb].x < RIGHT_SPC
		&& e->itf.spectrum[nb].y > 0 && e->itf.spectrum[nb].y < IMG_H)
	{
		while (++j < 1)
		{
			i = -11;
			while (++i < 10)
			{
				pt.x = e->itf.spectrum[nb].x + i;
				pt.y = e->itf.spectrum[nb].y + j;
				if (i < -2 || i > 2)
					color_point(&e->img[RIGHT], pt, WHITE);
				pt.x = e->itf.spectrum[nb].x + j;
				pt.y = e->itf.spectrum[nb].y + i;
				if (i < -2 || i > 2)
					color_point(&e->img[RIGHT], pt, WHITE);
			}
		}
	}
}
