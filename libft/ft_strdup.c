/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:26:24 by squiquem          #+#    #+#             */
/*   Updated: 2017/12/05 22:56:43 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *s;

	if (!(s = (char*)malloc(sizeof(*s) * (ft_strlen(src) + 1))))
		return (NULL);
	return (ft_strcpy(s, src));
}
