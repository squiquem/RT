/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:27:07 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/21 13:58:16 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	FIND_TEXTURE function:
**	Find the right texture number for a picked item
*/

static void	find_texture(t_env *e)
{
	e->itf.nb_texture = 0;
	if (e->itf.mat.type == 1)
	{
		if (!ft_strcmp(e->itf.mat.path_text, "textures/redbrick.xpm"))
			e->itf.nb_texture = 1;
		else if (!ft_strcmp(e->itf.mat.path_text, "textures/bluestone.xpm"))
			e->itf.nb_texture = 2;
		else if (!ft_strcmp(e->itf.mat.path_text, "textures/colorstone.xpm"))
			e->itf.nb_texture = 3;
		else if (!ft_strcmp(e->itf.mat.path_text, "textures/wood.xpm"))
			e->itf.nb_texture = 4;
	}
}

/*
**	WRITE_ITEM function
**	Write the category of the picked item and its material number
*/

static void	write_item(char *s, t_env *e)
{
	if (s != NULL)
	{
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50, BLACK, s);
		free(s);
		s = ft_itoa(e->itf.item.mat);
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100, BLACK, s);
		free(s);
	}
}

/*
**	ITEM_SELECTOR function:
**	Find the right type of the picked item
*/

static void	item_selector(t_env *e)
{
	char	*s;

	if (e->itf.item.item_type == SPHERE)
		s = ft_strdup("Sphere");
	else if (e->itf.item.item_type == PLANE)
		s = ft_strdup("Plane");
	else if (e->itf.item.item_type == I_CONE)
		s = ft_strdup("Inf. Cone");
	else if (e->itf.item.item_type == I_CYL)
		s = ft_strdup("Inf. Cylinder");
	else if (e->itf.item.item_type == DISK)
		s = ft_strdup("Disk");
	else if (e->itf.item.item_type == F_CYL)
		s = ft_strdup("Fin. Cylinder");
	else if (e->itf.item.item_type == F_CONE)
		s = ft_strdup("Fin. Cone");
	else if (e->itf.item.item_type == BOX)
		s = ft_strdup("Box");
	else if (e->itf.item.item_type == QUADRIC)
		s = ft_strdup("Quadric");
	else
		s = NULL;
	write_item(s, e);
}

/*
**	PICKED_ITEM function:
**	Write some strings on tab 1 and call the others functions to write item type
**	and material number
*/

void		picked_item(t_env *e)
{
	t_rect	rect;

	mlx_string_put(e->mlx, e->win, IMG_W + 5, 50, BLACK, "Item:");
	rect = init_rect(IMG_W + 7, 72, 42, 2);
	draw_line(rect, BLACK, e);
	if (e->itf.pick.button == -1)
	{
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50,
				BLACK, "None");
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100,
				BLACK, "None");
	}
	else
		item_selector(e);
	mlx_string_put(e->mlx, e->win, IMG_W + 5, 100, BLACK, "Mat.:");
	rect = init_rect(IMG_W + 7, 122, 42, 2);
	draw_line(rect, BLACK, e);
}

/*
**	PICK_ITEM function:
**	Find the right item pointed by mouse pointer by throwing a ray to this item
**	and set values to work on its material
*/

int			pick_item(t_mouse mouse, t_env *e)
{
	t_ray	r;
	t_vec	impact;
	int		nb;

	if (mouse.x > 0 && mouse.x < IMG_W && mouse.y > 0 && mouse.y < IMG_H)
	{
		r.start = e->cam->pos;
		r.dir = set_ray_dir(mouse.x, mouse.y, e);
		nb = find_closest_item2(r, e, &impact) % (e->nbs[ITEM] + 1);
		if (nb != e->itf.pick.button && nb != -1)
		{
			e->itf.pick.button = nb;
			e->itf.pick.x = mouse.x;
			e->itf.pick.y = mouse.y;
			e->itf.mat = e->mat[e->item[nb].mat];
			e->itf.item = e->item[nb];
			e->itf.mouse.button = -1;
			find_texture(e);
			fill_param(e);
		}
		else
			reset_values(e);
	}
	return (0);
}
