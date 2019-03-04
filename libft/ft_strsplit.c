/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:21:07 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/20 20:12:38 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbwords(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		i++;
	}
	return (i);
}

static void	copy(char *dest, char *src, char *end)
{
	char	*d;

	d = dest;
	while (src <= end)
	{
		*d = *src;
		d++;
		src++;
	}
	*d = '\0';
}

static int	make_elm(char **arr, int i, char *start, int len)
{
	if (!(arr[i] = (char *)malloc(len + 1)))
		return (0);
	copy(arr[i], start, start + len - 1);
	i++;
	return (i);
}

static char	**make_array(char **arr, char const *s, char c)
{
	char	*cp;
	char	*start;
	int		i;
	int		len;

	cp = (char *)s;
	i = 0;
	while (*cp)
	{
		len = 0;
		while (*cp == c)
			cp++;
		start = cp;
		while (*cp != c && *cp)
		{
			len++;
			cp++;
		}
		if (len)
			i = make_elm(arr, i, start, len);
	}
	arr[i] = 0;
	return (arr);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**s;

	if (!str || !c)
		return (NULL);
	if (!(s = (char **)malloc(sizeof(char *) * (nbwords((char *)str, c) + 1))))
		return (NULL);
	s = make_array(s, str, c);
	return (s);
}
