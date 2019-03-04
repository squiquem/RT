/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:42:55 by squiquem          #+#    #+#             */
/*   Updated: 2018/09/12 16:30:03 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_size((int)ft_abs((double)n));
	if (n < 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb = (int)ft_abs((double)n);
	str[i] = '\0';
	str[i - 1] = nb % 10 + '0';
	while (nb > 9 && i >= 2)
	{
		nb = nb / 10;
		str[i - 2] = nb % 10 + '0';
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
