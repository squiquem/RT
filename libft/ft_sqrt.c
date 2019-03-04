/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:29:57 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/16 22:21:35 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	carre(int x)
{
	return (x * x);
}

int				ft_sqrt(size_t nb)
{
	unsigned int	a;
	unsigned int	z;

	if (nb == 0)
		return (0);
	a = 0;
	z = 46342;
	while (1)
	{
		if (nb > carre((a + z) / 2))
			a = (a + z) / 2;
		if (nb < carre((a + z) / 2))
			z = (a + z) / 2;
		if (carre((a + z) / 2) == nb)
			return ((a + z) / 2);
		if (z - a <= 1)
			return (0);
	}
}
