/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 19:50:58 by lucocozz         ###   ########.fr       */
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
		ft_exit(EXIT_FAILURE, strerror(errno));
	new->ptr = NULL;
	new->ptr = malloc(nmemb * size);
	if (new->ptr == NULL)
		ft_exit(EXIT_FAILURE, strerror(errno));
	new->next = *garbage_lst;
	*garbage_lst = new;
	return (new->ptr);
}
