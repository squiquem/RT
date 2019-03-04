/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:55:34 by sderet            #+#    #+#             */
/*   Updated: 2018/06/28 16:55:39 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_i(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static void		ft_if_one(char **str, char **line, int i)
{
	*line = ft_strsub(*str, 0, i);
	*str = ft_strsubf(*str, i + 1, ((ft_strlen(*str) - i)) - 1);
}

static void		ft_if_two(char **str, char **line)
{
	*line = ft_strdup(*str);
	ft_strdel(str);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str;

	ret = 0;
	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	if (str == NULL || ft_strchr(str, '\n') == NULL)
	{
		str = (!str) ? ft_strnew(0) : str;
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			str = ft_strjoinfree(str, buf, 1);
			if (ft_strchr(str, '\n') != NULL)
				break ;
		}
		if (ret < BUFF_SIZE && str[0] == '\0')
			return (0);
	}
	if (str && ft_strchr(str, '\n') != NULL)
		ft_if_one(&str, line, ft_i(str));
	else if (str && ft_strchr(str, '\n') == NULL)
		ft_if_two(&str, line);
	return (1);
}
