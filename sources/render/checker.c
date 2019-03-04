/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:15:06 by squiquem          #+#    #+#             */
/*   Updated: 2019/01/31 15:32:11 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	checker_tex_build(t_img *tex, t_color c1, t_color c2)
{
	t_pix	p;
	int		k;

	tex->img = NULL;
	tex->bpp = 32;
	tex->s_line = 1024;
	tex->ed = 0;
	tex->w = 256;
	tex->h = 256;
	p.x = -1;
	if (!(tex->pixel_img = (unsigned char*)malloc(sizeof(char) * (tex->h
			* tex->s_line + 1))))
		ft_printerror("Error malloc");
	while (++p.x < tex->w)
	{
		p.y = -1;
		while (++p.y < tex->h)
		{
			k = (int)(floor(p.x / 128) + floor(p.y / 128)) % 2;
			tex->pixel_img[p.y * 1024 + p.x * 4] = (k ? c1.blue : c2.blue);
			tex->pixel_img[p.y * 1024 + p.x * 4 + 1] = (k ? c1.green
					: c2.green);
			tex->pixel_img[p.y * 1024 + p.x * 4 + 2] = (k ? c1.red : c2.red);
		}
	}
}

void	waves_tex_build(t_img *tex, t_color c)
{
	t_pix	p;
	double	k;

	tex->img = NULL;
	tex->bpp = 32;
	tex->s_line = 1024;
	tex->ed = 0;
	tex->w = 256;
	tex->h = 256;
	p.x = -1;
	if (!(tex->pixel_img = (unsigned char*)malloc(sizeof(char) * (tex->h
			* tex->s_line + 1))))
		ft_printerror("Error malloc");
	while (++p.x < tex->w)
	{
		p.y = -1;
		while (++p.y < tex->h)
		{
			k = (sin(p.x * 2 * M_PI * 5 / 256) + 1) * 0.5;
			tex->pixel_img[p.y * 1024 + p.x * 4] = k * c.blue;
			tex->pixel_img[p.y * 1024 + p.x * 4 + 1] = k * c.green;
			tex->pixel_img[p.y * 1024 + p.x * 4 + 2] = k * c.red;
		}
	}
}
