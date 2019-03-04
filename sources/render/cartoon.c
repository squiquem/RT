/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:09:02 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/18 19:36:30 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t			limit_clr(size_t col)
{
	if (col <= 0)
		return (0);
	else if (col > 0 && col <= 50)
		return (25);
	else if (col > 50 && col <= 100)
		return (75);
	else if (col > 100 && col <= 200)
		return (150);
	else if (col > 200 && col < 250)
		return (225);
	else if (col >= 255)
		return (255);
	return (col);
}

static void		init_tab_cartoon(short tab[3][3], char type)
{
	tab[0][0] = -1;
	tab[0][1] = (type == 'X') ? 0 : -2;
	tab[0][2] = (type == 'X') ? 1 : -1;
	tab[1][0] = (type == 'X') ? -2 : 0;
	tab[1][1] = 0;
	tab[1][2] = (type == 'X') ? 2 : 0;
	tab[2][0] = (type == 'X') ? -1 : 1;
	tab[2][1] = (type == 'X') ? 0 : 2;
	tab[2][2] = 1;
}

int				x_g(t_env *e, t_pix p, char type)
{
	t_pix	q;
	int		res;
	short	tab[3][3];
	t_color	c;

	res = 0;
	init_tab_cartoon(tab, type);
	q.y = -2;
	while (++q.y < 2)
	{
		q.x = -2;
		while (++q.x < 2)
		{
			c = get_pt_color(p.x + q.x, p.y + q.y, e->img[CENTER]);
			res += tab[q.y + 1][q.x + 1]
				* ((int)c.red + (int)c.green + (int)c.blue) / 3;
		}
	}
	return (res);
}
