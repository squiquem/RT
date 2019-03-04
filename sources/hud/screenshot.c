/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:30:48 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:52:48 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"
#include "png.h"
#include <stdio.h>

static void	fill_rows(t_img img, png_structp *png_ptr, png_byte **row_ptr)
{
	t_colo		c;
	int			x;
	int			y;
	png_byte	*row;
	int			pixel_size;

	pixel_size = 3;
	y = -1;
	while (++y < IMG_H)
	{
		if (!(row_ptr[y] = png_malloc(*png_ptr,
						(sizeof(unsigned char) * (IMG_W) * pixel_size))))
			ft_printerror("Error row png malloc");
		row = row_ptr[y];
		x = -1;
		while (++x < IMG_W)
		{
			c.val = *(int *)&img.pixel_img[x * img.bpp / 8 + y * img.s_line];
			*row++ = c.argb[R];
			*row++ = c.argb[G];
			*row++ = c.argb[B];
		}
	}
}

static void	save_to_png(t_img img, FILE *fp, png_structp *png_ptr
		, png_infop *info_ptr)
{
	png_byte	**row_pointers;
	int			depth;
	int			y;

	depth = 8;
	row_pointers = NULL;
	if (!(row_pointers = png_malloc(*png_ptr,
					sizeof(unsigned char *) * (IMG_H))))
		ft_printerror("Error row_pointers png malloc");
	png_set_IHDR(*png_ptr, *info_ptr, IMG_W, IMG_H, depth, PNG_COLOR_TYPE_RGB,
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
			PNG_FILTER_TYPE_DEFAULT);
	fill_rows(img, png_ptr, row_pointers);
	png_init_io(*png_ptr, fp);
	png_set_rows(*png_ptr, *info_ptr, row_pointers);
	png_write_png(*png_ptr, *info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
	y = -1;
	while (++y < IMG_H)
		png_free(*png_ptr, row_pointers[y]);
	png_free(*png_ptr, row_pointers);
}

static void	complete_name(char *name)
{
	int		i;

	i = -1;
	while (name[++i])
		if (name[i] == ' ')
			name[i] = '_';
}

static void	screenshot_name(t_save *save)
{
	char	*cdate;
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = ft_strstr(save->name, ".xml");
	if (!(tmp2 = ft_strrchr(save->name, '/')))
		i = ft_strlen(save->name) - 4;
	else
		i = (int)(tmp - tmp2);
	if (!(save->scene = ft_memalloc(sizeof(char) * (i + 42))))
		ft_printerror("Error malloc");
	save->scene = ft_strcpy(save->scene, "screenshots/");
	if (tmp2 == NULL)
		save->scene = ft_strncat(save->scene, save->name, i);
	else
		save->scene = ft_strncat(save->scene, tmp2 + 1, i - 1);
	save->scene = ft_strcat(save->scene, "_");
	save->start = time(NULL);
	cdate = ctime(&(save->start));
	save->scene = ft_strncat(save->scene, cdate, 24);
	save->scene = ft_strcat(save->scene, ".png");
	complete_name(save->scene);
}

void		screenshot(t_env *e)
{
	FILE		*fp;
	png_structp	png_ptr;
	png_infop	info_ptr;

	screenshot_name(&e->save);
	fp = fopen(e->save.scene, "wb");
	if (!fp)
		ft_printerror("Error open screenshot file");
	png_ptr = NULL;
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
		ft_printerror("Error png create write struct");
	info_ptr = NULL;
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
		ft_printerror("Error png create info struct");
	save_to_png(e->img[CENTER], fp, &png_ptr, &info_ptr);
	ft_putstr(e->save.scene);
	ft_putendl(" saved \\o/");
	free(e->save.scene);
	e->key[KEY_BCKSPC] = 0;
	png_destroy_write_struct(&png_ptr, &info_ptr);
	if (fclose(fp) != 0)
		ft_printerror("Error close screenshot file");
	save_load(e);
}
