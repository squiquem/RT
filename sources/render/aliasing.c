/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliasing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:14:18 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/20 15:27:20 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	SUPERSAMPLING function:
**	Calculates the average color from several rays built from each pixel
*/

void		supersampling(int k, t_pix p, t_env *e)
{
	t_color	c;
	int		i;
	int		j;

	if (k <= 0)
		ft_printerror("Antialiasing value incorrect");
	c = newcolor(0, 0, 0);
	i = -1;
	while (++i < k)
	{
		j = -1;
		while (++j < k)
			c = add_2colors(c, color_calc((double)p.x + (double)i / k,
						(double)p.y + (double)j / k, e));
	}
	c = multp_color(c, 1.0f / (k * k));
	draw_point(&e->img[CENTER], p.x, p.y, c);
}

/*
**	ALIASING function:
**	Decreases precision in order to increase the speed
*/

void		aliasing(int k, t_pix p, t_env *e)
{
	t_color	c;
	int		i;
	int		j;

	if (k <= 0)
		ft_printerror("Aliasing value incorrect");
	if (!(p.x % k) && !(p.y % k))
	{
		i = -1;
		c = color_calc((double)p.x, (double)p.y, e);
		while (++i < k)
		{
			j = -1;
			while (++j < k)
				draw_point(&e->img[CENTER], p.x + i, p.y + j, c);
		}
	}
	else
		return ;
}
