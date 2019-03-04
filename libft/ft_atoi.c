/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:50:39 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/16 16:05:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_aff(int p, const char *str)
{
	unsigned int	o;
	int				i;

	o = 0;
	i = p;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			o = o * 10 + str[i] - '0';
		if ((str[i] < '0' || str[i] > '9') && i == p)
			return (0);
		if ((str[i] < '0' || str[i] > '9') && i > p)
			return (o);
		if (o > INTMAX || (o == INTMAX && (!p || str[p - 1] != '-')))
			ft_printerror("N > intmax");
		i++;
	}
	return (o);
}

int					ft_atoi(const char *str)
{
	unsigned int	k;

	k = 0;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\v'
			|| str[k] == '\f' || str[k] == '\r' || str[k] == '\n')
		k++;
	if (str[k] == '-')
		return ((int)(-1 * ft_aff(k + 1, str)));
	if (str[k] == '+')
		return ((int)ft_aff(k + 1, str));
	return ((int)ft_aff(k, str));
}
