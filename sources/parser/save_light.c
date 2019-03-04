/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:00:44 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/11 20:53:04 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	SAVE_LIGHT function:
**	Save the settings for the light in the scene
*/

void		save_light(int fd, t_env *e)
{
	int		i;

	ft_putendl_fd("\t<light>", fd);
	i = -1;
	while (++i < e->nbs[LIGHT])
	{
		ft_putstr_fd("\t\t<sublight", fd);
		save_pos(fd, " pos=\"", e->light[i].pos);
		save_color(fd, " intensity=\"", e->light[i].intensity);
		save_name_val(fd, " radius=\"", e->light[i].radius);
		ft_putendl_fd("/>", fd);
	}
	ft_putstr_fd("\t\t<ambiant", fd);
	save_color(fd, " color=\"", e->backgroundcolor);
	ft_putendl_fd("/>", fd);
	ft_putendl_fd("\t</light>", fd);
}

/*
**	SAVE_CAMERA function:
**	Save the settings for the camera in the scene
*/

void		save_camera(int fd, t_cam cam)
{
	char	*s;

	ft_putstr_fd("\t<camera", fd);
	ft_putstr_fd(" pos=\"", fd);
	ft_putstr_fd(s = ft_itoa((int)cam.pos.x), fd);
	free(s);
	ft_putchar_fd(',', fd);
	ft_putstr_fd(s = ft_itoa((int)cam.pos.y), fd);
	free(s);
	ft_putchar_fd(',', fd);
	ft_putstr_fd(s = ft_itoa((int)cam.pos.z), fd);
	free(s);
	ft_putchar_fd('\"', fd);
	save_pos(fd, " dir=\"", cam.dir);
	ft_putendl_fd("/>", fd);
}
