/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:25:35 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/25 18:17:52 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <float.h>
# include "rt.h"

typedef struct			s_attribut
{
	char				*name;
	char				*content;
}						t_attribut;

typedef struct			s_element
{
	char				*object;
	char				*end_object;
	int					nbr_attr;
	t_attribut			*attribut;
	int					nbr_element;
	struct s_element	*elem;
	int					position;
	int					end;
}						t_element;

int						std_err(int err);
t_element				parser_xml(char *filename, t_element elem);
t_element				recursive_elem(char *xml, t_element element);
t_element				find_nbr_attr(char *xml, t_element element);
t_element				find_balise_name2(char *xml,\
		t_element element, int count);
t_element				find_attr_elem2(char *xml, t_element e, int *i);
t_element				find_nbr_elem2(char *xml, t_element element, int count);

t_env					*recup_env(t_env *e, t_element elem);
t_env					*recup_light(t_env *e, t_element elem);
t_env					*recup_camera(t_env *e, t_element elem);
t_mat					*recup_mat(t_env *e, t_element elem);
t_env					*recup_object(t_env *e, t_element elem, t_mat *mat);

int						get_sphere(t_env *e,\
		t_element elem, int i, int nbr_mat);
int						get_plane(t_env *e, t_element elem, int i, int nbr_mat);
int						get_lcyl(t_env *e, t_element elem, int i, int nbr_mat);
int						get_lcone(t_env *e, t_element elem, int i, int nbr_mat);
int						get_disk(t_env *e, t_element elem, int i, int nbr_mat);
int						get_fcyl(t_env *e, t_element elem, int i, int nbr_mat);
int						get_fcone(t_env *e, t_element elem, int i, int nbr_mat);
int						get_box(t_env *e, t_element elem, int i, int nbr_mat);
int						get_quadric(t_env *e, t_element elem, int i, \
		int nbr_mat);

int						get_center(t_env *e, t_element elem, int i, char *name);
int						get_radius(t_env *e, t_element elem, int i);
int						get_material(t_env *e,\
		t_element elem, int i, int nbr_mat);
int						get_dir(t_env *e, t_element elem, int i, char *name);
int						get_d(t_env *e, t_element elem, int i);
int						get_angle(t_env *e, t_element elem, int i);
int						get_height(t_env *e, t_element elem, int i);
int						get_translation(t_env *e, t_element elem, int i);
int						get_rotation(t_env *e, t_element elem, int i);
int						get_end(t_env *e, t_element elem, int i, char *name);
int						recup_value_mat(t_mat *mat, t_element elem, int i);
int						recup_value_text(t_mat *mat, t_element elem, int i);
int						get_bump(t_mat *mat, t_element elem, int i);
int						get_isnega(t_env *e, t_element elem, int i);
int						get_sizequadric(t_env *e, t_element elem, int i);
int						get_param(t_env *e, t_element elem, int i, char *name);
int						recup_value_checker(t_mat *mat, t_element elem, int i);
void					clean_value_mat(t_mat *mat, int j);
int						recup_checker_mat(t_mat *mat, t_element elem, int i,\
		char *name);
int						recup_tr(t_env *e, t_element elem, int i);

t_vec					ft_getpos(char *pos);
t_color					ft_getcolor(char *color);
double					ft_posatoi(char *nbr);

void					open_textures_mat(t_env *e);

t_env					*parser_all(char *file, t_env *e);
#endif
