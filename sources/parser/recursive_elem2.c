/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_elem2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:23:15 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/19 16:54:07 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_element		find_balise_name2(char *xml, t_element element, int count)
{
	if (count == 0)
		std_err(0);
	if (!(element.object = (char*)malloc(sizeof(char) * count + 1)))
		std_err(0);
	ft_strncpy(element.object, xml + element.position - count, count);
	element.object[count] = 0;
	if (!(element.end_object = (char*)malloc(sizeof(char) * count + 4)))
		std_err(0);
	element.end_object[0] = '<';
	element.end_object[1] = '/';
	ft_strncpy(element.end_object + 2, element.object, count);
	element.end_object[count + 2] = '>';
	element.end_object[count + 3] = 0;
	if (xml[element.position] != '>' && xml[element.position] != ' '
			&& xml[element.position] != '/')
		std_err(0);
	return (element);
}

t_element		find_attr_elem2(char *xml, t_element e, int *i)
{
	i[2] = 0;
	while (xml[i[0]] <= 'z' && xml[i[0]] >= 'a')
	{
		i[2]++;
		i[0]++;
	}
	if (!(e.attribut[i[1]].name = (char*)malloc(sizeof(char) * i[2] + 1)))
		std_err(0);
	ft_strncpy(e.attribut[i[1]].name, xml + i[0] - i[2], i[2]);
	e.attribut[i[1]].name[i[2]] = 0;
	i[0] += 2;
	i[2] = 0;
	while (xml[i[0]] != '"')
	{
		i[2]++;
		i[0]++;
	}
	if (!(e.attribut[i[1]].content = (char*)malloc(sizeof(char)
					* i[2] + 1)))
		std_err(0);
	ft_strncpy(e.attribut[i[1]].content, xml + i[0] - i[2], i[2]);
	e.attribut[i[1]].content[i[2]] = 0;
	i[1]++;
	return (e);
}

t_element		find_nbr_elem2(char *xml, t_element element, int count)
{
	char name[count + 1];

	ft_strncpy(name, xml + element.position - count, count);
	name[count] = 0;
	while (xml[element.position] != '>' && xml[element.position])
		element.position++;
	if (xml[element.position - 1] == '/')
	{
		element.nbr_element++;
		return (element);
	}
	while (xml[element.position])
	{
		if (xml[element.position] == '<')
		{
			if (ft_strncmp(xml + element.position + 2, name, count) == 0
					&& xml[element.position + 1] == '/')
			{
				element.nbr_element++;
				return (element);
			}
		}
		element.position++;
	}
	return (element);
}
