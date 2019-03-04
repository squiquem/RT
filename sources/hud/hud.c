/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:39:40 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/18 19:20:46 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	HUD function:
**	Creates new image to display UI
*/

void		hud(t_env *e)
{
	t_rect	rect;

	new_image(&e->img[RIGHT], RIGHT_SPC, IMG_H, e);
	rect = init_rect(0, 0, RIGHT_SPC, IMG_H);
	draw_rect(RIGHT, rect, DARK_GREY, e);
	new_image(&e->img[BOTTOM], WIN_W, BOTTOM_SPC, e);
	rect = init_rect(0, 0, WIN_W, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, DARK_GREY, e);
	tab(e);
}
