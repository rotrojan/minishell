/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:12:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/13 22:17:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list *begin_list)
{
	t_list	*prev;

	while (begin_list)
	{
		gc_free(begin_list->data);
		prev = begin_list;
		begin_list = begin_list->next;
		gc_free(prev);
	}
}
