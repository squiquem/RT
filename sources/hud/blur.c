/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:06:48 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 17:58:49 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	BLUR function:
**	Apply or not the blur effect to the shadows
*/

void		blur(t_env *e)
{
	int		i;

	i = -1;
	if (e->light[0].radius == 0)
		while (++i < e->nbs[LIGHT])
			e->light[i].radius = 100;
	else
		while (++i < e->nbs[LIGHT])
			e->light[i].radius = 0;
}
