/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:26:24 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/16 21:21:02 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	l1;
	int				i;

	l1 = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[i + l1] = src[i];
		i++;
	}
	dest[i + l1] = '\0';
	return (dest);
}
