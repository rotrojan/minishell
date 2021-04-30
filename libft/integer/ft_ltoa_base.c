/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:28:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 01:41:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long n, char const *base)
{
	long	i;
	int		base_len;
	char	*strnew;

	if (n == 0)
		return (ft_strdup(&base[0]));
	base_len = ft_strlen(base);
	i = ft_nbrlen(n, base_len);
	strnew = ft_calloc(i + 1, sizeof(char));
	if (strnew == NULL)
		return (NULL);
	strnew[i--] = '\0';
	while (n > 0)
	{
		strnew[i] = base[(n % base_len)];
		n /= base_len;
		i--;
	}
	return (strnew);
}
