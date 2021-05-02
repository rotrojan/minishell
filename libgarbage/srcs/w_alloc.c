/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 19:25:01 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgarbage.h"

void	*w_alloc(size_t nmemb, size_t size)
{
	t_garbage_lst	**garbage_lst;
	t_garbage_lst	*new;

	garbage_lst = get_garbage_lst();
	new = NULL;
	new = (t_garbage_lst *)malloc(sizeof(t_garbage_lst));
	if (new == NULL)
		exit_error(strerror(errno), errno);
	new->ptr = NULL;
	new->ptr = malloc(nmemb * size);
	if (new->ptr == NULL)
		exit_error(strerror(errno), errno);
	new->next = *garbage_lst;
	*garbage_lst = new;
	return (new->ptr);
}
