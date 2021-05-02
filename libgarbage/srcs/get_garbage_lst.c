/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_garbage_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:18:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 18:23:30 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgarbage.h"

t_garbage_lst	**get_garbage_lst(void)
{
	static t_garbage_lst	*garbage_lst = NULL;

	return (&garbage_lst);
}
