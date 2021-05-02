/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:04:32 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/03 01:06:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = w_alloc(count, size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
