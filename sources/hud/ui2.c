/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:28:45 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 19:54:32 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	UI2 function:
**	Centralize the functions calls for tab 2
*/

void		ui2(t_env *e)
{
	t_pix	pt;

	if (e->itf.mat.type != UNIFORM && e->itf.mat.type != TEXTURE
			&& e->itf.pick.button != -1)
	{
		pt = init_point(MARGE, 3 * MARGE);
		insert_xpm(RIGHT, pt, "resources/little-color-wheel.xpm", e);
		spectrum_shade(1, 3 * MARGE, e);
	}
	if ((e->itf.mat.type == CHECKER || e->itf.mat.type == MARBLE
				|| e->itf.mat.type == PERTURB || e->itf.mat.type == WOOD)
			&& e->itf.pick.button != -1)
	{
		pt = init_point(MARGE, M_IMG_H + 35);
		insert_xpm(RIGHT, pt, "resources/little-color-wheel.xpm", e);
		spectrum_shade(2, M_IMG_H + 35, e);
	}
	ui2_bottom(e);
}
