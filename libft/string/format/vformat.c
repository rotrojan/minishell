/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vformat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:53:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 22:08:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_type(char	type, va_list ap, t_fbuffer *format)
{
	int					i;
	t_fconvert const	convert[] = {
		{.type = '%', .function = &convert_percent},
		{.type = 'c', .function = &convert_c},
		{.type = 's', .function = &convert_s},
		{.type = 'd', .function = &convert_d},
		{.type = 'i', .function = &convert_i},
		{.type = 'x', .function = &convert_xl},
		{.type = 'X', .function = &convert_xu},
		{.type = 0}
	};

	i = 0;
	while (convert[i].type != type && convert[i].type != 0)
		i++;
	if (convert[i].type == 0)
		return (-1);
	convert[i].function(format, ap);
	return (0);
}

char	*vformat(const char *string, va_list ap)
{
	int					i;
	t_fbuffer			format;

	i = 0;
	format.i = 0;
	ft_bzero(format.buffer, FBUFFER_SIZE);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			if (match_type(string[++i], ap, &format) == -1)
				return (NULL);
		}
		else
			format.buffer[format.i++] = string[i];
		i++;
	}
	return (ft_strdup(format.buffer));
}
