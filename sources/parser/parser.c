/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:02:48 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/28 15:48:20 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_element		test_conf(t_element elem, char *tmp)
{
	elem = recursive_elem(tmp, elem);
	ft_memdel((void**)&tmp);
	return (elem);
}

t_element		parser_xml(char *filename, t_element elem)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (!(tmp = ft_strnew(0)))
		std_err(0);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (!(ft_isascii(line[0])))
			std_err(0);
		if (!(tmp = ft_strjoinfree(tmp, line, 3)))
			std_err(0);
		if (!(tmp = ft_strjoinfree(tmp, "\n", 1)))
			std_err(0);
	}
	if (i == -1)
		std_err(0);
	elem = test_conf(elem, tmp);
	return (elem);
}
