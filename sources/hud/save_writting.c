/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_writting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:56:44 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:58:10 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void		save_writting(t_env *e)
{
	mlx_string_put(e->mlx, e->win, IMG_W + 30, M_IMG_H + 52,
			BLACK, "Reset spectrum");
	mlx_string_put(e->mlx, e->win, IMG_W + RIGHT_SPC / 4 - 10, M_IMG_H + 102,
			BLACK, "Save changes");
	mlx_string_put(e->mlx, e->win, IMG_W + RIGHT_SPC / 4 - 10, M_IMG_H + 152,
			BLACK, "Export scene");
}
