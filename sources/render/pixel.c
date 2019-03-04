/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:45:04 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/20 23:50:38 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	DRAW_POINT function:
**	Puts the color in the unsigned char * image of the environment
*/

void	draw_point(t_img *img, int x, int y, t_color c)
{
	img->pixel_img[y * img->s_line + x * img->bpp / 8] =
		(unsigned char)ft_min(c.blue * 255.0f, 255.0f);
	img->pixel_img[y * img->s_line + x * img->bpp / 8 + 1] =
		(unsigned char)ft_min(c.green * 255.0f, 255.0f);
	img->pixel_img[y * img->s_line + x * img->bpp / 8 + 2] =
		(unsigned char)ft_min(c.red * 255.0f, 255.0f);
}

/*
**	GET_PT_COLOR function:
**	Gets the color of the point in the img
*/

t_color	get_pt_color(int x, int y, t_img img)
{
	t_color	c;

	x = (int)ft_clamp(0, IMG_W - 1, x);
	y = (int)ft_clamp(0, IMG_H - 1, y);
	c.blue = img.pixel_img[y * img.s_line + x * img.bpp / 8];
	c.green = img.pixel_img[y * img.s_line + x * img.bpp / 8 + 1];
	c.red = img.pixel_img[y * img.s_line + x * img.bpp / 8 + 2];
	return (c);
}

void	draw_debug(t_env *e, int x, int y)
{
	t_img	img;

	img = e->img[CENTER];
	if (e->debug)
	{
		img.pixel_img[y * img.s_line + x * img.bpp / 8 + 2] = 255;
		img.pixel_img[y * img.s_line + x * img.bpp / 8] = 0;
		img.pixel_img[y * img.s_line + x * img.bpp / 8 + 1] = 0;
	}
}
