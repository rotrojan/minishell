/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:28:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 00:41:55 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char 	*ft_append_char(char *str, char c)
{
	int		i;
	char	*str_new;

	i = 0;
	str_new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = c;
	str_new[i + 1] = '\0';
	free(str);
	return (str_new);
}

int	get_next_line(int fd, char **line)
{
	char	c;
	int		ret;
	char	*str;

	c = '\0';
	ret = 1;
	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return (-1);
	str[0] = '\0';
	while (c != '\n' && ret != 0)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
			return (-1);
		else if (c != '\n' && ret != 0)
			str = ft_append_char(str, c);
		str = ft_append_char(str, c);
		if (str == NULL)
			return (-1);
	}
	*line = str;
	if (ret != 0)
		ret = 1;
	return (ret);
}
