/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:26:53 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/19 21:39:22 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	Set the globals for parameters for an easier reading of the code
*/

const int	g_screen_x = IMG_W + RIGHT_SPC / 2 - 25;

/*
**	UI3_ZONE function:
**	Select the new lvl of refraction for the scene if the user click on the lvl
**	tab or set to 0 the 3 e->itf.spectrum to reset the 3 color spectrum value
*/

void		ui3_zone(t_mouse m, t_env *e)
{
	if (m.x >= IMG_W + RIGHT_SPC / 2 - 45 && m.x <= IMG_W + RIGHT_SPC / 2 + 45
			&& m.y >= IMG_H / 2 - 5 && m.y <= IMG_H / 2 + 5)
		e->lvl = (m.x - (IMG_W + RIGHT_SPC / 2 - 45)) / 3;
	else if (m.x >= IMG_W + 25 && m.x <= WIN_W - 25
			&& m.y >= M_IMG_H + 50 && m.y <= M_IMG_H + 80)
		ft_memset(e->itf.spectrum, 0, sizeof(e->itf.spectrum));
	else if (m.x >= IMG_W + 25 && m.x <= WIN_W - 25
			&& m.y >= M_IMG_H + 100 && m.y <= M_IMG_H + 100 + 2 * MARGE)
		save(0, e);
	else if (m.x >= IMG_W + 25 && m.x <= WIN_W - 25
			&& m.y >= M_IMG_H + 150 && m.y <= M_IMG_H + 150 + 2 * MARGE)
		save(1, e);
	else if (m.x >= g_screen_x && m.x <= g_screen_x + 50
			&& m.y >= M_IMG_H + 200 && m.y <= M_IMG_H + 250)
		screenshot(e);
}
