/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:15:45 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/03 16:07:38 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_lerp(double p, double first, double second)
{
	if (first == second)
		return (first);
	return (first + (second - first) * p);
}
