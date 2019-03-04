/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:21:01 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 16:02:31 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	GET_COLOR function:
**	Get the color for a pixel from an img, used with the insert_xpm function
*/

static int	get_color(int x, int y, t_img img)
{
	int color;

	if (x < img.w && x >= 0 && y < img.h && y >= 0)
	{
		color = *(int *)&img.pixel_img[x * (img.bpp / 8) + y * img.s_line];
		return (color);
	}
	return (0);
}

/*
**	INSERT_XPM function:
**	Insert and xpm file to the image, if one of the mlx function fail, exit
*/

void		insert_xpm(int nb, t_pix pt, char *name, t_env *e)
{
	t_img	img;
	int		i;
	int		j;
	t_colo	c;
	t_pix	tmp;

	if (!(img.img = mlx_xpm_file_to_image(e->mlx, name, &img.w, &img.h))
			|| !(img.pixel_img =
				(unsigned char*)mlx_get_data_addr(img.img, &img.bpp,
					&img.s_line, &img.ed)))
		ft_printerror("Error mlx");
	c.val = 0;
	j = -1;
	while (++j < img.h)
	{
		i = -1;
		while (++i < img.w)
		{
			tmp.x = i + pt.x;
			tmp.y = j + pt.y;
			c.val = get_color(i, j, img);
			color_point(&e->img[nb], tmp, c.val);
		}
	}
}

/*
**	COLOR_POINT function:
**	Color a pixel at coordinates pt with the color
*/

void		color_point(t_img *img, t_pix pt, int c)
{
	if (pt.x < img->w && pt.x >= 0 && pt.y < img->h && pt.y >= 0)
		*(int *)&img->pixel_img[pt.x * (img->bpp / 8) + pt.y * img->s_line] = c;
}

/*
**	COLOR_PICKER function:
**	Get the color for a pixel from coordinates pt
*/

int			color_picker(t_img img, t_pix pt)
{
	int c;

	if (pt.x < img.w && pt.x >= 0 && pt.y < img.h && pt.y >= 0)
	{
		c = *(int *)&img.pixel_img[pt.x * (img.bpp / 8) + pt.y * img.s_line];
		return (c);
	}
	return (0);
}
