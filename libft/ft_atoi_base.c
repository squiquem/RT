/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 21:50:39 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/16 16:05:48 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_blank(const char *str)
{
	int k;

	k = 0;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\v'
			|| str[k] == '\f' || str[k] == '\r' || str[k] == '\n')
		k++;
	return (k);
}

int			ft_atoi_base(const char *str, char *base)
{
	int i;
	int	j;
	int	result;

	result = 0;
	i = count_blank(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0' && str[i] != base[j])
			j++;
		if ((base[j] == '\0' && str[i] != '+' && str[i] != '-'))
			return (0);
		if (i > count_blank(str) && (str[i] == '+' || str[i] == '-'))
			return (result);
		result = result * ft_strlen(base) + j;
		i++;
	}
	if (str[count_blank(str)] == '-' && !(ft_strcmp(base, "0123456789")))
		result = -result;
	return (result);
}
