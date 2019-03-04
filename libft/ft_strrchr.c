/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:00:57 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/20 19:41:14 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
		cp++;
	while (cp >= s)
	{
		if (*cp == (char)c)
			return (cp);
		cp--;
	}
	return (NULL);
}
