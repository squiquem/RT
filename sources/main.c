/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:07:15 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/22 19:27:55 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "parser.h"
#include "hud.h"

/*
**	QUIT function:
**	Quits when clicking on the red cross
*/

int			quit(void)
{
	ft_putendl("bye (;'-')/");
	exit(1);
	return (0);
}

/*
**	FILENAME_CONTROL function:
**	Controls if the filename ends with ".xml"
*/

static void	filename_control(char *av)
{
	if (ft_strcmp(av + ft_strlen(av) - 4, ".xml"))
		ft_printerror("Please use valid file");
}

/*
**	INIT function:
**	Feeds some env variables
*/

static void	init(t_env *e)
{
	e->hit[SPHERE] = &hitsphere;
	e->hit[PLANE] = &hitplane;
	e->hit[I_CYL] = &hitcylinder;
	e->hit[I_CONE] = &hitcone;
	e->hit[DISK] = &hitdisk;
	e->hit[F_CYL] = &hitfcylinder;
	e->hit[F_CONE] = &hitfcone;
	e->hit[BOX] = &hitbox;
	e->hit[QUADRIC] = &hitquadric;
	e->backgroundcolor = multp_color(e->backgroundcolor, 0.00392156862);
	e->lvl = 4;
	e->antialiasing = 1;
	e->initcam = *e->cam;
	create_axis(e);
	e->img[CENTER].s_line = 0;
	ft_memset(e->key, 0, sizeof(int) * 300);
	ft_memset(e->itf.spec, 0, sizeof(e->itf.spec));
	e->itf.onglet = 1;
	ft_memset(e->itf.spectrum, 0, sizeof(e->itf.spectrum));
	e->loading = 0;
	e->cartoon = 0;
	reset_values(e);
}

/*
**	MAIN function:
*/

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_printerror("Only 1 argument");
	filename_control(av[1]);
	parser_all(av[1], &e);
	e.save.name = av[1];
	if (!(e.mlx = mlx_init()))
		ft_printerror("Error mlx init");
	open_textures_mat(&e);
	init(&e);
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, av[1]);
	mlx_centertop_window(e.win);
	new_image(&e.img[CENTER], IMG_W, IMG_H, &e);
	hud(&e);
	mlx_loop_hook(e.mlx, reload, &e);
	mlx_hook(e.win, KPRESS, KPRESSMASK, keypress, &e);
	mlx_hook(e.win, KRELEASE, KRELEASEMASK, keyrelease, &e);
	mlx_hook(e.win, MOTION_NOTIFY, PTR_MOTION_MASK, mousemove, &e);
	mlx_hook(e.win, BPRESS, BPRESSMASK, &mousepress, &e);
	mlx_hook(e.win, BRELEASE, BRELEASEMASK, &mouserelease, &e);
	mlx_hook(e.win, DESTROY, SNOTIFYMASK, quit, &e);
	mlx_loop(e.mlx);
	return (1);
}
