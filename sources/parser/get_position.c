/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:28:46 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/12 15:40:58 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

double		ft_posatoi(char *nbr)
{
	double	i;
	int		j;

	j = 0;
	i = ft_atoi(nbr);
	if (i < 0)
		std_err(0);
	while (nbr[j] >= '0' && nbr[j] <= '9')
		j++;
	if (nbr[j] != 0)
		std_err(0);
	return (i);
}

t_vec		ft_getpos2(char *pos, t_vec vec, int i)
{
	while (pos[i] >= '0' && pos[i] <= '9')
		i++;
	if (pos[i] != ',')
		std_err(0);
	i++;
	vec.z = ft_atoi(pos + i);
	if (pos[i] == '-')
		i++;
	if (pos[i] < '0' || pos[i] > '9')
		std_err(0);
	while (pos[i] >= '0' && pos[i] <= '9')
		i++;
	if (pos[i] != 0)
		std_err(0);
	return (vec);
}

t_vec		ft_getpos(char *pos)
{
	t_vec	vec;
	int		i;

	i = 0;
	vec.x = ft_atoi(pos);
	if (pos[i] == '-')
		i++;
	if (pos[i] < '0' || pos[i] > '9')
		std_err(0);
	while (pos[i] >= '0' && pos[i] <= '9')
		i++;
	if (pos[i] != ',')
		std_err(0);
	i++;
	vec.y = ft_atoi(pos + i);
	if (pos[i] == '-')
		i++;
	if (pos[i] < '0' || pos[i] > '9')
		std_err(0);
	vec = ft_getpos2(pos, vec, i);
	return (vec);
}

t_color		ft_getcolor2(char *pos, t_color col, int i)
{
	if (pos[i] != ',')
		std_err(0);
	i++;
	col.blue = ft_atoi(pos + i);
	if (pos[i] < '0' || pos[i] > '9')
		std_err(0);
	while (pos[i] >= '0' && pos[i] <= '9')
		i++;
	if (pos[i] != 0)
		std_err(0);
	if (col.red > 255 || col.blue > 255 || col.green > 255)
		std_err(0);
	if (col.red < 0 || col.blue < 0 || col.green < 0)
		std_err(0);
	return (col);
}

t_color		ft_getcolor(char *pos)
{
	t_color		col;
	int			i;

	i = 0;
	col.red = ft_atoi(pos);
	if (pos[i] < '0' || pos[i] > '9')
		std_err(0);
	while (pos[i] >= '0' && pos[i] <= '9')
		i++;
	if (pos[i] != ',')
		std_err(0);
	i++;
	col.green = ft_atoi(pos + i);
	if (pos[i] < '0' || pos[i] > '9')
		std_err(0);
	while (pos[i] >= '0' && pos[i] <= '9')
		i++;
	col = ft_getcolor2(pos, col, i);
	return (col);
}
