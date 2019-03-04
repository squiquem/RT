/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:42:55 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/20 19:20:40 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*last;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	while (*s && ft_whitespace(*s))
		s++;
	last = (char *)s + ft_strlen(s) - 1;
	while (last > s && ft_whitespace(*last))
		last--;
	len = ft_strlen(s) - ft_strlen(last) + 1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
