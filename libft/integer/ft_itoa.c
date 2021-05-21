/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:13:33 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:01:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*strnew;

	i = ft_number_len(n);
	strnew = gc_malloc(sizeof(char) * (i + 1));
	strnew[i--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		strnew[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		strnew[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (strnew);
}
