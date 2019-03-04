/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:21:21 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/18 19:25:05 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	DRAW_TRI_LEFT function:
**	Draw a triangle with its base is on the right
*/

void		draw_tri_left(int nb, t_rect base, int color, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;

	i = -1;
	while (++i < base.height)
	{
		j = -1;
		while (++j < base.width)
		{
			tmp.x = base.x - i;
			tmp.y = base.y + j - base.width / 2;
			color_point(&e->img[nb], tmp, color);
		}
		base.width -= 2;
	}
}

/*
**	DRAW_TRI_LEFT function:
**	Draw a triangle with its base is on the left
*/

void		draw_tri_right(int nb, t_rect base, int color, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;

	i = -1;
	while (++i < base.height)
	{
		j = -1;
		while (++j < base.width)
		{
			tmp.x = base.x + i;
			tmp.y = base.y + j - base.width / 2;
			color_point(&e->img[nb], tmp, color);
		}
		base.width -= 2;
	}
}
