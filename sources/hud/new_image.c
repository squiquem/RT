/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:07:06 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:55:02 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	NEW_IMAGE function:
**	Create a new image and get the data address for a further use for each of
**	the 3 different images used by RT
*/

void	new_image(t_img *img, int width, int height, t_env *e)
{
	if (!(img->img = mlx_new_image(e->mlx, width, height))
			|| !(img->pixel_img =
				(unsigned char*)mlx_get_data_addr(img->img, &(img->bpp),
					&(img->s_line), &(img->ed))))
		ft_printerror("Error mlx");
	img->w = width;
	img->h = height;
}
