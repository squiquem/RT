/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:42:21 by squiquem          #+#    #+#             */
/*   Updated: 2019/01/24 15:00:02 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	matrix_mult(t_matrix a, t_matrix b)
{
	t_matrix	c;

	c.col1.x = a.col1.x * b.col1.x + a.col2.x * b.col1.y + a.col3.x * b.col1.z;
	c.col1.y = a.col1.y * b.col1.x + a.col2.y * b.col1.y + a.col3.y * b.col1.z;
	c.col1.z = a.col1.z * b.col1.x + a.col2.z * b.col1.y + a.col3.z * b.col1.z;
	c.col2.x = a.col1.x * b.col2.x + a.col2.x * b.col2.y + a.col3.x * b.col2.z;
	c.col2.y = a.col1.y * b.col2.x + a.col2.y * b.col2.y + a.col3.y * b.col2.z;
	c.col2.z = a.col1.z * b.col2.x + a.col2.z * b.col2.y + a.col3.z * b.col2.z;
	c.col3.x = a.col1.x * b.col3.x + a.col2.x * b.col3.y + a.col3.x * b.col3.z;
	c.col3.y = a.col1.y * b.col3.x + a.col2.y * b.col3.y + a.col3.y * b.col3.z;
	c.col3.z = a.col1.z * b.col3.x + a.col2.z * b.col3.y + a.col3.z * b.col3.z;
	return (c);
}

t_matrix	matrix_transp(t_matrix a)
{
	t_matrix	b;

	b.col1.x = a.col1.x;
	b.col2.y = a.col2.y;
	b.col3.z = a.col3.z;
	b.col1.y = a.col2.x;
	b.col1.z = a.col3.x;
	b.col2.x = a.col1.y;
	b.col3.x = a.col1.z;
	b.col2.z = a.col3.y;
	b.col3.y = a.col2.z;
	return (b);
}
