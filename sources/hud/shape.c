/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:21:21 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/18 19:24:05 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	DRAW_TRI function:
**	Draw a triangle with its base on the bottom
*/

void		draw_tri(int nb, t_rect base, int color, t_env *e)
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
			tmp.x = base.x + j - base.width / 2;
			tmp.y = base.y - i;
			color_point(&e->img[nb], tmp, color);
		}
		base.width -= 2;
	}
}

/*
**	DRAW_REV_TRI function:
**	Draw a reverse triangle where the base is at the top
*/

void		draw_rev_tri(int nb, t_rect base, int color, t_env *e)
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
			tmp.x = base.x + j - base.width / 2;
			tmp.y = base.y + i;
			color_point(&e->img[nb], tmp, color);
		}
		base.width -= 2;
	}
}

/*
**	DRAW_RECT function:
**	Draw a rectangle
*/

void		draw_rect(int nb, t_rect rect, int color, t_env *e)
{
	t_pix	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < rect.height)
	{
		j = -1;
		while (++j < rect.width)
		{
			tmp.x = rect.x + j;
			tmp.y = rect.y + i;
			color_point(&e->img[nb], tmp, color);
		}
	}
}

/*
**	FRAME function:
**	Draw a frame of size 2 around a rectangle
*/

void		frame(int nb, t_rect rect, int color, t_env *e)
{
	t_rect	tmp;

	tmp = rect;
	tmp.x = rect.x - 2;
	tmp.y = rect.y - 2;
	tmp.width = 2;
	tmp.height = rect.height + 2 * 2;
	draw_rect(nb, tmp, color, e);
	tmp.height = rect.width + 2 * 2;
	ft_swap(&tmp.width, &tmp.height);
	draw_rect(nb, tmp, color, e);
	tmp.y = rect.y + rect.height;
	draw_rect(nb, tmp, color, e);
	tmp.x = rect.x + rect.width;
	tmp.y = rect.y - 2;
	ft_swap(&tmp.width, &tmp.height);
	tmp.height = rect.height + 2 * 2;
	draw_rect(nb, tmp, color, e);
}

/*
**	DRAW_LINE function:
**	Draw a line using the mlx_pixel_put function, need to be called after
**	mlx_put_image_to_window
*/

void		draw_line(t_rect rect, int color, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;

	i = -1;
	while (++i < rect.height)
	{
		j = -1;
		while (++j < rect.width)
		{
			tmp = init_point(rect.x + j, rect.y + i);
			mlx_pixel_put(e->mlx, e->win, tmp.x, tmp.y, color);
		}
	}
}
