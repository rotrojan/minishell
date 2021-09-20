/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:15:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/15 04:26:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_list_to_array(t_list **alst)
{
	int		i;
	t_list	*lst;
	t_list	*next;
	char	**array;

	i = 0;
	lst = *alst;
	if (lst == NULL)
		return (NULL);
	array = gc_malloc(sizeof(char *) * (ft_list_size(lst) + 1));
	while (lst)
	{
		array[i] = lst->data;
		next = lst->next;
		gc_free((void **)&lst);
		lst = next;
		i++;
	}
	array[i] = NULL;
	*alst = NULL;
	return (array);
}
