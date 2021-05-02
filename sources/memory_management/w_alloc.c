/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 17:07:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_management.h"
#include "minishell.h"

void	*w_alloc(size_t nmemb, size_t size)
{
	t_garbage_lst	**garbage_lst;
	t_garbage_lst	*new_garbage;

	garbage_lst = get_garbage_lst();
	new_garbage = NULL;
	new_garbage = (t_garbage_lst *)malloc(sizeof(t_garbage_lst));
	if (new_garbage == NULL)
		ft_exit_error(strerror(errno));
	new_garbage->ptr = NULL;
	new_garbage->ptr = malloc(nmemb * size);
	if (new_garbage->ptr == NULL)
		exit_error(strerror(errno));
	new_garbage->next = *garbage_lst;
	*garbage_lst = new_garbage;
	return (new_garbage->ptr);
}
