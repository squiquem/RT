/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:06:30 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 18:17:27 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	INIT_X functions:
**	Set the values for a t_pix or a t_rect
*/

t_pix			init_point(int x, int y)
{
	t_pix pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_rect			init_rect(int x, int y, int width, int height)
{
	t_rect rect;

	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}
