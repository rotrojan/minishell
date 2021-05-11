/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:04:42 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/11 17:27:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free_all(void)
{
	t_garbage_lst	**garbage;
	t_garbage_lst	*current;
	t_garbage_lst	*next;

	garbage = get_garbage_lst();
	current = *garbage;
	while (current)
	{
		next = current->next;
		_gc_memdel((void **)&current->ptr);
		_gc_memdel((void **)&current);
		current = next;
	}
}
