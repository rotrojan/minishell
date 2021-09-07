/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:52:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 17:01:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if (size == 0 && ptr != NULL)
	{
		new = gc_malloc(sizeof(char) * 1);
		gc_free(ptr);
		return (new);
	}
	new = gc_malloc(size);
	if (ptr != NULL)
	{
		ft_memcpy(new, ptr, size);
		gc_free(ptr);
	}
	return (new);
}
