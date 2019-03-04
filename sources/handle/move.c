/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:34:11 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/22 19:04:02 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"

/*
**	SHOW_MOUSE function:
**	Show or hide the mouse pointer with this new function added to the modified
**	mlx
*/

void		show_mouse(t_env *e)
{
	if (e->key[KEY_TAB])
		mlx_do_mouse_relativeon(e->win);
	else
		mlx_do_mouse_relativeoff(e->win);
}

/*
**	MOVE_CAM and CAM_UPDATE functions:
**	Move the camera and rotate its axis if the proper keys are press
*/

static void	cam_update(t_env *e)
{
	t_vec	i;
	t_vec	j;
	t_vec	k;

	k = (e->initcam.dir.x == 0.0f && e->initcam.dir.y == 1.0f
			&& e->initcam.dir.z == 0.0f) ? newvec(0, 0, 1) : newvec(0, 1, 0);
	i = crossproduct(e->cam->dir, k);
	j = crossproduct(i, e->cam->dir);
	if (e->key[KEY_LEFT] || e->key[KEY_A])
		e->cam->pos = add(e->cam->pos, scale(20, i));
	if (e->key[KEY_RIGHT] || e->key[KEY_D])
		e->cam->pos = add(e->cam->pos, scale(-20, i));
	if (e->key[KEY_W])
		e->cam->pos = add(e->cam->pos, scale(20, e->cam->dir));
	if (e->key[KEY_S])
		e->cam->pos = sub(e->cam->pos, scale(20, e->cam->dir));
	if (e->key[KEY_UP])
		e->cam->pos = add(e->cam->pos, scale(20, j));
	if (e->key[KEY_DOWN])
		e->cam->pos = add(e->cam->pos, scale(-20, j));
	if (e->key[KEY_Q])
		e->cam->dir = rotate_axis(e->cam->dir, e->j, -2);
	if (e->key[KEY_E])
		e->cam->dir = rotate_axis(e->cam->dir, e->j, 2);
}

void		move_cam(t_env *e)
{
	if (e->key[KEY_LEFT] || e->key[KEY_RIGHT] || e->key[KEY_UP]
			|| e->key[KEY_DOWN] || e->key[KEY_W] || e->key[KEY_A]
			|| e->key[KEY_S] || e->key[KEY_D] || e->key[KEY_Q] || e->key[KEY_E])
	{
		cam_update(e);
		e->loading = (e->antialiasing == 0 ? 1 : 0);
	}
}

void		create_axis(t_env *e)
{
	t_vec	k;
	t_vec	l;

	k = e->initcam.dir;
	l = (k.x == 0.0f && k.y == 1.0f && k.z == 0.0f) ? newvec(0, 0, 1)
		: newvec(0, 1, 0);
	e->i = crossproduct(k, l);
	e->j = crossproduct(e->i, k);
}
