/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:30:32 by squiquem          #+#    #+#             */
/*   Updated: 2017/08/21 18:07:04 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveif(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*list;
	t_list	*last;

	tmp = NULL;
	last = NULL;
	list = *begin_list;
	while (list)
	{
		if ((*cmp)(list->content, data_ref) == 0)
		{
			if (list == *begin_list)
				*begin_list = list->next;
			else
				last->next = list->next;
			tmp = list;
			list = list->next;
			free(tmp);
		}
		else
		{
			last = list;
			list = list->next;
		}
	}
}
