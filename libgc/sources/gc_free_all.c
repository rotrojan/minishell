/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:04:42 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/05 15:08:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free_all(void)
{
	t_garbage_lst	*current;
	t_garbage_lst	*next;

	current = *get_garbage_lst();
	while (current)
	{
		next = current->next;
		gc_free(current->ptr);
		current->ptr = NULL;
		gc_free(current);
		current = NULL;
		current = next;
	}
}
