/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/03 02:22:21 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

typedef struct s_garbage_lst
{
	void					*ptr;
	struct s_garbage_lst	*next;
}	t_garbage_lst;

void			*w_alloc(size_t nmemb, size_t size);
void			w_free(void *garbage_to_free);
void			ft_exit(int errnum, char *message);
t_garbage_lst	**get_garbage_lst(void);

#endif
