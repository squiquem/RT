/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:26:24 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/16 23:01:54 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int ld;
	unsigned int ls;

	if (size < ft_strlen(dest))
		ld = size;
	else
		ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (ld == size)
		return (size + ls);
	if (ls < size - ld)
		ft_strncat(dest, src, ls + 1);
	else
	{
		ft_strncat(dest, src, size - ld - 1);
		dest[size - 1] = '\0';
	}
	return (ld + ls);
}
