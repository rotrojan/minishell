/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:28:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:10:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char 	*ft_append_char(char *str, char c)
{
	int		i;
	char	*str_new;

	i = 0;
	str_new = gc_malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = c;
	str_new[i + 1] = '\0';
	gc_free(str);
	return (str_new);
}

int	get_next_line(int fd, char **line)
{
	char	c;
	int		ret;
	char	*str;

	c = '\0';
	ret = 1;
	str = gc_malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (c != '\n' && ret != 0)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
			return (-1);
		else if (c != '\n' && ret != 0)
			str = ft_append_char(str, c);
	}
	*line = str;
	return (ret);
}
