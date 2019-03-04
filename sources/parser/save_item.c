/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:32:52 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/11 20:53:27 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	radius_type(int fd, t_item item)
{
	if (item.item_type == SPHERE)
	{
		ft_putstr_fd("\t\t<sphere", fd);
		save_pos(fd, " center=\"", item.center);
	}
	else
	{
		if (item.item_type == I_CYL)
			ft_putstr_fd("\t\t<icyl", fd);
		else if (item.item_type == DISK)
			ft_putstr_fd("\t\t<disk", fd);
		else if (item.item_type == F_CYL)
			ft_putstr_fd("\t\t<fcyl", fd);
		save_pos(fd, " dir=\"", item.dir);
		save_pos(fd, " axispoint=\"", item.center);
	}
	save_name_val(fd, " radius=\"", item.radius);
	if (item.item_type == F_CYL)
		save_name_val(fd, " height=\"", item.height);
}

static void	cone_type(int fd, t_item item)
{
	if (item.item_type == I_CONE)
		ft_putstr_fd("\t\t<icone", fd);
	else
		ft_putstr_fd("\t\t<fcone", fd);
	save_pos(fd, " dir=\"", item.dir);
	save_pos(fd, " axispoint=\"", item.center);
	save_name_val(fd, " angle=\"", item.angle);
	if (item.item_type == F_CONE)
		save_name_val(fd, " height=\"", item.height);
}

static void	other_type(int fd, t_item item)
{
	if (item.item_type == PLANE)
	{
		ft_putstr_fd("\t\t<plane", fd);
		save_pos(fd, " normale=\"", item.dir);
		save_name_val(fd, " d=\"", item.d);
	}
	else if (item.item_type == BOX)
	{
		ft_putstr_fd("\t\t<box", fd);
		save_pos(fd, " start=\"", item.center);
		save_pos(fd, " end=\"", item.end);
	}
	else
	{
		ft_putstr_fd("\t\t<quadric", fd);
		save_pos(fd, " center=\"", item.center);
		save_pos(fd, " quadric=\"", item.quadric);
		save_name_val(fd, " sizequadric=\"", item.sizequadric);
	}
}

/*
**	SAVE_ITEM function:
**	Save the items settings in the save scene file
*/

void		save_item(int fd, int nbitem, t_item *item)
{
	int		i;

	ft_putendl_fd("\t<objects>", fd);
	i = -1;
	while (++i < nbitem)
	{
		if (item[i].item_type == SPHERE || item[i].item_type == DISK
				|| item[i].item_type == I_CYL || item[i].item_type == F_CYL)
			radius_type(fd, item[i]);
		else if (item[i].item_type == F_CONE || item[i].item_type == I_CONE)
			cone_type(fd, item[i]);
		else
			other_type(fd, item[i]);
		save_name_val(fd, " mat=\"", item[i].mat);
		if (item[i].item_type != PLANE)
			save_name_val(fd, " isneg=\"", item[i].isnega);
		ft_putendl_fd("/>", fd);
	}
	ft_putendl_fd("\t</objects>", fd);
}
