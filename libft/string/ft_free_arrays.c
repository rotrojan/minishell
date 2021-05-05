/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:07:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/03 01:10:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arrays(char **arrays)
{
	int	i;

	i = 0;
	while (arrays[i])
		gc_free(arrays[i++]);
	gc_free(arrays);
}
