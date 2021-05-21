/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:46:15 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:08:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	unsigned int	i;
	char			*strnew;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nbrlen(n, 10);
	strnew = gc_malloc(sizeof(char) * (i + 1));
	strnew[i--] = '\0';
	while (n > 0)
	{
		strnew[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (strnew);
}
