/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/02 16:50:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGEMENT_H
# define MEMORY_MANAGEMENT_H
# include "minishell.h"

typedef struct s_garbage_lst
{
	void					*ptr;
	struct s_garbage_lst	*next;
}	t_garbage_lst;

void			*w_alloc(size_t nmemb, size_t size);
void			w_free(void *garbage_to_free);
void			exit_error(char *str_error);
t_garbage_lst	**get_garbage_lst(void);

#endif
