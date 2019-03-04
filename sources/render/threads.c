/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/22 12:45:41 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <string.h>
#include <errno.h>

void		debug(t_env *e)
{
	t_pix			p;

	new_image(&e->img[CENTER], IMG_W, IMG_H, e);
	p.y = IMG_H;
	while (--p.y > -1)
	{
		p.x = -1;
		while (++p.x < IMG_W)
		{
			e->debug = (p.x == 470 && p.y == 300) ? 1 : 0;
			if (e->antialiasing == 0)
				aliasing(10, p, e);
			else if (e->antialiasing == 1)
				aliasing(1, p, e);
			else if (e->antialiasing == 2)
				supersampling(2, p, e);
			draw_debug(e, p.x, p.y);
		}
	}
}

/*
**	DRAW function:
**	For Multithreading
*/

static void	*draw(void *arg)
{
	t_sgmt			thread;
	t_pix			p;
	t_th			*th;

	th = (t_th *)arg;
	thread.start = 0;
	thread.end = (th->nb + 1) * IMG_W / NB_THR;
	thread.start = th->nb * IMG_W / NB_THR;
	p.y = IMG_H;
	while (--p.y > -1)
	{
		p.x = thread.start - 1;
		while (++p.x < thread.end)
		{
			if (th->env->antialiasing == 0)
				aliasing(10, p, th->env);
			else if (th->env->antialiasing == 1)
				aliasing(1, p, th->env);
			else if (th->env->antialiasing == 2)
				supersampling(2, p, th->env);
		}
	}
	pthread_exit(NULL);
}

/*
**	CREATE_THREADS function:
**	Creates threads in env
*/

void		create_threads(t_env *e)
{
	int				i;
	int				rc;
	t_th			th[NB_THR];

	i = -1;
	while (++i < NB_THR)
	{
		th[i].env = e;
		th[i].nb = i;
		if ((rc = pthread_create(&e->thr[i], NULL, draw, &th[i])))
			ft_putendl_fd(strerror(errno), 2);
	}
	i = -1;
	while (++i < NB_THR)
		if (pthread_join(e->thr[i], NULL))
			ft_putendl_fd(strerror(errno), 2);
}

/*
**	RELOAD function:
**	Sets image in the window
*/

int			reload(t_env *e)
{
	if (!e->loading)
		load(e);
	else if (e->loading == 1)
	{
		create_threads(e);
		if (e->cartoon == 1)
			add_cartoon_effect(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img[CENTER].img, 0, 0);
		e->loading = 2;
	}
	key_hook(e);
	return (0);
}
