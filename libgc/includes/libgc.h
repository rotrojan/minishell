/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/05 15:13:17 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_H
# define LIBGC_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_garbage_lst
{
	void					*ptr;
	struct s_garbage_lst	*next;
}							t_garbage_lst;

void			*gc_alloc(size_t nmemb, size_t size);
void			gc_free(void *garbage_to_free);
void			gc_free_all(void);
void			gc_exit(int errnum, char *message);
t_garbage_lst	**get_garbage_lst(void);

#endif
