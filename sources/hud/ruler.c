/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:29:43 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:57:49 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	SEPARATIONS function:
**	With the function above, draw the strokes from tab 1
*/

static void	separations(t_env *e)
{
	t_rect	rect;

	rect = init_rect(3 * (WIN_W / 5) - 3, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(3 * (WIN_W / 5) - 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(4 * (WIN_W / 5) - 3, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(4 * (WIN_W / 5) - 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(4 * (WIN_W / 5), (BOTTOM_SPC) / 2, WIN_W / 5, 1);
	draw_rect(BOTTOM, rect, BLACK, e);
}

/*
**	UI1_BOTTOM_STROKES function:
**	Draw the strokes from tab 1
*/

void		ui1_bottom_strokes(t_env *e)
{
	t_rect	rect;
	t_rect	r1;
	t_rect	r2;

	separations(e);
	r1 = init_rect(4 * (WIN_W / 5) + RIGHT_SPC / 3,
			5 * (BOTTOM_SPC) / 8 + 9, 1, 50);
	draw_rect(BOTTOM, r1, BLACK, e);
	r2 = init_rect(4 * (WIN_W / 5) + 2 * RIGHT_SPC / 3 + 1,
			5 * (BOTTOM_SPC) / 8 + 9, 1, 50);
	draw_rect(BOTTOM, r2, BLACK, e);
	if (!e->antialiasing)
		rect = init_rect(4 * (WIN_W / 5) + WIN_W / 7 / 4 - 14, r1.y,
				r1.x - (4 * (WIN_W / 5) + WIN_W / 7 / 4 - 14), 50);
	else if (e->antialiasing == 1)
		rect = init_rect(r1.x + 1, r1.y, r2.x - r1.x - 1, 50);
	else
		rect = init_rect(r2.x + 1, r2.y,
				(4 * (WIN_W / 5) + (WIN_W / 7) / 4 + 144) - r2.x, 50);
	frame(BOTTOM, rect, C_GREEN, e);
}
