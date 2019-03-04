/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:36:19 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/20 15:23:18 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	complete_name(char *name)
{
	int		i;

	i = -1;
	while (name[++i])
		if (name[i] == ' ')
			name[i] = '_';
}

static void	scene_name(t_save *save)
{
	char	*cdate;
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = ft_strstr(save->name, ".xml");
	if (!(tmp2 = ft_strrchr(save->name, '/')))
		i = ft_strlen(save->name) - 4;
	else
		i = (int)(tmp - tmp2);
	if (!(save->scene = ft_memalloc(sizeof(char) * (i + 37))))
		ft_printerror("Error malloc");
	save->scene = ft_strcpy(save->scene, "scenes/");
	if (tmp2 == NULL)
		save->scene = ft_strncat(save->scene, save->name, i);
	else
		save->scene = ft_strncat(save->scene, tmp2 + 1, i - 1);
	save->scene = ft_strcat(save->scene, "_");
	save->start = time(NULL);
	cdate = ctime(&(save->start));
	save->scene = ft_strncat(save->scene, cdate, 24);
	save->scene = ft_strcat(save->scene, ".xml");
	complete_name(save->scene);
}

/*
**	SAVE function:
**	Overwrite the opened file if state == 0 or create a new save file
*/

void		save(int state, t_env *e)
{
	if (state)
		scene_name(&e->save);
	else
		e->save.scene = e->save.name;
	if ((e->save.fd = open(e->save.scene, O_WRONLY | O_TRUNC | O_CREAT, 0644))
			< 0)
		ft_printerror("Error open new file");
	ft_putendl_fd("\n<scene>", e->save.fd);
	save_light(e->save.fd, e);
	save_camera(e->save.fd, *(e->cam));
	save_material(e->save.fd, e->nbs[MAT], e->mat);
	save_item(e->save.fd, e->nbs[ITEM], e->item);
	ft_putendl_fd("</scene>", e->save.fd);
	if (close(e->save.fd) < 0)
		ft_printerror("Error close file");
	ft_putstr(e->save.scene);
	ft_putendl(" saved \\o/");
	if (state)
		free(e->save.scene);
	save_load(e);
}
