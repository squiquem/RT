/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:19:16 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/26 15:38:46 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "rt.h"
#include "hud.h"

/*
**	KEYPRESS function:
**	Save the used keys from keyboard, called by mlx_hook function
*/

int		keypress(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		quit();
	else if (keycode == KEY_TAB)
		e->key[KEY_TAB] = (e->key[KEY_TAB] == 1 ? 0 : 1);
	else if (keycode == KEY_SPC)
		e->key[KEY_SPC] = (e->key[KEY_SPC] == 1 ? 0 : 1);
	else
	{
		if (keycode == KEY_ENTER)
		{
			if (e->itf.nb_texture)
				return (0);
			e->loading = (e->antialiasing == 0 ? 1 : 0);
			reset_ui(e);
		}
		e->key[keycode] = 1;
	}
	return (0);
}

/*
**	KEYRELEASE function:
**	Set to 0 the released keys, called by mlx_hook function
*/

int		keyrelease(int keycode, t_env *e)
{
	if (keycode == KEY_TAB || keycode == KEY_SPC)
		return (keycode);
	e->key[keycode] = 0;
	return (0);
}

/*
**	KEY_HOOK function:
**	Update the movement of the camera and show or hide the mouse pointer
*/

void	key_hook(t_env *e)
{
	if (e->key[KEY_BCKSPC])
		screenshot(e);
	move_cam(e);
	show_mouse(e);
}
