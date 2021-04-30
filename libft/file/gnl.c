/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:28:57 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 01:48:42 by lucocozz         ###   ########.fr       */
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
		if ((ret = read(fd, &c, 1)) == -1)
			return (-1);
		else if (c != '\n' && ret != 0)
			if ((str = ft_append_char(str, c)) == NULL)
				return (-1);
	}
	*line = str;
	return (ret == 0 ? 0 : 1);
}
