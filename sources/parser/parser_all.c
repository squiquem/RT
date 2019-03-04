/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:51:09 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/08 22:20:20 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

t_env		*parser_all(char *file, t_env *e)
{
	t_element	elem;

	elem.nbr_attr = 0;
	elem = parser_xml(file, elem);
	e = recup_env(e, elem);
	e->cam->dir = normalize(e->cam->dir);
	e->nbs[CAM] = 1;
	return (e);
}

void		open_textures_mat(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nbs[MAT])
	{
		if (e->mat[i].type == TEXTURE)
			open_texture(e, &(e->mat[i].tex), e->mat[i].path_text);
		i++;
	}
}
