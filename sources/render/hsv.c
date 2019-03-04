/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:11:54 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/05 15:44:31 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hsv	color_to_hsv(t_color c)
{
	t_hsv		out;
	double		min;
	double		max;
	double		delta;

	min = (c.red < c.green) ? c.red : c.green;
	min = (min < c.blue) ? min : c.blue;
	max = (c.red > c.green) ? c.red : c.green;
	max = (max > c.blue) ? max : c.blue;
	delta = max - min;
	out.h = 0.0f;
	out.s = 0.0f;
	out.v = max;
	if (delta > 0.00001f && max == c.red)
		out.h = 60 * (fmod(((c.green - c.blue) / delta), 6));
	else if (delta > 0.00001f && max == c.green)
		out.h = 60 * (((c.blue - c.red) / delta) + 2);
	else if (delta > 0.00001f && max == c.blue)
		out.h = 60 * (((c.red - c.green) / delta) + 4);
	out.s = (max > 0.00001f) ? delta / max : 0.0f;
	if (out.h < 0.0f)
		out.h += 360.0f;
	return (out);
}

t_color	hsv_to_color(t_hsv hsv)
{
	double		c;
	double		h_prime;
	double		x;
	double		m;
	t_color		res;

	c = hsv.v * hsv.s;
	h_prime = fmod(hsv.h / 60.0f, 6);
	x = c * (1 - fabs(fmod(h_prime, 2) - 1));
	m = hsv.v - c;
	res = newcolor(0, 0, 0);
	if (0 <= h_prime && h_prime < 1)
		res = newcolor(c, x, 0);
	else if (1 <= h_prime && h_prime < 2)
		res = newcolor(x, c, 0);
	else if (2 <= h_prime && h_prime < 3)
		res = newcolor(0, c, x);
	else if (3 <= h_prime && h_prime < 4)
		res = newcolor(0, x, c);
	else if (4 <= h_prime && h_prime < 5)
		res = newcolor(x, 0, c);
	else if (5 <= h_prime && h_prime < 6)
		res = newcolor(c, 0, x);
	return (newcolor(res.red + m, res.green + m, res.blue + m));
}
