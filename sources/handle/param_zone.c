/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_zone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:29:27 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 16:47:44 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	Set the globals for parameters for an easier reading of the code
*/

const int			g_param_x = WIN_W / 5;
const int			g_param_y = BOTTOM_SPC / 8;

/*
**	UP_AND_DOWN, UP_VALUE and DOWN_VALUE functions:
**	Increase or decrease the selected parameters for the picked item if the
**	user click on the up or down arrow zone
*/

static void	up_value(t_env *e)
{
	if (e->itf.mouse.button == REFLECTION
			&& e->itf.param[REFLECTION] < 100)
		e->itf.param[REFLECTION] += 5;
	else if (e->itf.mouse.button == TRANSPARENCY
			&& e->itf.param[TRANSPARENCY] < 100)
		e->itf.param[TRANSPARENCY] += 5;
	else if (e->itf.mouse.button == SPECVALUE)
		e->itf.param[SPECVALUE] += 1;
	else if (e->itf.mouse.button == SPECPOWER)
		e->itf.param[SPECPOWER] += 5;
	else if (e->itf.mouse.button == N && e->itf.param[N] < 20)
	{
		e->itf.param[N] += 1;
		if (e->itf.param[N] < 10)
			e->itf.param[N] = 10;
	}
	else if (e->itf.mouse.button == BUMP
			&& e->itf.param[BUMP] < 100)
		e->itf.param[BUMP] += 5;
	else if (e->itf.mouse.button == SCALE
			&& e->itf.param[SCALE] < 10)
		if ((e->itf.mat.type == PERTURB || e->itf.mat.type == MARBLE
					|| e->itf.mat.type == WOOD) && e->itf.mouse.button == SCALE)
			e->itf.param[SCALE] *= 10;
}

static void	down_value(t_env *e)
{
	if (e->itf.mouse.button == REFLECTION
			&& e->itf.param[e->itf.mouse.button] > 4)
		e->itf.param[REFLECTION] -= 5;
	else if (e->itf.mouse.button == TRANSPARENCY
			&& e->itf.param[TRANSPARENCY] > 4)
		e->itf.param[TRANSPARENCY] -= 5;
	else if (e->itf.mouse.button == SPECVALUE
			&& e->itf.param[SPECVALUE] > 0)
		e->itf.param[SPECVALUE] -= 1;
	else if (e->itf.mouse.button == SPECPOWER
			&& e->itf.param[SPECPOWER] > 5)
		e->itf.param[SPECPOWER] -= 5;
	else if (e->itf.mouse.button == N && e->itf.param[N] > 9)
	{
		e->itf.param[N] -= 1;
		if (e->itf.param[N] < 10)
			e->itf.param[N] = 0;
	}
	else if (e->itf.mouse.button == BUMP && e->itf.param[BUMP] > 0)
		e->itf.param[BUMP] -= 5;
	else if (e->itf.mouse.button == SCALE && e->itf.param[SCALE] > 0.001)
		if ((e->itf.mat.type == PERTURB || e->itf.mat.type == MARBLE
					|| e->itf.mat.type == WOOD) && e->itf.mouse.button == SCALE)
			e->itf.param[SCALE] /= 10;
}

void		up_and_down(t_mouse m, t_env *e)
{
	if (m.x >= g_param_x + WIN_W / 5 / 3 && m.x < g_param_x + WIN_W / 5 / 3 + 50
			&& m.y >= IMG_H + BOTTOM_SPC / 2 / 3
			&& m.y < IMG_H + BOTTOM_SPC / 2 / 3 + 50)
		up_value(e);
	if (m.x >= g_param_x + WIN_W / 5 / 3 && m.x < g_param_x + WIN_W / 5 / 3 + 50
			&& m.y >= IMG_H + BOTTOM_SPC / 2
			&& m.y < IMG_H + BOTTOM_SPC / 2 + 50)
		down_value(e);
}

/*
**	PARAM_ZONE and PARAM_ZONE2 functions:
**	If an item is picked, select or not the parameter if the user click on
**	the proper parameter zone
*/

static void	param_zone2(t_mouse m, t_env *e)
{
	if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + 6 * g_param_y
			- 20 && m.y < IMG_H + 6 * g_param_y + 3)
		e->itf.mouse.button = (e->itf.mouse.button == BUMP ? -1 : BUMP);
	else if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + 7 * g_param_y
			- 20 && m.y < IMG_H + 7 * g_param_y + 3)
		if (e->itf.mat.type == PERTURB || e->itf.mat.type == MARBLE
				|| e->itf.mat.type == WOOD)
			e->itf.mouse.button = (e->itf.mouse.button == SCALE ? -1 : SCALE);
}

void		param_zone(t_mouse m, t_env *e)
{
	if (e->itf.pick.button != -1)
	{
		if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + g_param_y - 25
				&& m.y < IMG_H + g_param_y + 3)
			e->itf.mouse.button =
				(e->itf.mouse.button == REFLECTION ? -1 : REFLECTION);
		else if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + 2 * g_param_y
				- 20 && m.y < IMG_H + 2 * g_param_y + 3)
			e->itf.mouse.button =
				(e->itf.mouse.button == TRANSPARENCY ? -1 : TRANSPARENCY);
		else if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + 3 * g_param_y
				- 20 && m.y < IMG_H + 3 * g_param_y + 3)
			e->itf.mouse.button =
				(e->itf.mouse.button == SPECVALUE ? -1 : SPECVALUE);
		else if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + 4 * g_param_y
				- 20 && m.y < IMG_H + 4 * g_param_y + 3)
			e->itf.mouse.button =
				(e->itf.mouse.button == SPECPOWER ? -1 : SPECPOWER);
		else if (m.x >= 10 && m.x < g_param_x && m.y >= IMG_H + 5 * g_param_y
				- 20 && m.y < IMG_H + 5 * g_param_y + 3)
			e->itf.mouse.button = (e->itf.mouse.button == N ? -1 : N);
		param_zone2(m, e);
		up_and_down(m, e);
	}
}
