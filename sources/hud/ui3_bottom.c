/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:27:30 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 16:00:57 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	UI3_ARROW function:
**	Draw the 2 arrows for increase and decrease parameter value
*/

static void	ui3_arrow(t_env *e)
{
	t_rect	r;

	r = init_rect(g_param_x + WIN_W / 5 / 3, BOTTOM_SPC / 2 / 3, 50, 50);
	draw_rect(BOTTOM, r, LIGHT_GREY, e);
	r = init_rect(g_param_x + WIN_W / 5 / 3, BOTTOM_SPC / 2, 50, 50);
	draw_rect(BOTTOM, r, LIGHT_GREY, e);
	r = init_rect(g_param_x + WIN_W / 5 / 3 + 25, BOTTOM_SPC / 2 / 3 + 20,
			29, 15);
	draw_tri(BOTTOM, r, BLACK, e);
	r = init_rect(g_param_x + WIN_W / 5 / 3 + 19, BOTTOM_SPC / 2 / 3 + 20,
			13, 20);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(g_param_x + WIN_W / 5 / 3 + 25, BOTTOM_SPC / 2 + 30, 29, 15);
	draw_rev_tri(BOTTOM, r, BLACK, e);
	r = init_rect(g_param_x + WIN_W / 5 / 3 + 19, BOTTOM_SPC / 2 + 10, 13, 20);
	draw_rect(BOTTOM, r, BLACK, e);
}

/*
**	UI3_FRAMES function:
**	Draw the frames on the selected parameter for the picked item
*/

static void	ui3_frames(t_rect *r, t_env *e)
{
	int		i;

	i = -1;
	while (++i < 7)
		frame(BOTTOM, r[i], DARK_GREY, e);
	i = -1;
	while (++i < 7)
		if (i == e->itf.mouse.button)
			frame(BOTTOM, r[i], C_GREEN, e);
	if (--i == SCALE && (e->itf.mat.type != MARBLE && e->itf.mat.type != WOOD
				&& e->itf.mat.type != PERTURB))
		frame(BOTTOM, r[i], DARK_GREY, e);
}

/*
**	SET_FRAMES function:
**	Set frames to draw for selected parameter
*/

static void	set_frames(t_rect *r)
{
	int		i;

	i = -1;
	while (++i < 7)
		r[i] = init_rect(7, i * g_param_y + g_param_y - 18, g_param_x, 20);
}

/*
**	UI3_LIST function:
**	Draw list points to get a pretty menu
*/

static void	ui3_list(t_env *e)
{
	t_rect	r;
	int		i;

	i = -1;
	while (++i < 6)
	{
		r = init_rect(15, 17 + i * 25, 9, 5);
		draw_tri_right(BOTTOM, r, BLACK, e);
		draw_tri_left(BOTTOM, r, BLACK, e);
	}
	if (e->itf.mat.type == MARBLE || e->itf.mat.type == PERTURB
			|| e->itf.mat.type == WOOD)
	{
		r = init_rect(15, 17 + i * 25, 9, 5);
		draw_tri_right(BOTTOM, r, BLACK, e);
		draw_tri_left(BOTTOM, r, BLACK, e);
	}
}

/*
**	UI3_BOTTOM function:
**	Centralize the functions calls for tab 3 bottom
*/

void		ui3_bottom(t_env *e)
{
	t_rect	r[7];

	if (e->itf.pick.button != -1)
	{
		set_frames(r);
		ui3_list(e);
		ui3_frames(r, e);
		ui3_arrow(e);
	}
}
