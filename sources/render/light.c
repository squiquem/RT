/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/20 15:37:38 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	LAMBERT function:
**	Returns the lambert coefficient (for shape shadow)
*/

double		lambert(t_ray lightray, t_vec n)
{
	double	f;

	f = dotproduct(lightray.dir, n);
	return (f);
}

/*
**	COLOR_LAMBERT function:
*/

void		color_lambert(t_color *c, double l, t_light currl, t_color matdiff)
{
	c->red += l * currl.intensity.red * matdiff.red / 255 / 255;
	c->green += l * currl.intensity.green * matdiff.green / 255 / 255;
	c->blue += l * currl.intensity.blue * matdiff.blue / 255 / 255;
}

/*
**	BLINNPHUONG function:
**	Returns the Blinn-Phuong coefficient (for bright)
*/

double		blinnphong(t_ray lightray, t_ray *r, t_vec n, t_mat currmat)
{
	t_vec	blinndir;
	double	blinnterm;

	blinndir = sub(lightray.dir, r->dir);
	if (magnitude2(blinndir) != 0)
	{
		blinndir = normalize(blinndir);
		blinnterm = ft_max(dotproduct(blinndir, n), 0.0f);
		blinnterm = currmat.specvalue * powf(blinnterm, currmat.specpower);
	}
	else
		blinnterm = 0;
	return (blinnterm);
}

/*
**	COLOR_BLINNPHUONG function:
**	Changes the color to add the BP coefficient according to the color
*/

void		color_blinnphong(t_color *c, double b, t_light currl)
{
	c->red += b * currl.intensity.red / 255;
	c->green += b * currl.intensity.green / 255;
	c->blue += b * currl.intensity.blue / 255;
}

/*
**	LENS_FLARING function:
**	Blinds the user when a light is in front of the camera
*/

t_color		lens_flaring(t_ray r, t_env *e)
{
	int		j;
	t_color	c;
	t_vec	dist;
	t_ray	lray;

	c = newcolor(0, 0, 0);
	j = -1;
	while (++j < e->nbs[LIGHT])
	{
		dist = sub(e->light[j].pos, e->cam->pos);
		dist = (magnitude(dist) < 0.01f ? newvec(0, 0, 0) : normalize(dist));
		lray.start = e->cam->pos;
		lray.dir = dist;
		if (in_shadow(lray, e, magnitude(sub(e->light[j].pos, e->cam->pos)))
				!= -1)
			continue ;
		c = add_2colors(c, multp_color(e->light[j].intensity,
					pow(ft_max(dotproduct(r.dir, dist), 0.0f), 10) / 255.0f));
	}
	return (c);
}
