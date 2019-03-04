/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:17:53 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/26 15:12:46 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	TOP_RIGHT function:
**	Draw the 3 top right tabs
*/

static void		top_right(t_env *e)
{
	t_rect	rect;

	rect = init_rect(0, 0, (RIGHT_SPC) / 3, 2 * MARGE);
	draw_rect(RIGHT, rect, LIGHT_GREY, e);
	rect = init_rect((RIGHT_SPC) / 3 + 1, 0, rect.width, rect.height);
	draw_rect(RIGHT, rect, LIGHT_GREY, e);
	rect = init_rect(2 * ((RIGHT_SPC) / 3 + 1), 0, rect.width, rect.height);
	draw_rect(RIGHT, rect, LIGHT_GREY, e);
}

/*
**	UI1_WRITTING function:
**	Write strings into tab 1
*/

static void		ui1_writting(t_env *e)
{
	t_rect	rect;

	mlx_string_put(e->mlx, e->win, WIN_W / 16 - 10,
			IMG_H + 2 * (BOTTOM_SPC) / 10, BLACK, "Filters:");
	rect = init_rect(WIN_W / 14, IMG_H + 2 * (BOTTOM_SPC) / 10 + 22, 40, 2);
	draw_line(rect, BLACK, e);
	mlx_string_put(e->mlx, e->win, 4 * WIN_W / 5 + WIN_W / 7 / 4,
			IMG_H + (BOTTOM_SPC) / 2, BLACK, "Anti-aliasing:");
	rect = init_rect(4 * WIN_W / 5 + WIN_W / 7 / 3 + 12,
			IMG_H + (BOTTOM_SPC) / 2 + 22, 74, 2);
	draw_line(rect, BLACK, e);
	mlx_string_put(e->mlx, e->win, 4 * WIN_W / 5 + WIN_W / 5 / 6,
			IMG_H + (BOTTOM_SPC) / 8 + 2, BLACK, "Uniform color");
	mlx_string_put(e->mlx, e->win, 4 * WIN_W / 5 + WIN_W / 7 / 4 - 10,
			IMG_H + 4 * (BOTTOM_SPC) / 5 - 13, BLACK, "Off");
	mlx_string_put(e->mlx, e->win, 4 * WIN_W / 5 + RIGHT_SPC / 3 + 4,
			IMG_H + 4 * (BOTTOM_SPC) / 5 - 13, BLACK, "Middle");
	mlx_string_put(e->mlx, e->win, 4 * WIN_W / 5 + 2 * RIGHT_SPC / 3 + 14,
			IMG_H + 4 * (BOTTOM_SPC) / 5 - 13, BLACK, "On");
	picked_item(e);
}

/*
**	UI_WRITTING function:
**	Write the number of each tab in top corner right and call the right function
**	to call for the right tab
*/

static void		ui_writting(t_env *e)
{
	int color;

	color = e->itf.onglet;
	mlx_string_put(e->mlx, e->win, 829, 2, (color == 1 ? RED : BLACK), "1");
	mlx_string_put(e->mlx, e->win, 895, 2, (color == 2 ? RED : BLACK), "2");
	mlx_string_put(e->mlx, e->win, 961, 2, (color == 3 ? RED : BLACK), "3");
	if (e->itf.onglet == 1)
		ui1_writting(e);
	if (e->itf.onglet == 3)
	{
		picked_item(e);
		ui3_writting(e);
	}
}

/*
**	TAB function:
**	Call top_right function and the required function to display the right tab
**	Also put image to window, put the strings above the image and destroy images
*/

void			tab(t_env *e)
{
	top_right(e);
	if (e->itf.onglet == 1)
		ui1(e);
	else if (e->itf.onglet == 2)
		ui2(e);
	else if (e->itf.onglet == 3)
		ui3(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[RIGHT].img, IMG_W, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img[BOTTOM].img, 0, IMG_H);
	ui_writting(e);
	mlx_destroy_image(e->mlx, e->img[RIGHT].img);
	mlx_destroy_image(e->mlx, e->img[BOTTOM].img);
}
