/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/22 19:18:11 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	COLOR_CALC function:
**	The loop is here for reflections
*/

t_color			color_calc(double x, double y, t_env *e)
{
	t_work	w;
	int		i;
	t_color	c;

	w.c = e->backgroundcolor;
	w.coef = 1.0;
	w.r.start = e->cam->pos;
	w.r.dir = set_ray_dir(x, y, e);
	w.n = 1.000;
	i = -1;
	while (++i < REFRINCL)
		w.id[i] = -1;
	c = ft_resolve(e, w, 0);
	if (e->filter == SEPIA)
		c = add_sepia_filter(c);
	else if (e->filter == GREYSCALE)
		c = add_greyscale_filter(c);
	else if (e->filter == REVERSE)
		c = add_reverse_filter(c);
	else if (e->filter == SATURATE)
		c = add_saturate_filter(c);
	return (c);
}

/*
**	COLOR_TAB_SUM function:
**	Sums the colors of a tab
**	Necessary for the get_light_value function
*/

static t_color	color_tab_sum(t_color *c, t_env *e)
{
	t_color	k;
	int		i;

	k = e->backgroundcolor;
	i = -1;
	while (++i < e->nbs[LIGHT])
		k = add_2colors(k, c[i]);
	return (k);
}

/*
**	GET_LIGHT_VALUE function:
**	Calculation of the light value from diffusion and lighting
**	(Lambert diffusion & Blinn-Phuong reflection)
*/

t_color			get_light_value(t_work w, t_vec impact, t_mat mat, t_env *e)
{
	int		j;
	t_vec	dist;
	t_ray	lray;
	t_color	c[e->nbs[LIGHT]];

	j = -1;
	while (++j < e->nbs[LIGHT])
	{
		c[j] = newcolor(0, 0, 0);
		dist = sub(e->light[j].pos, impact);
		if (dotproduct(w.n_vec, dist) <= 0.0f || magnitude(dist) <= 0.0f)
			continue;
		lray.start = impact;
		lray.dir = normalize(dist);
		color_lambert(&c[j], lambert(lray, w.n_vec), e->light[j],
				find_texture_color(impact, w, e));
		color_blinnphong(&c[j], blinnphong(lray, &w.r, w.n_vec, mat),
				e->light[j]);
		c[j] = multp_color(c[j], e->light[j].radius
				? shadow_from_sphere(e->light[j], impact, w, e)
				: shadow_from_point(lray, dist, e));
	}
	return (add_2colors(lens_flaring(w.r, e), color_tab_sum(c, e)));
}

/*
**	SET_RAY_DIR function:
**	Calculation of the ray parameters from the x and y (screen parameters)
*/

t_vec			set_ray_dir(double x, double y, t_env *e)
{
	t_vec	i;
	t_vec	j;
	t_vec	k;
	t_vec	l;

	k = e->cam->dir;
	l = (e->initcam.dir.x == 0.0f && e->initcam.dir.y == 1.0f
			&& e->initcam.dir.z == 0.0f) ? newvec(0.0, 0.0, 1.0)
		: newvec(0.0, 1.0, 0.0);
	i = crossproduct(k, l);
	j = crossproduct(i, k);
	l.x = (IMG_W - x * 2.0) / IMG_W * i.x
			+ (IMG_H - y * 2.0) / IMG_W * j.x + FOV * k.x;
	l.y = (IMG_W - x * 2.0) / IMG_W * i.y
			+ (IMG_H - y * 2.0) / IMG_W * j.y + FOV * k.y;
	l.z = (IMG_W - x * 2.0) / IMG_W * i.z
			+ (IMG_H - y * 2.0) / IMG_W * j.z + FOV * k.z;
	l = normalize(l);
	return (l);
}
