/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:53:36 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/11 17:45:33 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	FILL_PARAM function:
**	fill the working param table to be modified by user.
*/

void		fill_param(t_env *e)
{
	e->itf.param[REFLECTION] = e->itf.mat.reflection * 100;
	e->itf.param[TRANSPARENCY] = e->itf.mat.transparency * 100;
	e->itf.param[SPECVALUE] = e->itf.mat.specvalue;
	e->itf.param[SPECPOWER] = e->itf.mat.specpower;
	e->itf.param[N] = e->itf.mat.n * 10;
	e->itf.param[BUMP] = e->itf.mat.bump * 100;
	e->itf.param[SCALE] = e->itf.mat.scale;
}
