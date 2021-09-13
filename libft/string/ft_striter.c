/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:25:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/12 17:32:16 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_striter(char *str, int (*function)(int))
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (function(str[i++]) == 0)
			return (0);
	return (1);
}
