/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3_writting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:13:48 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 16:59:56 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	N_PARAM function:
**	Proper write of the n parameter value
*/

static char	*n_param(double n)
{
	char	*tmp;
	char	*tmp2;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n == 10 || n == 20)
			return (ft_itoa((int)n / 10));
		tmp = ft_strjoinfree(ft_itoa((int)n / 10), ".", 1);
		tmp2 = ft_strjoinfree(tmp, ft_itoa((int)n - 10), 3);
		return (tmp2);
	}
}

/*
**	SCALE_PARAM function:
**	Simplier display for the scale parameter value
*/

static char	*scale_param(double scale)
{
	if ((int)scale < 10 && (int)scale > 0)
		return (ft_itoa(0));
	else if (scale > 9)
		return (ft_itoa(1));
	else if ((int)((scale - (int)scale) * 10) > 0
			&& (scale - (int)scale) * 10 < 10)
		return (ft_itoa(-1));
	else if ((int)((scale - (int)scale) * 100) > 0
			&& (scale - (int)scale) * 100 < 10)
		return (ft_itoa(-2));
	else
		return (ft_itoa(-3));
}

/*
**	WRITE_PARAM_VAL function:
**	Write the value for the selected parameter
*/

static void	write_param_val(t_env *e)
{
	char	*s;

	s = NULL;
	if (e->itf.mouse.button != -1)
	{
		if (e->itf.mouse.button != N && e->itf.mouse.button != SCALE)
		{
			s = ft_itoa((int)(e->itf.param[e->itf.mouse.button]));
			mlx_string_put(e->mlx, e->win, 2 * WIN_W / 5,
					IMG_H + 3 * BOTTOM_SPC / 8, BLACK, s);
			free(s);
		}
		else
		{
			if (e->itf.mouse.button == N)
				s = n_param(e->itf.param[N]);
			else
				s = scale_param(e->itf.param[SCALE]);
			mlx_string_put(e->mlx, e->win, 2 * WIN_W / 5,
					IMG_H + 3 * BOTTOM_SPC / 8, BLACK, s);
			free(s);
		}
	}
}

/*
**	FILL_STR function:
**	Fill the table with parameters name for display
*/

static void	fill_str(char **s)
{
	s[0] = "Reflection";
	s[1] = "Transparency";
	s[2] = "Spec. value";
	s[3] = "Spec. power";
	s[4] = "Refractive index";
	s[5] = "Bump";
	s[6] = "Scale";
	s[7] = NULL;
}

/*
**	UI3_WRITTING function:
**	Put on the image all the writtings for tab 3
*/

void		ui3_writting(t_env *e)
{
	char	*s[8];
	int		i;

	if (e->itf.pick.button != -1 && e->itf.mat.type != TEXTURE)
	{
		fill_str(s);
		i = -1;
		while (++i < 6)
			mlx_string_put(e->mlx, e->win, 30, IMG_H + 5 + i * 25, BLACK, s[i]);
		if (e->itf.mat.type == MARBLE || e->itf.mat.type == WOOD
				|| e->itf.mat.type == PERTURB)
			mlx_string_put(e->mlx, e->win, 30, IMG_H + 5 + i * 25, BLACK, s[i]);
		write_param_val(e);
	}
	mlx_string_put(e->mlx, e->win, IMG_W + 15, M_IMG_H - 30,
			BLACK, "Reflection number");
	s[0] = ft_itoa(e->lvl);
	mlx_string_put(e->mlx, e->win, IMG_W + RIGHT_SPC / 2 - 5, M_IMG_H + 10,
			BLACK, s[0]);
	free(s[0]);
	save_writting(e);
}
