/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:35:37 by asarasy           #+#    #+#             */
/*   Updated: 2019/02/19 16:55:06 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_element		find_balise_name(char *xml, t_element element)
{
	int count;

	count = 0;
	while (xml[element.position])
	{
		if (xml[element.position] == '<')
		{
			element.position++;
			while (xml[element.position] > 96 && xml[element.position] < 123)
			{
				count++;
				element.position++;
			}
			return (find_balise_name2(xml, element, count));
		}
		element.position++;
	}
	std_err(0);
	return (element);
}

t_element		find_nbr_attr(char *xml, t_element element)
{
	int error;

	element.nbr_attr = 0;
	while (xml[element.position] != '>' && xml[element.position])
	{
		if (xml[element.position] >= 'a' && xml[element.position] <= 'z')
		{
			error = 0;
			while (xml[element.position] >= 'a' && xml[element.position] <= 'z')
				element.position++;
			if (xml[element.position] == '=' && xml[element.position + 1] == 34)
				error++;
			element.position += 2;
			while (xml[element.position] != '"' && xml[element.position] != '>'
					&& xml[element.position])
				element.position++;
			if (xml[element.position] != '"' || error == 0)
				std_err(0);
			element.nbr_attr++;
		}
		element.position++;
	}
	if (xml[element.position] != '>')
		std_err(0);
	return (element);
}

t_element		find_attr_elem(char *xml, t_element element)
{
	int i[3];

	i[1] = 0;
	i[0] = element.position;
	element = find_nbr_attr(xml, element);
	if (element.nbr_attr > 0)
	{
		if (!(element.attribut = (t_attribut*)malloc(sizeof(t_attribut)
					* element.nbr_attr)))
			std_err(0);
	}
	while (i[0] < element.position)
	{
		if (xml[i[0]] <= 'z' && xml[i[0]] >= 'a')
		{
			element = find_attr_elem2(xml, element, i);
		}
		i[0]++;
	}
	return (element);
}

t_element		find_nbr_elem(char *xml, t_element element)
{
	int		count;

	while (ft_strcmp(xml + element.position, ft_strstr(xml
					, element.end_object)) != 0 && xml[element.position])
	{
		if (xml[element.position] == '<')
		{
			element.position++;
			count = 0;
			while (xml[element.position] != '>' && xml[element.position] != ' '
					&& xml[element.position])
			{
				count++;
				element.position++;
			}
			element = find_nbr_elem2(xml, element, count);
		}
		element.position++;
	}
	if (!(element.elem = (t_element*)malloc(sizeof(t_element)
					* element.nbr_element)))
		std_err(0);
	while (xml[element.position] != '>' && xml[element.position])
		element.position++;
	return (element);
}

t_element		recursive_elem(char *xml, t_element element)
{
	int		i;
	int		count;

	element.position = 0;
	element.nbr_element = 0;
	i = 0;
	element = find_balise_name(xml, element);
	element = find_attr_elem(xml, element);
	if (xml[element.position - 1] == '/')
	{
		element.end = element.position;
		return (element);
	}
	count = element.position;
	element = find_nbr_elem(xml, element);
	element.end = element.position;
	if (element.nbr_element == 0)
		return (element);
	while (i < element.nbr_element)
	{
		element.elem[i] = recursive_elem(xml + count, element.elem[i]);
		count += element.elem[i].end;
		i++;
	}
	return (element);
}
