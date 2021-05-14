/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 04:53:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/13 21:59:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_create_elem(void *data);
void				ft_list_clear(t_list *begin_list);
void				ft_list_push_back(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
char				**ft_list_to_array(t_list **alst);

#endif
