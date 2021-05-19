/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/19 13:34:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	*gc_malloc(size_t size)
{
	t_garbage_lst	*tmp;
	t_garbage_lst	*new;
	t_garbage_lst	**garbage_lst;

	new = NULL;
	garbage_lst = get_garbage_lst();
	tmp = *garbage_lst;
	new = malloc(sizeof(t_garbage_lst));
	if (new == NULL)
		gc_exit(EXIT_FAILURE, "malloc(): failed to allocate memory.\n");
	_gc_bzero(new, sizeof(t_garbage_lst));
	new->ptr = malloc(size);
	if (new->ptr == NULL)
	{
		_gc_memdel((void **)&new);
		gc_exit(EXIT_FAILURE, "malloc(): failed to allocate memory.\n");
	}
	_gc_bzero(new->ptr, size);
	new->next = tmp;
	*garbage_lst = new;
	return (new->ptr);
}
