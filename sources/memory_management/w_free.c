/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 16:58:19 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_management.h"
#include "minishell.h"

void	w_free(void *garbage_to_free)
{
	t_garbage_lst	**garbage_lst;
	t_garbage_lst	*current_garbage;
	t_garbage_lst	*previous_garbage;

	garbage_lst = get_garbage_lst();
	current_garbage = *garbage_lst;
	previous_garbage = NULL;
	while (current_garbage->ptr != garbage_to_free)
	{
		previous_garbage = current_garbage;
		current_garbage = current_garbage->next;
	}
	free(current_garbage->ptr);
	current_garbage->ptr = NULL;
	if (previous_garbage == NULL)
		*garbage_lst = current_garbage->next;
	else
		previous_garbage->next = current_garbage->next;
	free(current_garbage->ptr);
	current_garbage->ptr = NULL;
	free(current_garbage);
	current_garbage = NULL;
}
