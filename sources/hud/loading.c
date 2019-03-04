/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:38:44 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/25 16:11:47 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void			save_load(t_env *e)
{
	t_rect	r;

	r = init_rect(IMG_W - 105, IMG_H - 30, 102, 30);
	draw_line(r, LIGHT_GREY, e);
	mlx_string_put(e->mlx, e->win, IMG_W - 100, IMG_H - 30, BLACK, "Saving...");
	e->loading = 1;
}

/*
**	LOAD function:
**	Display the loading screen
*/

void			load(t_env *e)
{
	t_img	load;

	if (e->antialiasing > 0)
	{
		open_texture(e, &load, "resources/3_hours_later.xpm");
		mlx_put_image_to_window(e->mlx, e->win, load.img, 0, 0);
		mlx_destroy_image(e->mlx, load.img);
	}
	e->loading = 1;
}
