/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:57:38 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/26 15:16:47 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	RESET_VALUES function:
**	Reset values for the next item to modify
*/

void		reset_values(t_env *e)
{
	ft_memset(&e->itf.mat, 0, sizeof(t_mat));
	ft_memset(&e->itf.item, 0, sizeof(t_item));
	ft_memset(&e->itf.param, 0, sizeof(e->itf.param));
	e->itf.pick.button = -1;
	e->itf.mouse.button = -1;
	e->itf.nb_texture = 0;
}

/*
**	RESET_UI function:
**	Apply all the changes and reset the values for the next item
*/

void		reset_ui(t_env *e)
{
	if (e->itf.pick.button != -1)
	{
		if (e->itf.nb_texture && e->itf.item.item_type != QUADRIC
				&& e->itf.item.item_type != BOX)
			apply_texture(e);
		else
			apply_mat(e->itf.mat.type, e);
	}
	reset_values(e);
	hud(e);
}
