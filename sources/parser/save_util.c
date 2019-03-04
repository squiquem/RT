/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:52:11 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/11 20:58:37 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	SAVE_NAME_VAL function:
**	Write the name of the setting named name and write its value
*/

void		save_name_val(int fd, const char *name, double val)
{
	ft_putstr_fd(name, fd);
	save_val(fd, val);
	ft_putstr_fd("\"", fd);
}

/*
**	SAVE_VAL function:
**	Write the value in the save file, because of rounded doubles need to write
**	the first decimal
*/

void		save_val(int fd, double val)
{
	char	*s;

	if (val - (int)val != 0)
		s = ft_itoa((val - (int)val) * 10);
	else
		s = ft_itoa((int)val);
	ft_putstr_fd(s, fd);
	free(s);
}

/*
**	SAVE_POS function:
**	Save the vector named name with the proper style
*/

void		save_pos(int fd, const char *type, t_vec pos)
{
	ft_putstr_fd(type, fd);
	save_val(fd, pos.x);
	ft_putchar_fd(',', fd);
	save_val(fd, pos.y);
	ft_putchar_fd(',', fd);
	save_val(fd, pos.z);
	ft_putchar_fd('\"', fd);
}

/*
**	SAVE_COLOR function:
**	Save a color for a material with the proper style
*/

void		save_color(int fd, const char *type, t_color color)
{
	ft_putstr_fd(type, fd);
	save_val(fd, color.red);
	ft_putchar_fd(',', fd);
	save_val(fd, color.green);
	ft_putchar_fd(',', fd);
	save_val(fd, color.blue);
	ft_putchar_fd('\"', fd);
}
