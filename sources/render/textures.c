/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:12:07 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/19 19:14:34 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	find_texture_color(t_vec impact, t_work w, t_env *e)
{
	t_mat	m;
	t_item	item;

	item = e->item[w.item_hit];
	m = e->mat[item.mat];
	if (m.type == UNIFORM)
		return (m.diffuse);
	else if (m.type == TEXTURE || m.type == CHECKER || m.type == WAVES)
	{
		if (item.item_type == PLANE)
			return (texture_plane(m.tex, item, impact));
		else if (item.item_type == SPHERE)
			return (texture_sphere(m.tex, item, w));
		else if (item.item_type == I_CYL || item.item_type == F_CYL)
			return (texture_cylinder(m.tex, item, impact));
		else
			return (texture_cone(m.tex, item, impact));
	}
	else if (m.type == MARBLE)
		return (color_marble(m.diffuse, m.diffuse2, impact, m.scale));
	else if (m.type == PERTURB)
		return (color_turbulence(m.diffuse, m.diffuse2, impact, m.scale));
	else
		return (color_wood(m.diffuse, m.diffuse2, impact, m.scale / 2));
}

t_color	texture_plane(t_img tex, t_item item, t_vec impact)
{
	t_color	c;
	t_vec	d;
	t_vec	u;
	t_pix	p;

	if (magnitude(tex.center) && (fabs(dotproduct(item.dir, tex.center)
					+ item.d) > 0.01f))
		tex.center = newvec(0, 0, 0);
	d = sub(impact, tex.center);
	u = (d.x == 0 && d.x == 0 && d.z == 1) ? newvec(0, 1, 0) : newvec(0, 0, 1);
	if (u.x == item.dir.x && u.y == item.dir.y && u.z == item.dir.z)
		u = newvec(1, 0, 0);
	p.x = (int)(dotproduct(d, u) * tex.w / tex.realw + tex.w / 2);
	p.y = (int)(dotproduct(d, crossproduct(item.dir, u)) * tex.h / tex.realh
			+ tex.h / 2);
	p = rotate_pix(p, tex.w, tex.h, tex.angle);
	return (get_img_color(tex, p, &c));
}

t_color	texture_sphere(t_img tex, t_item item, t_work w)
{
	t_color	c;
	t_pix	p;
	t_vec	k;

	if (magnitude(tex.center) && (fabs(magnitude(sub(item.center, tex.center))
					- item.radius) > 0.01f))
		tex.center = newvec(0, 0, 0);
	if (magnitude(item.center))
		k = normalize(sub(tex.center, item.center));
	p.x = (int)(((magnitude(tex.center) ? atan2(k.z, k.x) : 0.5)
				- atan2(w.n_vec.z, w.n_vec.x)) / (2 * M_PI) * tex.w * 1.5
			* item.radius / tex.realw + tex.w / 2);
	p.y = (int)((asin(w.n_vec.y) - (magnitude(tex.center) ? asin(k.y) : 0))
			/ M_PI * tex.h * 1.5 * item.radius / tex.realh + tex.h / 2);
	p = rotate_pix(p, tex.w, tex.h, tex.angle);
	return (get_img_color(tex, p, &c));
}

t_color	texture_cylinder(t_img tex, t_item item, t_vec impact)
{
	t_color		c;
	t_pix		p;
	t_matrix	m;
	t_vec		v;
	t_vec		u;

	if (magnitude(tex.center) && (fabs(magnitude(sub(sub(item.center
								, tex.center), scale(dotproduct(sub(item.center
											, tex.center), item.dir)
									, item.dir))) - item.radius) > 0.01f))
		tex.center = newvec(0, 0, 0);
	u = sub(impact, item.center);
	v = sub(tex.center, item.center);
	m.col2 = crossproduct(item.dir, ((item.dir.x == 0 && item.dir.y == 0
					&& item.dir.z == 1) ? newvec(0, 1, 0) : newvec(0, 0, 1)));
	m.col3 = crossproduct(item.dir, m.col2);
	p.x = (int)((dotproduct(u, item.dir) - dotproduct(v, item.dir))
			* item.radius / tex.realw + tex.w / 2);
	p.y = (int)((atan(dotproduct(u, m.col2) / dotproduct(u, m.col3))
				- (magnitude(tex.center) ? atan(dotproduct(v, m.col2)
						/ dotproduct(v, m.col3)) : 0)) / M_PI * 2 * tex.h
			* item.radius / tex.realh + tex.h / 2);
	p = rotate_pix(p, tex.w, tex.h, tex.angle);
	return (get_img_color(tex, p, &c));
}

t_color	texture_cone(t_img t, t_item i, t_vec impact)
{
	t_color		c;
	t_pix		p;
	t_matrix	m;
	t_vec		v;
	t_vec		u;

	if (magnitude(t.center)
			&& (fabs(magnitude(sub(sub(i.center, t.center),
							scale(dotproduct(sub(i.center, t.center), i.dir),
								i.dir))) - magnitude(sub(impact, i.center))
					* cos(i.angle * M_PI / 180)) > 0.01f))
		t.center = newvec(0, 0, 0);
	u = sub(impact, i.center);
	v = sub(t.center, i.center);
	m.col2 = crossproduct(i.dir, ((i.dir.x == 0 && i.dir.y == 0
					&& i.dir.z == 1) ? newvec(0, 1, 0) : newvec(0, 0, 1)));
	m.col3 = crossproduct(i.dir, m.col2);
	p.x = (int)((dotproduct(u, i.dir) - dotproduct(v, i.dir))
			* 150 / t.realw + t.w / 2);
	p.y = (int)((atan(dotproduct(u, m.col2) / dotproduct(u, m.col3))
				- (magnitude(t.center) ? atan(dotproduct(v, m.col2)
						/ dotproduct(v, m.col3))
					: 0)) / M_PI * 2 * t.h * 150 / t.realh + t.h / 2);
	p = rotate_pix(p, t.w, t.h, t.angle);
	return (get_img_color(t, p, &c));
}
