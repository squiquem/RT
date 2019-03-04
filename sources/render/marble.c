/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:55:20 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/20 15:38:35 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_marble(t_color c1, t_color c2, t_vec impact, double s)
{
	int		lvl;
	double	noisecoef;

	lvl = 0;
	noisecoef = 0;
	impact = scale(s, impact);
	while (++lvl < 10)
		noisecoef += (1.0f / lvl) * fabs(noise(lvl * impact.x, lvl * impact.y,
					lvl * impact.z));
	noisecoef = 0.5f * sin((impact.x + impact.y) * s + noisecoef) + 0.5f;
	noisecoef = ft_clamp(0, 1, noisecoef);
	return (add_2colors(multp_color(c1, noisecoef),
				multp_color(c2, 1.0f - noisecoef)));
}

t_color	color_turbulence(t_color c1, t_color c2, t_vec impact, double s)
{
	int		lvl;
	double	noisecoef;

	lvl = 0;
	noisecoef = 0;
	impact = scale(s, impact);
	while (++lvl < 10)
		noisecoef += (1.0f / lvl) * fabs(noise(lvl * impact.x, lvl * impact.y,
					lvl * impact.z));
	noisecoef = ft_clamp(0, 1, noisecoef);
	return (add_2colors(multp_color(c1, noisecoef),
				multp_color(c2, 1.0f - noisecoef)));
}

t_color	color_wood(t_color c1, t_color c2, t_vec impact, double s)
{
	double	grain;

	impact = scale(s, impact);
	grain = 20 * noise(impact.x, impact.y, impact.z);
	grain = grain - (int)grain;
	grain = ft_clamp(0, 1, grain);
	return (add_2colors(multp_color(c1, grain),
				multp_color(c2, 1.0f - grain)));
}

t_vec	bumpmapping(t_vec n, t_vec impact, t_mat m)
{
	t_vec	noisecoef;
	t_vec	res;

	if (!m.bump)
		return (n);
	noisecoef.x = noise(0.1 * impact.x, 0.1 * impact.y, 0.1 * impact.z);
	noisecoef.y = noise(0.1 * impact.y, 0.1 * impact.z, 0.1 * impact.x);
	noisecoef.z = noise(0.1 * impact.z, 0.1 * impact.x, 0.1 * impact.y);
	res = add(scale(1.0f - m.bump, n), scale(m.bump, noisecoef));
	return (normalize(res));
}
