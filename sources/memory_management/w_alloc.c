/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 15:24:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*w_alloc(size_t nmemb, size_t size, t_garbage_lst **garbage_lst)
{
	t_garbage_lst	*new_garbage;

	new_garbage = NULL;
	new_garbage = (t_garbage_lst *)malloc(sizeof(t_garbage_lst));
	if (new_garbage == NULL)
		ft_exit_error(strerror(errno));
	new_garbage->garbage_ptr = NULL;
	new_garbage->garbage_ptr = malloc(nmemb * size);
	if (new_garbage->garbage_ptr == NULL)
		exit_error(strerror(errno));
	new_garbage->next = *garbage_lst;
	*garbage_lst = new_garbage;
	return (new_garbage->garbage_ptr);
}
