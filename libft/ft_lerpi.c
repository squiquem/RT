/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerpi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:26:37 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/03 16:07:52 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lerpi(double p, int first, int second)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}
